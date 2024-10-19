#ifndef MicroDexed_preset_synth_h_
#define MicroDexed_preset_synth_h_

#ifndef NUM_VALUES_PER_VOICE
#define NUM_VALUES_PER_VOICE 128
#endif
#ifndef MAX_NUM_TRANSPOSE
#define MAX_NUM_TRANSPOSE 36
#endif

#define NUM_SYNTH_VOICES 30
constexpr uint8_t synth_bank[NUM_SYNTH_VOICES][NUM_VALUES_PER_VOICE] PROGMEM =
{
    {	// 0: Korg CX3
            99,  99,  99,  99,  99,  99,  99,   0,
            63,  20,   0,   0,  56,   0,  88,  57,
            30,  99,  99,  99,  99,  99,  99,  99,
            0,  63,   0,  30,   0,  72,   0,  99,
            6,   0,  99,  99,  99,  99,  99,  99,
            99,   0,  63,   0,  30,   0,  56,   0,
            99,   4,   0,  99,  99,  60,  99,  99,
            99,  80,   0,  63,   0,  30,   0,  57,
            0,  99,  12,   0,  99,  99,  99,  99,
            99,  99,  99,   0,  63,   0,  30,   0,
            40,   0,  99,   6,   0,  99,  99,  99,
            99,  99,  99,  99,   0,  63,   0,  30,
            0,  56,   0,  99,   2,   0,  99,  99,
            99,  99,  50,  50,  50,  50,  23,   8,
            35,   0,   0,   0,  49,  24,  75, 111,
        114, 103,  32,  67,  88,  51,  32,  32
    },
    {	// 1: Synclavier
            81,  25,  25,  14,  99,  99,   0,   0,
            29,   0,   0,   3,  85,   0,  99,   6,
            1,  99,   0,  25,   0,  99,  75,   0,
            0,  28,   0,  16,   0,  69,   4,  68,
            2,   0,  81,  25,  20,  48,  99,  82,
            0,   0,   0,  85,   0,   3,  64,   4,
            99,   2,   1,  81,  25,  25,  14,  99,
            99,   0,   0,  29,   0,   1,   3,  93,
            0,  99,   6,   0,  99,   0,  25,   0,
            99,  75,   0,   0,  28,   0,  16,   0,
            45,   4,  68,   2,   0,  81,  25,  20,
            48,  99,  82,   0,   0,   0,  85,   0,
            3,  48,   4,  99,   2,   0,  99,  75,
            95,  60,  50,  50,  50,  50,   2,   8,
            42,  20,   3,   0,  64,  12,  83, 121,
        110,  99, 108,  97, 118, 105, 101, 114
    },
    {	// 2: FATSO. RT.
            99,  99,  53,  60,  95,  95,  95,  61,
            0,   0,   3,   0,  24,   0,  71,   2,
            0,  99,  99,  53,  60,  95,  95,  95,
            61,   0,   0,   3,   0,  24,   0,  71,
            2,   0,  99,  99,  39,  60,  99,  99,
            61,  61,   0,   0,   3,   0,  24,   0,
            90,   2,   0,  99,  99,  99,  49,  99,
            99,  99,   0,   0,   0,   0,   0,   0,
            0,  91,   2,   0,  99,  99,  39,  90,
            99,  99,  90,  90,   0,   0,   3,   0,
            88,   0,  89,   2,   0,  99,  99,  99,
            89,  99,  99,  99,   0,   0,   0,   0,
            0,  88,   0,  99,   2,   0,  99,  99,
            99,  99,  50,  50,  50,  50,   1,  14,
            45,   0,   0,   0,  48,  12,  70,  65,
            84,  83,  79,  46,  32,  82,  84,  46
    },
    {	// 3: JUPITER 8
            64,  27,  16,  31,  90,  99,  94,   0,
            0,   0,  17,   0,   0,   0,  99,   4,
            0,  64,  27,  16,  43,  90,  99,  95,
            0,   0,   0,   0,   0, 112,   0,  65,
            0,   0,  64,  27,  16,  39,  90,  99,
            94,   0,   0,   0,   0,   0,   8,   0,
            82,   0,   0,  64,  40,  23,  46,  99,
            97,  94,   0,   0,   0,   0,   0,  80,
            0,  99,   0,   0,  50,  26,   9,  36,
            94,  99,  94,   0,  24,   0,   5,   0,
            112,   4,  83,   0,   0,  65,  99,  99,
            44,  99,  99,  99,   0,   0,   0,   0,
            0, 104,   0,  99,   0,   0,  99,  99,
            99,  99,  50,  50,  50,  50,   8,  15,
            23,   0,  11,   0,  33,  24,  74,  85,
            80,  73,  84,  69,  82,  32,  56,  32
    },
    {	// 4: Mini-Moog
            99,  99,  99,  70,  99,  99,  99,   0,
            39,   0,   0,   0,  40,   0,  70,   2,
            0,  67,  44,  30,  70,  99,  97,  94,
            0,  39,   0,   0,   0,  32,   0,  78,
            2,   0,  81,  99,  99,  70,  99,  99,
            99,   0,  39,   0,   0,   0,  40,   0,
            94,   2,   0,  69,  99,  99,  70,  99,
            99,  99,   0,  39,   0,   0,   0,  80,
            16,  89,   2,   0,  65,  99,  99,  70,
            99,  99,  99,   0,  39,   0,   0,   0,
            56,   0,  75,   1,   0,  85,  99,  99,
            70,  99,  99,  99,   0,  39,   0,   0,
            0,  72,   0,  95,   2,   0,  99,  99,
            99,  99,  50,  50,  50,  50,   3,   4,
            40,   0,   5,   0,  64,  24,  77, 105,
        110, 105,  45,  77, 111, 111, 103,  32
    },
    {	// 5: St Pad  4c
            73,  70,  30,  30,  99,  94,  96,   0,
            0,   0,  20,   0,  40,   0,  73,  16,
            0,  72,  70,  30,  30,  99,  94,  96,
            0,   0,   0,  20,   0, 112,   0,  66,
            4,   0,  51,  99,  99,  32,  99,  99,
            99,   0,  99,   0,   0,   0,  32,   0,
            65,   4,   0,  50,   7,  10,  47,  99,
            90,  90,   0,  99,   0,   0,   0,  72,
            3,  98,   4,   0,  85,  10,  10,  20,
            99,  95,  97,   0,   0,   0,   0,   0,
            24,   8,  80,   4,   0,  55,  56,  10,
            43,  59,  98,  99,   0,   0,   0,   0,
            0,  56,   3,  92,   4,   0,  10,   5,
            6,   6,  50,  50,  50,  50,  11,  15,
            30,  60,  10,   0,  40,  12,  83, 116,
            32,  80,  97, 100,  32,  32,  52,  99
    },
    {	// 6: HORNS 5A W
            53,  15,  25,  53,  85,  87,  88,   0,
            54,   0,   0,   0,  73,   0,  99,   2,
            0,  53,  15,  23,  53,  80,  82,  80,
            0,  54,   0,   0,   0,  57,   0,  70,
            2,   0,  53,  13,  60,  53,  98,  80,
            85,   0,  54,   0,   0,   0,  41,   8,
            86,   2,   0,  62,  70,  20,  54,  99,
            92,  84,   0,   0,   0,   0,   0,  90,
            0,  98,   2,   0,  53,  46,  20,  53,
            98,  96,  93,   0,  54,   0,   0,   0,
            1,  10,  84,   2,   0,  62,  70,  20,
            54,  99,  97,  95,   0,   0,   0,   0,
            0,  58,   4,  99,   2,   0,  94,  67,
            95,  60,  50,  50,  50,  50,   1,  15,
            37,   0,   0,   0,  40,  12,  72,  79,
            82,  78,  83,  32,  53,  65,  32,  87
    },
    {	// 7: 80 F
            99,  39,  32,  71,  99,  98,  88,   0,
            51,   0,   0,  15,  56,   0,  80,   0,
            0,  99,  39,  32,  71,  99,  98,  81,
            0,  39,   0,   0,  15,  64,   0,  99,
            0,   0,  99,  39,  32,  71,  99,  98,
            81,   0,  39,   0,   0,  15,  40,   0,
            99,   0,   0,  99,  39,  32,  71,  99,
            98,  81,   0,  39,   0,   0,  15,  32,
            0,  99,   0,   0,  99,  39,  32,  71,
            99,  98,  80,   0,  51,   0,  38,  15,
        112,   0,  84,   0,   0,  99,  39,  32,
            71,  99,  98,  80,   0,  51,   0,  38,
            15, 112,  28,  99,   0,   0,  84,  95,
            95,  60,  50,  50,  50,  50,  21,  15,
            37,   0,   0,   0,  72,  24,  56,  48,
            32,  70,  32,  32,  32,  32,  32,  32
    },
    {	// 8: FUNK-RHYT.
            61,  36,  18,  32,  99,  80,  72,   0,
            46,   0,  14,   3, 112,   0,  75,   4,
            0,  99,  33,  18,  71,  99,  75,  68,
            0,  46,   0,  17,   3, 112,   4,  82,
            2,   0,  99,  76,  99,  99,  99,  88,
            96,   0,  46,   0,   5,   3, 112,   0,
            94,   2,   0,  99,  28,  18,  35,  99,
            80,  70,   0,  46,   0,  10,   3,  56,
            8,  93,   2,   0,  61,  33,  17,  47,
            99,  75,  72,   0,  46,   0,  13,   3,
            56,   0,  76,   2,   0,  99,  76,  99,
            99,  99,  88,  96,   0,  46,   0,   5,
            3,  56,   0,  94,   4,   0,  84,  95,
            95,  60,  50,  50,  50,  50,   2,  15,
            37,   0,   3,   0,  48,  12,  70,  85,
            78,  75,  45,  82,  72,  89,  84,  46
    },
    {	// 9: KLA5 HS
            99,  39,  32,  71,  99,  98,  70,   0,
            39,   0,  59,   3,  80,   0,   0,   0,
            0,  99,  39,  32,  71,  99,  98,  70,
            0,  39,   0,   0,  15,  56,   0,  76,
            2,  50,  99,  39,  32,  71,  99,  98,
            70,   0,  39,   0,   0,   3, 104,   0,
            50,   0,   0,  99,  39,  32,  71,  99,
            98,  70,   0,  39,   0,   0,  15,  96,
            0,  99,   0,   0,  99,  39,  32,  46,
            99,  98,  70,   0,  39,   0,   0,  15,
        112,   4,  82,   0,   0,  99,  25,  25,
            61,  99,  98,  70,   0,  39,   0,   0,
            15, 112,   0,  99,   2,   0,  84,  95,
            95,  60,  50,  50,  50,  50,  11,  15,
            23,   0,   0,   0,  16,  24,  75,  76,
            65,  53,  32,  72,  83,  32,  32,  32
    },
    {	// 10: SYNTH R.T.
            77,  46,  29,  41,  86,  99,  95,   0,
            35,   0,   3,   0, 113,   4,  83,   2,
            0,  74,  99,  99,  55,  99,  99,  99,
            0,   0,   0,   0,   0, 112,   8,  99,
            2,   0,  74,  99,  99,  55,  99,  99,
            99,   0,   0,   0,   0,   0,  56,   8,
            99,   0,   0,  62,  41,  44,  39,  90,
            99,  96,   0,  40,   0,   0,   0,   0,
            0,  75,   0,   0,  75,  99,  99,  55,
            99,  99,  99,   0,  20,   0,  10,   0,
            0,   8,  99,   0,   0,  68,  99,  99,
            55,  99,  99,  99,   0,  20,   0,  20,
            0,   0,   0,  99,   0,   0,  99,  99,
            99,  99,  50,  50,  50,  50,  22,  15,
            35,   0,  10,   0,  49,  24,  83,  89,
            78,  84,  72,  32,  82,  46,  84,  46
    },
    {	// 11: LAAZCHRD1
            50,  13,  60,  38,  98,  80,  85,   0,
            54,   0,   0,   0,   9,   0,  92,   2,
            0,  99,  13,  60,  36,  82,  80,  85,
            0,  54,   0,   0,   0,  57,   0,  55,
            10,   0,  85,  13,  60,  37,  71,  80,
            85,   0,  15,   0,   0,   0,  41,   4,
            84,   2,   0,  42,  70,  20,  41,  34,
            92,  84,   0,   0,   0,   0,   0,  50,
            0,  95,   2,   0,  99,  46,  60,  37,
            97,  95,  95,   0,  54,   0,   0,   0,
            1,   4,  83,   2,   0,  99,  70,  20,
            37,  99,  97,  95,   0,  51,  72,   0,
            3,   2,   4,  99,   1,   0,  94,  67,
            95,  60,  50,  50,  50,  50,  14,   7,
            38,  33,  12,  71,   8,  12,  76,  65,
            65,  90,  67,  72,  82,  68,  49,  32
    },
    {	// 12: BRASS   2
            99,  39,  32,  71,  99,  98,  88,   0,
            51,   0,   0,  15,  56,   0,  80,   0,
            0,  99,  39,  32,  71,  99,  98,  81,
            0,  39,   0,   0,  15,  64,   0,  99,
            0,   0,  99,  39,  32,  71,  99,  98,
            81,   0,  39,   0,   0,  15,  40,   0,
            99,   0,   0,  99,  39,  32,  71,  99,
            98,  81,   0,  39,   0,   0,  15,  32,
            0,  99,   0,   0,  99,  39,  32,  71,
            99,  98,  80,   0,  51,   0,  38,  15,
            112,   0,  84,   0,   0,  99,  39,  32,
            71,  99,  98,  80,   0,  51,   0,  38,
            15, 112,   0,  99,   0,   0,  84,  95,
            95,  60,  50,  50,  50,  50,  21,  15,
            37,   0,   0,   0,  56,  24,  66,  82,
            65,  83,  83,  32,  32,  32,  50,  32
    },
    {	// 13: ORCHESTRA
            72,  76,  10,  32,  99,  92,   0,   0,
            0,   0,   0,   0,  56,   0,  82,   4,
            0,  76,  73,  10,  55,  99,  92,   0,
            0,   0,   0,   0,   0,  56,   0,  80,
            4,   0,  56,  74,  10,  45,  98,  98,
            36,   0,  98,   0,   0,   0,  56,   0,
            72,   4,   0,  54,  15,  10,  47,  99,
            92,   0,   0,   0,   0,   0,   0, 104,
            0,  96,   4,   0,  53,  46,  32,  61,
            99,  93,  90,   0,   0,   0,   0,   0,
            8,   0,  83,   2,   0,  80,  56,  10,
            45,  98,  98,  36,   0,  98,   0,   0,
            0,  56,   0,  99,   2,   0,  84,  95,
            95,  60,  50,  50,  50,  50,   1,  15,
            30,  63,   6,   0,  56,  12,  79,  82,
            67,  72,  69,  83,  84,  82,  65,  32
    },
    {	// 14: SYN-LEAD 1
            99,  70,  60,   0,  99,  99,  97,   0,
            32,   0,  21,   0,  59,   0,  47,  34,
            0,  99,  99,  97,   0,  99,  65,  60,
            0,  32,   0,   0,   0,  41,   0,  43,
            6,   0,  99,  92,  28,  60,  99,  90,
            0,   0,  48,   0,  60,   0,  78,   0,
            71,   4,   0,  99,  87,   0,   0,  93,
            90,   0,   0,  32,   0,  21,   0,  59,
            0,  82,   2,   0,  99,  95,   0,   0,
            99,  96,  89,   0,  32,   0,   0,   0,
            51,   0,  71,   2,   0,  99,   0,  12,
            70,  99,  95,  95,   0,  32,   0,   0,
            0,  65,   0,  99,   2,   0,   0,   0,
            0,   0,  50,  50,  50,  50,  17,   7,
            37,  42,   0,  99,  72,  36,  83,  89,
            78,  45,  76,  69,  65,  68,  32,  49
    },
    {	// 15: KOTO
            82,  53,  37,  48,  99,  81,   0,   0,
            0,   0,   5,   0,  62,   4,  81,   6,
            0,  91,  37,  29,  29,  99,  90,   0,
            0,   0,   0,   5,   0,  62,   4,  83,
            8,   0,  90,  28,  17,  39,  99,  76,
            0,   0,  10,   0,  17,   4,  62,   4,
            82,   2,   0,  94,  64,  30,  33,  99,
            92,   0,   0,   0,   0,   0,   0,  61,
            12,  99,   2,   0,  99,  68,  28,  48,
            99,  83,   0,   0,   0,   0,  10,   0,
            62,   0,  99,   8,   0,  94,  62,  58,
            34,  99,  92,   0,   0,   0,   0,   0,
            0,  62,  12,  90,   2,   0,  85,  99,
            75,   0,  49,  50,  50,  50,   1,  15,
            30,  40,  17,  15,  41,  24,  75,  79,
            84,  79,  32,  32,  32,  32,  32,  32
    },
    {	// 16: CLAV    3
            93,   5,  17,  30,  76,  51,   0,   0,
            10,  32,   0,   4,  82,   4,  67,  24,
            0,  99,  42,  15,  99,  99,  61,   0,
            0,  10,   0,   0,   4,  56,   8,  91,
            0,   0,  95,  99,  23,  84,  99,  99,
            0,   0,   0,   0,   0,   4,  63,  12,
            99,   4,   0,  95,  17,  17,  66,  99,
            95,   0,   0,  38,  98,  98,   6,  56,
            16,  77,   6,   0,  99,  39,  21,  30,
            99,  85,   0,   0,   0,   0,   0,   4,
            112,   8,  93,   0,   0,  80,  32,  18,
            66,  99,  95,   0,   0,   0,   0,   0,
            0,  60,  12,  99,   0,   0,  99,  98,
            75,  60,  50,  50,  50,  50,   3,   0,
            35,  30,   0,   0,  32,  24,  67,  76,
            65,  86,  32,  32,  32,  32,  51,  32
    },
    {	// 17: ACCORDION
            98,  15,  10,  50,  90,  92,  68,   0,
            0,   0,   0,   0,  64,   0,  69,  12,
            0,  63,  15,  10,  46,  99,  92,  68,
            0,  39,   0,   0,  13,  48,   0,  75,
            2,   0,  55,  15,  10,  69,  99,  92,
            99,   0,   0,   0,   0,   0,  56,   0,
            90,   4,   0,  87,  15,  10,  46,  99,
            92,  71,   0,   0,   0,   0,   0,  72,
            0,  56,   6,   0,  91,  15,  10,  70,
            99,  92,  71,   0,   0,   0,   0,   0,
            64,   0,  91,   0,   0,  55,  15,  10,
            76,  99,  92,  82,   0,  68,   0,  68,
            0,  56,   0,  87,   2,   0,  84,  95,
            95,  60,  50,  50,  50,  50,   2,  15,
            35,   0,   0,   0,  24,  24,  65,  67,
            67,  79,  82,  68,  73,  79,  78,  32
    },
    {	// 18: SITAR
            99,  41,  26,  10,  99,  98,   0,   0,
            15,   0,   0,   4,  66,  12,  37,  18,
            0,  99,  77,  26,   7,  99,  98,   0,
            0,  15,   0,   0,   4,  18,   8,  87,
            2,   0,  99,  41,  42,   7,  99,  98,
            0,   0,  15,   0,   0,   4,  34,   4,
            90,  14,   0,  99,  77,  26,  28,  99,
            98,   0,   0,  15,   0,   0,   4,  58,
            8,  91,   2,   0,  99,  41,  26,   7,
            99,  98,   0,   0,  15,   0,   0,   4,
            58,   8,  97,   2,   0,  99,  77,  26,
            42,  99,  98,   0,   0,  15,   0,   0,
            4,  58,   4,  73,  40,   0,  99,  99,
            99,  99,  50,  50,  50,  50,   7,   8,
            28,   0,   0,   0,  32,  24,  83,  73,
            84,  65,  82,  32,  32,  32,  32,  32
    },
    {	// 19: HARP    2
            95,  46,  28,  24,  94,  79,   0,   0,
            0,   0,   0,   0,   7,  25,  90,   6,
            0,  95,  35,  99,  28,  99,  70,   0,
            0,  52,   0,  35,   3,  92,  16,  79,
            6,   0,  95,  32,  49,  33,  99,  70,
            0,   0,   0,   0,   0,   0,  27,  28,
            99,   2,   0,  95,  50,  44,  10,  99,
            70,   0,   0,  58,   0,  37,   0,  11,
            0,  62,   6,   0,  95,  46,  99,  12,
            99,  70,   0,   0,  52,   8,   0,   3,
            43,  12,  79,   4,   0,  95,  32,  45,
            31,  99,  70,   0,   0,   0,   0,   0,
            0,  99,  28,  99,   2,   0,  94,  67,
            95,  60,  50,  50,  50,  50,   2,  14,
            34,  33,   0,   0,  25,  24,  72,  65,
            82,  80,  32,  32,  32,  32,  50,  32
    },
    {	// 20: GONG    2
            40,  25,   7,  16,  86,  96,   0,   0,
            0,   0,   0,   0,  56,   8,  65,  24,
            20,  43,  30,  15,  10,  95,  87,   0,
            0,   0,   0,   0,   0,  56,  28,  67,
            8,  40,  79,  30,  15,  24,  95,  87,
            0,   0,   0,   0,   0,   0,  56,   8,
            65,   6,  26,  36,  30,  50,  24,  95,
            87,   0,   0,   0,   0,   0,   0,  56,
            4,  63,  14,  32,  29,  42,  20,  18,
            99,  85,  41,   0,   0,   0,   0,   0,
            57,   8,  56,   2,   0,  79,  26,  20,
            41,  99,  95,  41,   0,   0,   0,   0,
            0,  56,   4,  99,   2,   0,  99,  98,
            75,  60,  50,  50,  50,  50,  16,  15,
            35,  89,   0,   0,  89,  12,  71,  79,
            78,  71,  32,  32,  32,  32,  50,  32
    },
    {	// 21: SYN-LEAD 3
            99,  42,  35,  71,  99,  56,   0,   0,
            27,   0,  45,   7,  56,   0,  78,   4,
            0,  99,  76,  99,  71,  99,  88,  96,
            0,  39,   0,  14,  15,  56,   0,  83,
            2,   0,  99,  76,  99,  71,  99,  88,
            96,   0,  39,   0,  14,  15,  56,   0,
            99,   4,   0,  99,  76,  99,  71,  99,
            88,  96,   0,  39,   0,  14,  15,  56,
            0,  99,   4,   0,  99,  42,  35,  71,
            99,  56,   0,   0,  27,   0,  45,   7,
            56,   0,  97,   4,   0,  99,  76,  99,
            71,  99,  88,  42,   0,  39,   0,  14,
            15,  56,   0,  93,   2,   0,  84,  95,
            95,  60,  50,  50,  50,  50,  21,  15,
            37,   0,   0,   0,  88,  24,  83,  89,
            78,  45,  76,  69,  65,  68,  32,  51
    },
    {	// 22: SYN-CLAV 3
            93,  16,  17,  30,  77,  51,  88,   0,
            10,   0,   0,   4,  87,   7,  70,  24,
            0,  94,  17,  15,  40,  99,  87,  79,
            0,  10,   0,  50,   4,  63,   7,  80,
            24,   0,  95,  16,  15,  30,  99,  85,
            96,   0,   0,   0,   0,   4,  95,  28,
            96,   0,   0,  95,  17,  17,  66,  99,
            95,  70,   0,   0,   0,   0,   0,  87,
            9,  99,   2,   0,  80,   7,  21,  30,
            99,  85,  80,   0,   0,   0,   0,   4,
            63,  11,  99,   2,   0,  80,  32,  18,
            66,  99,  95,  90,   0,   0,   0,   0,
            0,  63,   8,  99,   2,   0,  50,  99,
            75,  99,  50,  50,  50,  50,   1,   2,
            41,  50,   0,  99,  10,  24,  83,  89,
            78,  45,  67,  76,  65,  86,  32,  51
    },
    {	// 23: SYNBRASS 2
            64,  99,  35,  93,  99,  99,  93,   0,
            15,   0,   0,   4,  60,   0,  88,   2,
            0,  82,  99,  99,  93,  99,  98,  98,
            0,  15,   0,   0,   4,  60,   0,  99,
            2,   0,  84,  99,  99,  93,  99,  98,
            98,   0,  15,   0,   0,   4,  60,   0,
            99,   2,   0,  81,  99,  99,  93,  99,
            99,  98,   0,  15,   0,   0,   4,  60,
            0,  98,   2,   0,  56,  99,  50,  93,
            99,  99,  84,   0,  15,   0,   0,   4,
        116,   0,  92,   0,   0,  81,  99,  99,
            93,  99,  99,  98,   0,  15,   0,   0,
            4, 116,   0,  99,   2,   0,  99,  99,
            99,  99,  50,  50,  50,  50,  21,  14,
            41,  74,   2,   0,  64,  12,  83,  89,
            78,  66,  82,  65,  83,  83,  32,  50
    },
    {	// 24: OCTAVE WAR
            75,  40,  36,  44,  99,  99,  98,   5,
            15,   0,  82,   4,  71,   0,  69,   0,
            0,  80,  40,  36,  44,  99,  99,  98,
            5,  15,   0,  11,   4,  67,   0,  64,
            2,   0,  48,  15,  54,  28,  99,  72,
            89,   0,  15,   0,  96,   4,  59,   0,
            44,  16,   0,  48,  15,  54,  28,  99,
            72,  89,   0,  15,   0,  96,   4,  59,
            0,  99,   4,   0,  48,  15,  54,  28,
            99,  72,  89,   0,  15,   0,  96,   4,
            59,   0,  93,   6,   0,  48,  15,  54,
            28,  99,  72,  89,   0,  15,   0,  96,
            4,  59,   0,  99,   6,   0,  98,  98,
            98,  98,  50,  50,  50,  50,   6,  14,
            21,   0,  58,  88, 118,  17,  79,  67,
            84,  65,  86,  69,  32,  87,  65,  82
    },
    {	// 25: BRASS S H
            42,  56,  20,  70,  99,   0,   0,   0,
            0,   0,   0,   0,  63,  15,  99,  14,
            21,  48,  12,  22,  50,  99,  61,  61,
            0,   0,   0,   0,   0,  29,  19,  50,
            12,   4,  66,  76,  22,  50,  99,  65,
            65,   0,  63,   0,   0,   0,  85,  19,
            74,   2,   0,  41,  12,  22,  50,  99,
            95,  95,   0,   0,   0,   0,   0,  53,
            8,  81,   2,   0,  99,  99,  99,  50,
            99,  99,  99,   0,  28,   0,  99,   0,
        114,   3,  96,   2,   0,  70,  24,  19,
            55,  99,  95,  95,   0,   0,   0,   0,
            0,  58,   0,  99,   2,   0,  86,  67,
            95,  60,  54,  50,  50,  50,  17,  15,
            42,   0,   5,  99,  43,  12,  66,  82,
            65,  83,  83,  32,  83,  32,  72,  32
    },
    {	// 26: LEAD BRASS
            42,  56,  20,  70,  99,   0,   0,   0,
            0,   0,   0,   0,  63,  12,  99,  14,
            21,  48,  12,  22,  50,  99,  61,  61,
            0,   0,   0,   0,   0,  53,   0,  50,
            12,   4,  66,  76,  22,  50,  99,  61,
            61,   0,  63,   0,   0,   0,  61,  16,
            74,   2,   0,  41,  12,  22,  50,  99,
            95,  95,   0,   0,   0,   0,   0,  61,
            0,  80,   2,   0,  99,  12,  22,  50,
            85,   0,   0,   0,  68,   0,  96,   4,
            58,  28,  45,   4,   5,  70,  24,  19,
            55,  99,  95,  53,   0,   0,   0,   0,
            0,  58,  16,  99,   2,   0,  86,  67,
            95,  60,  52,  50,  50,  50,  17,  15,
            34,  45,   5,   0,  32,  24,  76,  69,
            65,  68,  32,  66,  82,  65,  83,  83
    },
    {	// 27: PRC SYNTH2
            61,  38,  25,  77,  99,  72,  72,   0,
            39,   0,   0,  15, 112,   0,  79,   2,
            0,  99,  39,  25,  71,  99,  71,  64,
            0,  39,   0,   0,  15, 112,   0,  78,
            2,   0,  99,  76,  99,  99,  99,  88,
            96,   0,  39,   0,   0,  15, 112,   0,
            99,   2,   0,  99,  39,  25,  98,  99,
            71,  64,   0,  39,   0,   0,  15,  56,
            0,  83,   2,   0,  97,  38,  25,  47,
            99,  72,  72,   0,  39,   0,   0,  15,
            56,   0,  82,   2,   0,  99,  76,  99,
            99,  99,  88,  96,   0,  39,   0,   0,
            15,  56,   0,  99,   2,   0,  84,  95,
            95,  60,  50,  50,  50,  50,   2,  15,
            37,   0,   0,   0,  64,  12,  80,  82,
            67,  32,  83,  89,  78,  84,  72,  50
    },
    {	// 28: STRG-CHIME
            99,  64,  20,  34,  99,  90,   0,   0,
            44,  97,   0,   0,  58,  12,  81,  24,
            0,  99,  64,  20,  34,  99,  90,   0,
            0,  44,  97,   0,   0,  58,   8,  63,
            14,   0,  99,  64,  20,  34,  99,  90,
            0,   0,  44,  97,   0,   0,  58,   0,
            70,  10,   0,  99,  64,  20,  34,  99,
            90,   0,   0,  44,  97,   0,   0,  58,
            12,  99,   4,   0,  97,  15,  15,  43,
            99,  98,  98,   0,  34,   0,   0,   0,
            58,   0,  75,   2,   0,  40,  20,  20,
            47,  99,  99,  80,   0,  36,   0,  99,
            1,  58,   4,  99,   2,   0,  94,  67,
            95,  60,  50,  50,  50,  50,   1,  15,
            34,  33,   0,   0,  24,  24,  83,  84,
            82,  71,  45,  67,  72,  73,  77,  69
    },
    {	// 29: Mooger Low
            85,  55,  55,  65,  99,   0,   0,   0,
            0,   0,   0,   0,  56,   0,  85,   2,
            50,  80,  50,  40,  65,  99,  95,   0,
            0,  27,   0,  20,   3,  56,   0,  80,
            2,   0,  90,  30,  14,  65,  99,  95,
            85,   0,  39,   0,  15,   3,  56,   0,
            99,   0,   0,  90,  30,  14,  65,  99,
            95,  85,   0,  27,   0,  10,   3,  56,
            0,  80,   0,   0,  90,  30,  14,  65,
            99,  95,  85,   0,  39,   0,  10,   3,
            56,   0,  99,   0,   0,  90,  30,  14,
            65,  99,  95,  85,   0,  39,   0,  15,
            3,  56,   0,  99,   0,   0,  99,  99,
            99,  99,  50,  50,  50,  50,  25,  14,
            35,   0,   0,   0,  49,  12,  77, 111,
        111, 103, 101, 114,  32,  76, 111, 119
    },
    
};

#endif