/*
 * Company: Holger Wurtz
 * Effect Name: MicroDexed
 * Description: Yamaha DX7
 *
 * This file was auto-generated by Aviate Audio Effect Creator for the Multiverse.
 */
#include <cmath>
#include "Aviate/LibBasicFunctions.h"
#include "MicroDexed.h"

using namespace Aviate;

namespace HolgerWurtz_MicroDexed {

void MicroDexed::mapMidiControl(int parameter, int midiCC, int midiChannel)
{
    if (parameter >= NUM_CONTROLS) {
        return ; // Invalid midi parameter
    }
    m_midiConfig[parameter][MIDI_CHANNEL] = midiChannel;
    m_midiConfig[parameter][MIDI_CONTROL] = midiCC;
}

void MicroDexed::setParam(int paramIndex, float paramValue)
{
    switch(paramIndex) {
    case 0 : bypass( (paramValue - 0.000000) / (1.000000 - 0.000000) ); break;
    case 1 : volume( (paramValue - 0.000000) / (10.000000 - 0.000000) ); break;
    case 2 : transpose( (paramValue - 0.000000) / (35.000000 - 0.000000) ); break;
    case 3 : category( (paramValue - 0.000000) / (9.000000 - 0.000000) ); break;
    case 4 : piano( (paramValue - 0.000000) / (20.000000 - 0.000000) ); break;
    case 5 : organ( (paramValue - 0.000000) / (9.000000 - 0.000000) ); break;
    case 6 : compressorenable( (paramValue - 0.000000) / (1.000000 - 0.000000) ); break;
    case 7 : compressorpregain( (paramValue - 0.000000) / (12.000000 - 0.000000) ); break;
    case 8 : compressorattack( (paramValue - 0.000000) / (500.000000 - 0.000000) ); break;
    default : break;
    }
}

float MicroDexed::getUserParamValue(int paramIndex, float normalizedParamValue)
{
    switch(paramIndex) {
    case 0 : return ( ((1.000000 - 0.000000) * normalizedParamValue) + 0.000000 ); // bypass
    case 1 : return ( ((10.000000 - 0.000000) * normalizedParamValue) + 0.000000 ); // volume
    case 2 : return ( ((35.000000 - 0.000000) * normalizedParamValue) + 0.000000 ); // transpose
    case 3 : return ( ((9.000000 - 0.000000) * normalizedParamValue) + 0.000000 ); // category
    case 4 : return ( ((20.000000 - 0.000000) * normalizedParamValue) + 0.000000 ); // piano
    case 5 : return ( ((9.000000 - 0.000000) * normalizedParamValue) + 0.000000 ); // organ
    case 6 : return ( ((1.000000 - 0.000000) * normalizedParamValue) + 0.000000 ); // compressorenable
    case 7 : return ( ((12.000000 - 0.000000) * normalizedParamValue) + 0.000000 ); // compressorpregain
    case 8 : return ( ((500.000000 - 0.000000) * normalizedParamValue) + 0.000000 ); // compressorattack
    default : return 0.0f;
    }
}


audio_block_float32_t* MicroDexed::m_basicInputCheck(audio_block_float32_t* inputAudioBlock, unsigned outputChannel)
{
    // Check if effect is disabled
    if (m_enable == false) {
        // do not transmit or process any audio, return as quickly as possible after releasing the inputs
        if (inputAudioBlock) { release(inputAudioBlock); }
        return nullptr; // disabled, no further EFX processing in update()
    }  // end of enable check

    // check if effect is in bypass
    if (m_bypass == true) {
        // drive input directly to the specified output. ie. bypass
        if (inputAudioBlock != nullptr) {
            // valid input, drive to outputChannel if specified
            if (outputChannel >= 0) {
                transmit(inputAudioBlock, outputChannel); // drive to specified output
            }
            release(inputAudioBlock); // release the input block as we are done with it
        } else { // invalid input block, allocate a block and drive silence if specified
            if (outputChannel >= 0) {
                audio_block_float32_t* silenceBlock = allocateFloat();
                if (silenceBlock) {
                    clearAudioBlock(silenceBlock);  // create silence in the buffer
                    transmit(silenceBlock, outputChannel);
                    release(silenceBlock);
                }
            }
        }
        return nullptr;  // bypassed, no further EFX processing in update()
    }  // end of bypass check

    // If not disabled or bypassed, create silence if the input block is invalid then
    // return the valid audio block so update() can continue.
    if (inputAudioBlock == nullptr) {
        inputAudioBlock = allocateFloat();
        if (inputAudioBlock == nullptr) { return nullptr; } // check if allocate was unsuccessful
        // else
        clearAudioBlock(inputAudioBlock);
    }
    return inputAudioBlock; // inputAudioBLock is valid and ready for update() processing
}

const uint8_t rblk[256] = { 0xf2, 0xfe, 0xee, 0x04, 0xae, 0x1c, 0x60, 0x25, 0x38, 0xb4, 0x5d, 0x52, 0x73, 0xa3, 0xbc, 0xfd, 0x95, 0xbe, 0xe8, 0x8a, 0xec, 0x93, 0xb6, 0x48, 0x4f, 0x83, 0x38, 0xbb, 0x7b, 0x69, 0x3f, 0xd3, 0xf6, 0x51, 0x1e, 0x46, 0x28, 0xe2, 0x45, 0x43, 0xd8, 0x30, 0x80, 0x40, 0x5d, 0x42, 0xbe, 0xae, 0x05, 0x93, 0xf4, 0x2a, 0x28, 0x04, 0xc0, 0x8c, 0xa1, 0xc7, 0xfb, 0x50, 0xc4, 0xb5, 0x13, 0x01, 0x50, 0x6c, 0x33, 0x79, 0x10, 0x89, 0x12, 0xe5, 0xe6, 0xba, 0x9f, 0xd5, 0x90, 0xe0, 0xc1, 0x7b, 0xc6, 0x17, 0x32, 0xcc, 0xe3, 0xc1, 0x36, 0x2c, 0x30, 0x16, 0x3f, 0xd1, 0x82, 0xd9, 0xcb, 0x44, 0x01, 0xf9, 0x05, 0xdc, 0x18, 0x36, 0x2e, 0x58, 0x6c, 0x9b, 0xf1, 0x0b, 0xf4, 0x02, 0x69, 0x12, 0xa3, 0x44, 0xa3, 0xd4, 0x96, 0x36, 0x27, 0xf6, 0x44, 0x56, 0x87, 0x56, 0x46, 0x00, 0x79, 0x07, 0x6e, 0xf3, 0x01, 0x02, 0x93, 0x9b, 0x18, 0x08, 0x39, 0xba, 0xe5, 0x35, 0xe7, 0x7b, 0xef, 0x9e, 0x67, 0x49, 0xe3, 0xb5, 0x16, 0x88, 0xa6, 0x81, 0xa4, 0xda, 0x24, 0x9e, 0xba, 0x9e, 0xa5, 0x29, 0x91, 0xa6, 0x2b, 0x24, 0x42, 0x43, 0x2c, 0x7b, 0xfd, 0x11, 0xb0, 0xe4, 0x8d, 0x9f, 0x82, 0xf4, 0xe9, 0x66, 0xa9, 0xff, 0xee, 0x4f, 0x80, 0x92, 0x2a, 0xa4, 0x31, 0xe4, 0x42, 0xd6, 0x0d, 0xd3, 0x7d, 0x38, 0xf7, 0xbf, 0x7b, 0x23, 0x3a, 0x78, 0x35, 0xea, 0x5c, 0xc2, 0x89, 0xdf, 0xb6, 0x72, 0x45, 0x5f, 0x71, 0x33, 0xae, 0xf1, 0xc5, 0xd8, 0x96, 0xf6, 0xbd, 0xd8, 0xcd, 0xca, 0xac, 0x4a, 0x03, 0xa3, 0x09, 0x7e, 0xc7, 0x43, 0xf7, 0xfc, 0x2d, 0x53, 0xbe, 0xb6, 0x32, 0x74, 0x29, 0x77, 0xd3, 0x9a, 0xaa, 0x81, 0x8c, 0x70, 0x5a, 0x22, 0x66, 0x17, 0xfa, 0x33, 0xe1, 0xa6, 0x7d, 0xe4};
const uint8_t* MicroDexed::getRblk() { return rblk; }
static constexpr char PROGMEM MicroDexed_name[] = {0x48, 0x6f, 0x6c, 0x67, 0x65, 0x72, 0x20, 0x57, 0x75, 0x72, 0x74, 0x7a, 0x3a, 0x44, 0x3a, 0x4d, 0x69, 0x63, 0x72, 0x6f, 0x44, 0x65, 0x78, 0x65, 0x64, 0x0};
const char* MicroDexed::getName() { return MicroDexed_name; }

}
