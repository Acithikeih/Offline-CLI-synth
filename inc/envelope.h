#ifndef ENVELOPE_H
#define ENVELOPE_H

#include "map.h"

struct Envelope
{
	double attack;
	double decay;
	double sustain;
};

double envelope(struct Map map, struct Envelope env);

#endif
