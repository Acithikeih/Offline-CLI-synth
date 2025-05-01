#include "settings.h"
#include "envelope.h"

double envelope(struct Map map, struct Envelope env)
{
	double sig;
	int attack = env.attack * sample_rate * oversampling;
	int decay = env.decay * sample_rate * oversampling;

	if (map.pos_l < attack)
	{
		sig = (double)map.pos_l / attack;
	}
	else if (map.pos_l >= attack && map.pos_l < attack + decay)
	{
		sig = ((double)(decay + attack - map.pos_l) / decay) * (1.0 - env.sustain) + env.sustain;
	}
	else
	{
		sig = env.sustain;
	}

	return sig;
}
