/*
 * Company: Holger Wurtz
 * Effect Name: MicroDexed
 * Description: Yamaha DX7
 *
 * This file was auto-generated by Aviate Audio Effect Creator for the Multiverse.
 */
#include "Aviate/EfxPrint.h"
#include "MicroDexed.h"
#include "sysPlatform/SysTimer.h"
#include "dexed.h"
#include "voices.h"
#include "banks.h"
#include "preset_piano.h"
#include "preset_organ.h"
#include "preset_strings.h"
#include "preset_synth.h"
#include "preset_brass.h"
#include "preset_winds.h"
#include "preset_bass.h"
#include "preset_percuss.h"
#include "preset_bells.h"

#include "preset_finetales.h"

using namespace Aviate;

namespace HolgerWurtz_MicroDexed {

MicroDexed::MicroDexed()
: AudioStream(NUM_INPUTS, m_inputQueueArray)
{
    // perform any necessary class initialization here
    m_dexed = new Dexed(4, AUDIO_SAMPLE_RATE_EXACT);
}

MicroDexed::~MicroDexed()
{
    // perform any necessary clean up here, though destructors are not
    // called on the hardware, only in the simulator.
    if (m_dexed) delete m_dexed;
}

void MicroDexed::m_init()
{
    AUDIO_SAMPLES_PER_BLOCK_INV = 1.0f / (float)(AUDIO_SAMPLES_PER_BLOCK-1);
    m_transposeSel = 0;
    m_categorySel = InstrumentCategory::PIANO;
    m_pianoSel     = 0;
    m_organSel     = 0;
    m_stringsSel   = 0;
    m_synthSel     = 0;
    m_brassSel     = 0;
    m_windsSel     = 0;
    m_bassSel      = 0;
    m_bellsSel     = 0;
    m_percussSel   = 0;
    m_finetalesSel = 0;

    m_bankselect = 0;
    m_voiceselect = 0;

    for (unsigned i=0; i < MAX_NOTES; i++) { m_noteArray[i].playing = false; }
    m_updateVoice();

    m_dexed->setPitchbendRange(12);
    m_dexed->setModWheelRange(99);

    m_isInit = true;
}

void MicroDexed::update(void)
{
    if (!m_enable ) { return; }
    if (!m_isInit) { m_init(); }
    
    audio_block_float32_t* output = allocateFloat();
    if (!output) { return; }
    memset(&output->data[0], 0, AUDIO_SAMPLES_PER_BLOCK* sizeof(AudioDataType));
    if (m_bypass) { transmit(output, 0); release(output); }
    m_updateInputPeak(output);

    SysPlatform::ElapsedMicros render_time;

    if (m_voiceUpdate == VoiceUpdate::ATTACKING) {
        for (unsigned i=0; i< MAX_NOTES; i++) {
            if (m_noteArray[i].playing) {
                efxLogger.printf("Restarting note:%d  velocity:%d\n", m_noteArray[i].note, m_noteArray[i].velocity);
                m_dexed->keydown(m_noteArray[i].note, m_noteArray[i].velocity);
            }
        } 
    }

    m_dexed->getSamples(output->data, AUDIO_BLOCK_SAMPLES);

    if (render_time > audio_block_time_us) // everything greater audio_block_time_us (2.9ms for buffer size of 128) is a buffer underrun!
        m_dexed->xrun++;

    if (render_time > m_dexed->render_time_max)
        m_dexed->render_time_max = render_time;

    for (unsigned idx=0; idx<AUDIO_SAMPLES_PER_BLOCK; idx++) {
        if (m_voiceUpdate == VoiceUpdate::MUTING) {
            output->data[idx] *= (m_volume * ((float)(AUDIO_SAMPLES_PER_BLOCK-1-idx) * AUDIO_SAMPLES_PER_BLOCK_INV));
        } else if (m_voiceUpdate == VoiceUpdate::ATTACKING) {            
            //output->data[idx] *= m_volume;
            output->data[idx] *= (m_volume * ((float)(idx) * AUDIO_SAMPLES_PER_BLOCK_INV));    
        } else {
            output->data[idx] *= m_volume;
        }
    }

    if (m_voiceUpdate == VoiceUpdate::MUTING) {
        m_voiceUpdate = VoiceUpdate::ATTACKING;
        m_updateVoice();
    } else if (m_voiceUpdate == VoiceUpdate::ATTACKING) { 
        m_voiceUpdate = VoiceUpdate::IDLE;    
    }

    m_updateOutputPeak(output); // you must call m_upateOutputPeak() at the end of update() before transmit
    transmit(output);
    release(output);
}

void MicroDexed::volume(float value)
{
    float volDbValue = -40.0f + (value * 50.0f);  // remap the normalized value to represent -40dB to +10dB
    volumeDb(volDbValue);  // AudioEffectFloat has built-in volume function in dB

    // Demonstrate the efxLogger.printf() function to print over the USB serial port
    // Note: efxLogger.printf() statements will have no effect in RELEASE builds
    efxLogger.printf("volume change: normalized value: %f  dB value: %f\n", value, volDbValue);
}

void MicroDexed::bankselect(float value)
{
    m_bankselect = getUserParamValue(BankSelect_e, value);
    bankSel = static_cast<unsigned>(m_bankselect)-1;
    efxLogger.printf("MicroDexed::bankselect: %u\n", bankSel);
    if (bankSel >= 0 && bankSel < NUM_BANKS) {
        m_setVoice(bankSel, voiceSel, m_transposeSel);
    }
}

void MicroDexed::voiceselect(float value)
{
    m_voiceselect = getUserParamValue(VoiceSelect_e, value);
    voiceSel = static_cast<unsigned>(m_voiceselect)-1;
    efxLogger.printf("MicroDexed::voiceselect: %u\n", voiceSel);
    if (voiceSel >= 0 && voiceSel < NUM_VOICES_PER_BANK) {
        m_setVoice(bankSel, voiceSel, m_transposeSel);
    }
}

void MicroDexed::transpose(float value)
{
    m_transpose = getUserParamValue(Transpose_e, value);
    m_transposeSel = static_cast<unsigned>(m_transpose);
    efxLogger.printf("MicroDexed::tranpose: %u\n", m_transposeSel);
    m_updateVoiceRequest();
}

// ModWheel is not working right now
// void MicroDexed::wheeltarget(float value)
// {
//     m_wheeltarget = getUserParamValue(WheelTarget_e, value);
//     unsigned wheelTarget = static_cast<unsigned>(m_wheeltarget);
//     efxLogger.printf("MicroDexed::wheeltarget() value is %u\n", wheelTarget);
//     m_dexed->setModWheelTarget(wheelTarget);
// }

void MicroDexed::m_setVoice(unsigned bank, unsigned voice, unsigned tranpose)
{
    char voice_name[11];
    uint8_t decoded_voice[156];

    memset(voice_name, 0, 11);
    memcpy(voice_name, &progmem_bank[bank][voice][118], 10);

    efxLogger.printf("MicroDexed::m_setVoice(): Voice name: %s  Bank/Voice/Trans: %u/%u/%u\n", voice_name, bank, voice, tranpose);

    m_dexed->decodeVoice(decoded_voice, (uint8_t*)progmem_bank[bank][voice]);
    m_dexed->loadVoiceParameters(decoded_voice);
    m_dexed->setTranspose(tranpose);

    // // print out all names
    // for (int i=0; i < NUM_BANKS; i++) {
    //     efxLogger.printf("\nBank %u\n", i);
    //     for (int j=0; j < NUM_VOICES_PER_BANK; j++) {
    //         char name[11];
    //         memset(name, 0, 11);
    //         memcpy(name, &progmem_bank[i][j][118], 10);
    //         //efxLogger.printf("%s,", name);
    //         efxLogger.printf("v:%u -> %s\n", j, name);
    //     }
    //     for (int j=0; j < NUM_VOICES_PER_BANK; j++) {
    //         char name[11];
    //         memset(name, 0, 11);
    //         memcpy(name, &progmem_bank[i][j][118], 10);
    //         efxLogger.printf("%s,", name);
    //         if (j % 8 == 0) efxLogger.printf("\n");
    //     }
    //     efxLogger.printf("\n");
    // }
    // efxLogger.printf("\n");
}

void MicroDexed::m_addNote(uint8_t note, uint8_t velocity) {
    int firstSlot = -1;
    for (unsigned i=0; i < MAX_NOTES; i++) {
        if ((firstSlot < 0) && !m_noteArray[i].playing) { firstSlot = i; }
        else if (m_noteArray[i].playing && (m_noteArray[i].note == note)) {
            m_noteArray[i].velocity = velocity;  // update the velocity
            return;
        }
    }

    if (firstSlot >= 0) {
        m_noteArray[firstSlot].playing  = true;
        m_noteArray[firstSlot].note     = note;
        m_noteArray[firstSlot].velocity = velocity;
    }
}

void MicroDexed::m_removeNote(uint8_t note, uint8_t velocity) {
    for (unsigned i=0; i < MAX_NOTES; i++) {
        if (m_noteArray[i].playing && (m_noteArray[i].note == note)) {
            m_noteArray[i].playing = false;
        }
    }
}

void MicroDexed::processMidi(int status, int data1, int data2) {
    uint8_t type = status & 0xF0U;
    //efxLogger.printf("MicroDexed::processMidi(): type:%02X channel:%02X  data1:%d  data2:%d\n", type, status & 0x0FU, data1, data2);

    uint8_t note = data1;
    uint8_t velocity = data2;

    if (type == 0x90U) {  // note on
        m_dexed->keydown(note, velocity);
        m_addNote(note, velocity);
    }
    else if (type == 0x80U) {  // note off
        m_dexed->keyup(note);
        m_removeNote(note, velocity);
    }
    else if (type == 0xE0U) {  // pitch bend
        efxLogger.printf("Set pitch bend to %d %d\n", note, velocity);
        m_dexed->setPitchbend(note, velocity);
    }
    else if (type == 0xB0U) { // CC
        switch(data1) {
        case 1 : m_dexed->setModWheel(data2); efxLogger.printf("MOD Wheel:%d\n", data2); break;
        case 64 :
        {            
            bool sustain = (data2 >= 64);
            m_dexed->setSustain(sustain);
            break;
        }
        default: break;
        }
    }
}

void MicroDexed::m_updateVoiceRequest()
{
    //m_dexed->notesOff();
    m_voiceUpdate = VoiceUpdate::MUTING;
}

void MicroDexed::m_updateVoice()
{
    // for (unsigned i=0; i< MAX_NOTES; i++) {
    //     if (m_noteArray[i].playing) {
    //         efxLogger.printf("Clearing note:%d  velocity:%d\n", m_noteArray[i].note, m_noteArray[i].velocity);
    //         m_dexed->keyup(m_noteArray[i].note);
    //     }
    // }

    uint8_t decoded_voice[156];
    switch(m_categorySel) {
    case InstrumentCategory::PIANO :
        efxLogger.printf("MicroDexed::m_updateVoice(): PIANO set to voice %u, transpose %u\n", m_pianoSel, m_transposeSel);
        m_dexed->decodeVoice(decoded_voice, (uint8_t*)piano_bank[m_pianoSel]); break;
    case InstrumentCategory::ORGAN :
        efxLogger.printf("MicroDexed::m_updateVoice(): ORGAN set to voice %u, transpose %u\n", m_organSel, m_transposeSel);
        m_dexed->decodeVoice(decoded_voice, (uint8_t*)organ_bank[m_organSel]);break;
    case InstrumentCategory::STRINGS :
        efxLogger.printf("MicroDexed::m_updateVoice(): STRINGS set to voice %u, transpose %u\n", m_stringsSel, m_transposeSel);
        m_dexed->decodeVoice(decoded_voice, (uint8_t*)strings_bank[m_stringsSel]);break;
    case InstrumentCategory::SYNTH :
        efxLogger.printf("MicroDexed::m_updateVoice(): SYNTH set to voice %u, transpose %u\n", m_synthSel, m_transposeSel);
        m_dexed->decodeVoice(decoded_voice, (uint8_t*)synth_bank[m_synthSel]);break;
    case InstrumentCategory::BRASS :
        efxLogger.printf("MicroDexed::m_updateVoice(): BRASS set to voice %u, transpose %u\n", m_brassSel, m_transposeSel);
        m_dexed->decodeVoice(decoded_voice, (uint8_t*)brass_bank[m_brassSel]);break;
    case InstrumentCategory::WINDS :
        efxLogger.printf("MicroDexed::m_updateVoice(): WINDS set to voice %u, transpose %u\n", m_windsSel, m_transposeSel);
        m_dexed->decodeVoice(decoded_voice, (uint8_t*)winds_bank[m_windsSel]);break;
    case InstrumentCategory::BASS :
        efxLogger.printf("MicroDexed::m_updateVoice(): BASS set to voice %u, transpose %u\n", m_bassSel, m_transposeSel);
        m_dexed->decodeVoice(decoded_voice, (uint8_t*)bass_bank[m_bassSel]);break;
    case InstrumentCategory::BELLS :
        efxLogger.printf("MicroDexed::m_updateVoice(): BELLS set to voice %u, transpose %u\n", m_bellsSel, m_transposeSel);
        m_dexed->decodeVoice(decoded_voice, (uint8_t*)bells_bank[m_bellsSel]);break;
    case InstrumentCategory::PERCUSS :
        efxLogger.printf("MicroDexed::m_updateVoice(): PERCUSS set to voice %u, transpose %u\n", m_percussSel, m_transposeSel);
        m_dexed->decodeVoice(decoded_voice, (uint8_t*)percuss_bank[m_percussSel]);break;
    case InstrumentCategory::FINETALES :
        efxLogger.printf("MicroDexed::m_updateVoice(): FINETALES set to voice %u, transpose %u\n", m_finetalesSel, m_transposeSel);
        m_dexed->decodeVoice(decoded_voice, (uint8_t*)finetales3_bank[m_finetalesSel]);break;
    default : return;;
    }

    m_dexed->loadVoiceParameters(decoded_voice);
    m_dexed->setTranspose(m_transposeSel);

    // for (unsigned i=0; i< MAX_NOTES; i++) {
    //     if (m_noteArray[i].playing) {
    //         efxLogger.printf("Restarting note:%d  velocity:%d\n", m_noteArray[i].note, m_noteArray[i].velocity);
    //         m_dexed->keydown(m_noteArray[i].note, m_noteArray[i].velocity);
    //     }
    // }
}

void MicroDexed::category(float value)
{
    m_category = getUserParamValue(Category_e, value);
    m_categorySel = static_cast<InstrumentCategory>(m_category);
    efxLogger.printf("MicroDexed::category select: %u\n", m_categorySel);
    m_updateVoiceRequest();
}

void MicroDexed::m_setInstrument(InstrumentCategory category, unsigned instEnum, float& var, float value, unsigned& sel, 
                                 unsigned numVoices, const char* name)
{
    var = getUserParamValue(instEnum, value);
    sel = static_cast<unsigned>(var);
    efxLogger.printf("MicroDexed::%s select: %u\n", name, sel);
    if (sel < 0) { sel = 0; }
    if (sel >= numVoices) { sel = numVoices-1; }
    if (m_categorySel == category) { m_updateVoiceRequest(); }
}

void MicroDexed::piano(float value)
{
    m_setInstrument(InstrumentCategory::PIANO, Piano_e, m_piano, value, m_pianoSel, NUM_PIANO_VOICES, "piano");
}

void MicroDexed::organ(float value)
{
    m_setInstrument(InstrumentCategory::ORGAN, Organ_e, m_organ, value, m_organSel, NUM_ORGAN_VOICES, "organ");
}

void MicroDexed::strings(float value)
{
    m_setInstrument(InstrumentCategory::STRINGS, Strings_e, m_strings, value, m_stringsSel, NUM_STRINGS_VOICES, "strings");
}
void MicroDexed::synth(float value)
{
    m_setInstrument(InstrumentCategory::SYNTH, Synth_e, m_synth, value, m_synthSel, NUM_SYNTH_VOICES, "synth");
}
void MicroDexed::brass(float value)
{
    m_setInstrument(InstrumentCategory::BRASS, Brass_e, m_brass, value, m_brassSel, NUM_BRASS_VOICES, "brass");
}
void MicroDexed::winds(float value)
{
    m_setInstrument(InstrumentCategory::WINDS, Winds_e, m_winds, value, m_windsSel, NUM_WINDS_VOICES, "winds");
}
void MicroDexed::bass(float value)
{
    m_setInstrument(InstrumentCategory::BASS, Bass_e, m_bass, value, m_bassSel, NUM_BASS_VOICES, "bass");
}
void MicroDexed::bells(float value)
{
    m_setInstrument(InstrumentCategory::BELLS, Bells_e, m_bells, value, m_bellsSel, NUM_BELLS_VOICES, "bells");
}
void MicroDexed::percussion(float value)
{
    m_setInstrument(InstrumentCategory::PERCUSS, Percussion_e, m_percussion, value, m_percussSel, NUM_PERCUSS_VOICES, "percussion");
}
void MicroDexed::finetales(float value)
{
    m_setInstrument(InstrumentCategory::FINETALES, FineTales_e, m_finetales, value, m_finetalesSel, NUM_FINETALES_VOICES, "finetales");
}
// void MicroDexed::finetales(float value)
// {
//     m_finetalesSel = getUserParamValue(FineTales_e, value);
//     m_finetalesSel = static_cast<unsigned>(m_finetalesSel);
//     efxLogger.printf("MicroDexed::finetales select: %u\n", m_finetalesSel);
//     if (m_finetalesSel < 0) { m_finetalesSel = 0; }
//     if (m_finetalesSel >= NUM_FINETALES_VOICES) { m_finetalesSel = NUM_FINETALES_VOICES-1; }
//     if (m_categorySel == InstrumentCategory::FINETALES) { m_updateVoiceRequest(); }
// }

///////////////
// COMPRESSOR
///////////////
// void MicroDexed::compressorenable(float value)
// {
//     m_compressorenable = value;
//     bool enable = static_cast<bool>(m_compressorenable);
//     m_dexed->setCompressor(enable);
//     efxLogger.printf("MicroDexed::compressor enable: %u\n", enable);
// }

// // pregain in dB
// void MicroDexed::compressorpregain(float value)
// {
//     m_compressorpregain = getUserParamValue(CompressorPregain_e, value);
//     m_dexed->setCompressorPreGain_dB(m_compressorpregain);
//     efxLogger.printf("MicroDexed::compressor pregain (dB): %f\n", m_compressorpregain);
// }

// void MicroDexed::compressorattack(float value)
// {
//     m_compressorattack = getUserParamValue(CompressorAttack_e, value);
//     m_dexed->setCompressorAttack_sec(m_compressorattack / 1000.0f);
//     efxLogger.printf("MicroDexed::compressor attack (msec): %f\n", m_compressorattack);
// }

}
