#ifndef MicroDexed_preset_organ_h_
#define MicroDexed_preset_organ_h_

#ifndef NUM_VALUES_PER_VOICE
#define NUM_VALUES_PER_VOICE 128
#endif
#ifndef MAX_NUM_TRANSPOSE
#define MAX_NUM_TRANSPOSE 36
#endif

#define NUM_ORGAN_VOICES 16
constexpr uint8_t organ_bank[NUM_ORGAN_VOICES][NUM_VALUES_PER_VOICE] PROGMEM =
{
	{	// 17: ORGEL 1
			 99,  92,  22,  90,  99,   0,   0,   0,
			  0,   0,   0,   0,  56,   0,  99,   4,
			  0,  99,  80,  22,  90,  99,  99,  99,
			  0,   0,   0,   5,   0,  72,   0,  94,
			  6,   0,  99,  80,  22,  90,  99,  99,
			 99,   0,   0,   0,   0,   0,  96,   0,
			 94,   0,   0,  99,  80,  54,  82,  99,
			 99,  99,   0,   0,   0,   0,   0,  88,
			  0,  94,   2,  50,  99,  20,  22,  90,
			 99,  99,  97,   0,   0,   0,  10,   0,
			  8,   0,  94,   2,   1,  99,  80,  22,
			 90,  99,  99,  99,   0,   0,   0,   0,
			  0,  40,   0,  94,   0,   0,  75,  80,
			 75,  60,  50,  50,  50,  50,  30,  15,
			 35,   0,   0,   0,  64,  24,  79,  82,
			 71,  69,  76,  32,  49,  32,  32,  32
		},
		{	// 18: B 3 ORGAN
			 99,  42,  99,  99,  99,  99,   0,   0,
			 51,  11,  99,  12,  56,   0,  99,   1,
			  2,  99,  21,  99,  99,  99,  80,  80,
			  0,  51,   0,  25,  12,  56,   0,  85,
			  2,   0,  99,  50,  55,  99,  99,  99,
			  0,   0,   0,   0,   0,   0,  57,   0,
			 99,   6,   0,  99,  99,  99,  99,  99,
			 99,  99,   0,   0,   0,   0,   0,  56,
			  3,  95,   2,   0,  99,  99,  99,  99,
			 99,  99,  99,   0,   0,   0,   0,   0,
			 56,   3,  95,   2,  50,  99,  99,  99,
			 99,  99,  99,  99,   0,   0,   0,   0,
			  0,  56,   2,  99,   0,   0,  99,  99,
			 99,  99,  50,  50,  50,  50,  30,  15,
			 40,   0,   0,  60,  57,  24,  66,  32,
			 51,  32,  79,  82,  71,  65,  78,  32
		},
		{	// 17: E.ORGAN 1
			 99,  54,  22,  90,  99,   0,   0,   0,
			  0,   0,   0,   0,  56,   0,  94,   6,
			  0,  99,  80,  22,  90,  99,  99,  99,
			  0,   0,   0,   0,   0,  72,   0,  94,
			  2,   0,  99,  80,  22,  90,  99,  99,
			 99,   0,   0,   0,   0,   0,  96,   0,
			 94,   0,   0,  99,  80,  54,  82,  99,
			 99,  99,   0,   0,   0,   0,   0,  88,
			  0,  94,   2,  50,  99,  20,  22,  90,
			 99,  99,  97,   0,   0,   0,  10,   0,
			  8,   0,  94,   2,   1,  99,  80,  22,
			 90,  99,  99,  99,   0,   0,   0,   0,
			  0,  40,   0,  94,   0,   0,  75,  80,
			 75,  60,  50,  50,  50,  50,  31,   8,
			 35,   0,   0,   0,  64,  24,  69,  46,
			 79,  82,  71,  65,  78,  32,  49,  32
		},
		{	// 13: E.ORGAN 2
			 99,  42,  99,  99,  99,  99,  99,   0,
			 39,   0,   0,   0,  56,  28,  71,   2,
			  0,  99,  31,  99,  98,  99,  80,  80,
			  0,  39,   0,   0,   0,  56,   0,  99,
			  6,   0,  99,  99,  99,  98,  99,  99,
			 99,   0,  39,   0,   0,   0,  40,  28,
			 81,   2,   0,  99,  99,  99,  98,  99,
			 99,  99,   0,  39,   0,   0,   0,  64,
			  0,  99,   4,   0,  99,  99,  99,  98,
			 99,  99,  99,   0,  39,   0,   0,   0,
			 64,  12,  98,   2,  50,  99,  99,  99,
			 98,  99,  99,  99,   0,  39,   0,   0,
			  0,  56,   0,  99,   2,   0,  99,  71,
			 95,  60,  50,  50,  50,  50,  28,   6,
			 35,   0,   0,   0,  40,  24,  69,  46,
			 79,  82,  71,  65,  78,  32,  50,  32
		},
		{	// 14: E.ORGAN 3
			 99,  61,  99,  99,  99,   0,   0,   0,
			 39,  98,   0,   0,  56,   0,  75,   8,
			  0,  99,  99,  99,  98,  99,  99,  99,
			  0,  39,   0,   0,   0,  56,   0,  86,
			  4,   0,  99,  99,  99,  98,  99,  99,
			 99,   0,  39,   0,   0,   0,  56,  28,
			 71,  10,   0,  99,  99,  99,  98,  99,
			 99,  99,   0,  86,  98,   0,  15,  56,
			 28,  99,   4,   0,  99,  99,  99,  98,
			 99,  99,  99,   0,  39,   0,   0,   0,
			 64,   0,  99,   2,   0,  99,  99,  99,
			 98,  99,  99,  99,   0,  39,   0,   0,
			  0,  56,   0,  99,   0,   0,  99,  71,
			 95,  60,  50,  50,  50,  50,  28,   0,
			 33,   0,   0,   0,  40,  24,  69,  46,
			 79,  82,  71,  65,  78,  32,  51,  32
		},
		{	// 15: E.ORGAN 4
			 91,  79,  99,  82,  86,  50,   0,   0,
			  0,   0,   0,   0, 114,   0,  99,   8,
			  0,  97,  99,  50,  82,  99,  90,  84,
			  0,   0,   0,   0,   0,  58,  28,  99,
			 10,   0,  79,  98,  99,  82,  99,  89,
			 80,   0,   0,   0,   0,   0,  42,  28,
			 99,   0,   0,  97,  97,  99,  82,  99,
			 99,  97,   0,   0,   0,   0,   0, 114,
			  0,  99,   2,   0,  97,  97,  99,  82,
			 99,  99,  97,   0,   0,   0,   0,   0,
			 74,  28,  82,   0,   0,  97,  97,  99,
			 82,  99,  99,  99,   0,   0,   0,   0,
			  0,  42,   0,  95,   0,   0,   4,  67,
			 95,  60,  50,  50,  50,  50,   4,  15,
			 34,  33,   0,   0,  32,  24,  69,  46,
			 79,  82,  71,  65,  78,  32,  52,  32
		},
		{	// 16: E.ORGAN 5
			 99,  98,  10,  99,  99,  99,  99,   0,
			  0,   0,   0,   0,  56,   0,  73,   2,
			  0,  99,  98,  10,  99,  99,  99,  99,
			  0,   0,   0,   0,   0,  56,   0,  89,
			  6,   0,  99,  98,  10,  99,  99,  99,
			 99,   0,   0,   0,   0,   0,  56,   0,
			 90,   6,   0,  99,  98,  10,  99,  99,
			 99,  99,   0,  63,   0,  99,   0,  56,
			  0,  90,   6,   0,  99,  98,  10,  99,
			 99,  99,  99,   0,   0,   0,   0,   0,
			 56,   0,  90,   4,   0,  99,  98,  10,
			 99,  99,  99,  99,   0,   0,   0,   0,
			  0,  56,   0,  91,   0,   0,  75,  80,
			 75,  60,  50,  50,  50,  50,  28,  14,
			 35,  14,  22,   0,  25,  24,  69,  46,
			 79,  82,  71,  65,  78,  32,  53,  32
		},
		{	// 11: SYNORGAN 1
			 99,  57,  45,  71,  99,  36,  31,   0,
			 27,   0,  45,   7,  56,   0,  83,  40,
			  0,  64,  39,  79,  71,  99,  99,  99,
			  0,  39,   0,  14,  15,  56,   0,  98,
			  8,   0,  64,  39,  79,  71,  99,  99,
			 99,   0,  39,   0,  14,  15,  56,   0,
			 99,   4,   0,  64,  39,  79,  71,  99,
			 99,  99,   0,  39,   0,  14,  15,  56,
			  0,  99,   2,   0,  99,  42,  53,  71,
			 99,  56,  56,   0,  27,   0,  45,   7,
			 56,   0,  78,   2,   0,  99,  76,  99,
			 71,  99,  88,  96,   0,  39,   0,  14,
			 15,  56,   0,  99,   6,   0,  84,  95,
			 95,  60,  50,  50,  50,  50,  21,  15,
			 37,   0,   0,   0,  72,  12,  83,  89,
			 78,  79,  82,  71,  65,  78,  32,  49
		},
		{	// 12: SYNORGAN 2
			 69,  70,  23,  54,  99,  99,   0,   0,
			  0,   0,   0,   0,  51,  28,  75,   2,
			  0,  69,  70,  22,  54,  99,  99,   0,
			 84,   0,   0,   0,   0,  59,  16,  99,
			  0,   0,  97,  70,  30,  65,   0,  95,
			 90,   0,   0,   0,   0,   0,  59,   8,
			 99,   0,   0,  12,  70,  25,  54,  99,
			 99,   0,   0,   0,   0,   0,   0,  59,
			 28,  77,  18,   0,  12,  70,  10,  54,
			 99,  99,  99,   0,   0,   0,   0,   0,
			 59,  12,  99,   0,   0,  85,  70,  34,
			 65,   0,  95,  90,   0,   0,   0,   0,
			  0,  75,   0,  93,  16,   0,  94,  67,
			 95,  60,  50,  50,  50,  50,   2,   4,
			 34,  33,   0,   0,  56,  24,  83,  89,
			 78,  79,  82,  71,  65,  78,  32,  50
		},
		{	// 10: PIPES   1
			 72,  25,  25,  70,  99,  99,  99,   0,
			 46,  10,   1,  12,  59,   8,  76,  20,
			  0,  61,  25,  25,  61,  99,  99,  93,
			  0,   0,   0,   0,   0,  59,   0,  97,
			  4,   0,  61,  25,  25,  50,  99,  99,
			 97,   0,  60,  10,  10,   0,  59,   0,
			 88,   8,   0,  99,  97,  62,  47,  99,
			 99,  90,   0,  46,  17,  40,   3,  61,
			  0,  75,   2,   0,  99,  97,  62,  47,
			 99,  99,  90,   0,   0,   0,   0,   0,
			 60,   0,  90,   0,   0,  45,  25,  25,
			 36,  99,  99,  98,   0,  41,   0,  50,
			  0,  61,   0,  99,   0,   0,  94,  67,
			 95,  60,  50,  50,  50,  50,  18,  15,
			 34,  33,   0,   0,  40,  12,  80,  73,
			 80,  69,  83,  32,  32,  32,  49,  32
		},
		{	// 11: E.ORGAN 1
			 99,  54,  22,  90,  99,   0,   0,   0,
			  0,   0,   0,   0,  56,   0,  94,   6,
			  0,  99,  80,  22,  90,  99,  99,  99,
			  0,   0,   0,   0,   0,  72,   0,  94,
			  2,   0,  99,  80,  22,  90,  99,  99,
			 99,   0,   0,   0,   0,   0,  96,   0,
			 94,   0,   0,  99,  80,  54,  82,  99,
			 99,  99,   0,   0,   0,   0,   0,  88,
			  0,  94,   2,  50,  99,  20,  22,  90,
			 99,  99,  97,   0,   0,   0,  10,   0,
			  8,   0,  94,   2,   1,  99,  80,  22,
			 90,  99,  99,  99,   0,   0,   0,   0,
			  0,  40,   0,  94,   0,   0,  75,  80,
			 75,  60,  50,  50,  50,  50,  31,   8,
			 35,   0,   0,   0,  32,  24,  69,  46,
			 79,  82,  71,  65,  78,  32,  49,  32
		},
		{	// 13: E.ORGAN 2
			 99,  61,  99,  99,  99,   0,   0,   0,
			 39,  98,   0,   0,  56,   0,  75,   8,
			  0,  99,  99,  99,  98,  99,  99,  99,
			  0,  39,   0,   0,   0,  56,   0,  86,
			  4,   0,  99,  99,  99,  98,  99,  99,
			 99,   0,  39,   0,   0,   0,  56,  28,
			 71,  10,   0,  99,  99,  99,  98,  99,
			 99,  99,   0,  86,  99,   0,  15,  56,
			 28,  99,   4,   0,  99,  99,  99,  98,
			 99,  99,  99,   0,  39,   0,   0,   0,
			 64,   0,  99,   2,   0,  99,  99,  99,
			 98,  99,  99,  99,   0,  39,   0,   0,
			  0,  56,   0,  99,   0,   0,  98,  71,
			 95,  60,  50,  50,  50,  50,  28,   0,
			 32,   0,   0,   0,  16,  24,  69,  46,
			 79,  82,  71,  65,  78,  32,  50,  32
		},
		{	// 14: E.ORGAN 3
			 99,  42,  99,  99,  99,   0,   0,   0,
			 39,   0,   0,   0,  56,  28,  62,  14,
			  0,  99,  99,  99,  98,  99,  99,  99,
			  0,  39,   0,   0,   0,  56,   0,  99,
			  6,   0,  99,  99,  99,  98,  99,  99,
			 99,   0,  39,   0,   0,   0,  24,   0,
			 75,   2,   0,  99,  99,  99,  98,  99,
			 99,  99,   0,  39,   0,   0,   0,  88,
			  0,  99,   2,   0,  99,  99,  99,  98,
			 99,  99,  99,   0,  39,   0,   0,   0,
			 64,   0,  99,   4,   0,  99,  99,  99,
			 98,  99,  99,  99,   0,  39,   0,   0,
			  0,  56,   0,  99,   2,   0,  98,  71,
			 95,  60,  50,  50,  50,  50,  28,   0,
			 32,   0,   0,   0,  24,  24,  69,  46,
			 79,  82,  71,  65,  78,  32,  51,  32
		},
		{	// 15: 60-S ORGAN
			 99,  98,  10,  99,  99,  99,  99,   0,
			  0,   0,   0,   0,  56,   0,  73,   2,
			  0,  99,  98,  10,  99,  99,  99,  99,
			  0,   0,   0,   0,   0,  56,   0,  89,
			  6,   0,  99,  98,  10,  99,  99,  99,
			 99,   0,   0,   0,   0,   0,  56,   0,
			 90,   6,   0,  99,  98,  10,  99,  99,
			 99,  99,   0,   0,   0,   0,   0,  56,
			  0,  90,   6,   0,  99,  98,  10,  99,
			 99,  99,  99,   0,   0,   0,   0,   0,
			 56,   0,  90,   4,   0,  99,  98,  10,
			 99,  99,  99,  99,   0,   0,   0,   0,
			  0,  56,   0,  91,   0, 100,  75,  80,
			 75,  60,  50,  50,  50,  50,  28,  14,
			 35,  14,  22,   0,  25,  24,  54,  48,
			 45,  83,  32,  79,  82,  71,  65,  78
		},
		{	// 16: PIPES   2
			 89,  80,  22,  65,  99,  99,  99,   0,
			  0,   0,  60,   4,  56,   0,  58,   8,
			  1,  88,  68,  22,  75,  70,  70,  70,
			  0,  78,   0,   5,   8,  56,   0,  84,
			 16,   1,  62,  80,  22,  50,  99,  99,
			 99,   0,   0,   0,  20,   0,  48,   0,
			 98,   4,   1,  47,  80,  22,  63,  99,
			 99,  99,   0,  35,  13,  15,   0,  60,
			  0,  97,   2,   1,  85,  30,  57,  64,
			 57,  75,  99,   0,   0,   0,  30,   0,
			 56,   0,  99,   8,   1,  53,  80,  41,
			 48,  99,  97,  99,   0,  35,  13,  10,
			  3,  58,   0,  99,   0,   0,  94,   3,
			 95,  60,  50,  50,  50,  50,  24,   3,
			 35,  63,   0,   0,  24,  24,  80,  73,
			 80,  69,  83,  32,  32,  32,  50,  32
		},
		{	// 17: PIPES   3
			 99,  99,  99,  45,  99,  99,  99,   0,
			 27,  14,  83,   4,  59,   0,  79,  12,
			  0,  43,  99,  99,  51,  99,  99,  99,
			  0,   0,   0,   6,   0,  59,   0,  81,
			  4,   0,  99,  99,  25,  50,  99,  99,
			 99,   0,  60,   0,   0,   0,  59,   0,
			 72,   2,   0,  53,  37,  18,  54,  99,
			 99,  97,   0,   0,   0,   3,   3,  61,
			  0,  94,   4,   0,  99,  97,  62,  54,
			 99,  99,  90,   0,   0,   0,   0,   0,
			 60,   0,  83,   0,   0,  60,  25,  25,
			 71,  99,  99,  98,   0,   0,   0,   4,
			  0,  56,   0,  94,   2,   0,  94,  67,
			 95,  60,  50,  50,  50,  50,   5,   8,
			 34,  33,   0,   0,  24,  24,  80,  73,
			 80,  69,  83,  32,  32,  32,  51,  32
		},

};

#endif