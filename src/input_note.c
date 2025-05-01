#include <stdlib.h>
#include <math.h>

#include "input_note.h"

static double valueToDuration(double value, double bpm)
{
	return value * 240 / bpm;
}

static double pitchToFrequency(int pitch, double tuning)
{
	return tuning * exp((pitch - 69) * log(2) / 12);
}

struct Sequence notesToSequence(struct Note *notes, int len, double tuning, double bpm)
{
	int i;
	struct Sequence seq;

	seq.ptr = malloc(sizeof(struct Event) * len);
	seq.len = len;

	for (i = 0; i < len; i++)
	{
		seq.ptr[i].duration = valueToDuration(notes[i].value, bpm);
		seq.ptr[i].freq = pitchToFrequency(notes[i].pitch, tuning);
		seq.ptr[i].is_active = notes[i].note_rest == N ? 1 : 0;
	}

	return seq;
}
