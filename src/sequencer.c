#include "sequencer.h"
#include "input_raw.h"
#include "input_note.h"

struct Sequence sequencer(void)
{
	double tuning = 440;
	double bpm = 113;
	struct Note notes[] =
	{
		{ N, B3N, S008 },
		{ N, D4N, S008 },
		{ N, F4S, S008 },
		{ N, B3N, D004 },
		{ N, F4S, S016 },
		{ N, G4N, S016 },
		{ N, A4N, D004 },
		{ N, G4N, S016 },
		{ N, A4N, S016 },
		{ N, B4N, D008 },
		{ N, A4N, D008 },
		{ N, G4N, S008 },
		{ N, G4N, S032 },
		{ N, A4N, D016 + D004 + S008 }
	};
	int len = sizeof(notes) / sizeof(struct Note);
	struct Sequence seq = notesToSequence(notes, len, tuning, bpm);
	
	/*
	struct Raw raw[] =
	{
		{ 10, 20, 1}
	};
	int len = sizeof(raw) / sizeof(struct Raw);
	struct Sequence seq = rawToSequence(raw, len);
	*/

	return seq;
}
