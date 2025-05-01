#ifndef OSCILLATOR_H
#define OSCILLATOR_H

#include "map.h"

enum Waveforms
{
	SINE,
	SAW,
	SAW_LIMITED,
	RECTANGLE,
	TRIANGLE,
	NOISE
};

enum Mode
{
	UNI,
	BI
};

struct Oscillator
{
	int waveform;
	int mode;
	int reset;
	double freq;
	double duty_cycle;
	double phase;
};

void phaseUpdate(struct Map map, struct Oscillator *osc);

double oscillator(struct Map map, struct Oscillator osc);

#endif
