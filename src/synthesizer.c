#include "settings.h"
#include "map.h"
#include "track.h"
#include "oscillator.h"
#include "envelope.h"

double synthesizer(struct Map map)
{
	double sig_main;
	double sig_1;
	static struct Oscillator osc;
	static struct Oscillator lfo;
	struct Envelope env;
	
	osc.waveform = SINE;
	osc.mode = BI;
	osc.reset = 0;
	osc.freq = 440;
	osc.duty_cycle = 0.5;

	lfo.waveform = SINE;
	lfo.mode = BI;
	lfo.reset = 0;
	lfo.freq = 5;
	lfo.duty_cycle = 0.5;

	env.attack = 0.1;
	env.decay = 2;
	env.sustain = 0.8;

	//Track
	osc.freq = track(map, 0);

	//Modulations
	sig_1 = 0.1 * envelope(map, env);
	phaseUpdate(map, &lfo);
	osc.freq += 10 * oscillator(map, lfo);

	//Oscillators
	phaseUpdate(map, &osc);
	sig_main = oscillator(map, osc);

	//Filters
	//filterFunction
	
	return sig_main;

	/*
	double sig_main;
	static struct Oscillator osc;
	struct Envelope env;
	
	osc.waveform = SAW_LIMITED;
	osc.mode = BI;
	osc.reset = 0;
	osc.freq = 440;
	osc.duty_cycle = 0.5;

	env.attack = 10;
	env.decay = 0;
	env.sustain = 1;

	//Track
	osc.freq = track(map, 0);

	//Modulations
	osc.freq = 20000 * envelope(map, env);

	//Oscillators
	phaseUpdate(map, &osc);
	sig_main = 0.1 * oscillator(map, osc);

	//Filters
	//filterFunction
	
	return sig_main;
	*/
}
