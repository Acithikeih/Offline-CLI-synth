#include <math.h>
#include <sys/time.h>
#include <stdlib.h>

#include "settings.h"
#include "oscillator.h"

static double waveSine(double phase)
{
	return sin(phase);
}

static double waveSaw(double phase)
{
	return phase / M_PI - 1;
}

static double waveSawLimited(double phase, double freq)
{
	int i;
	int max = floor(oversampling * sample_rate / (2 * freq));
	double signal = 0;
	double harmonic;

	for (i = 1; i <= max; i++)
	{
		harmonic = pow(-1, i) * sin(i * phase) / (0.52 * i * M_PI);
		if (freq * i / (sample_rate * oversampling) >= 0.3)
		{
			harmonic *= 1 - (freq * i - 0.3 * oversampling * sample_rate) / (0.2 * oversampling * sample_rate);
		}
		signal += harmonic;
	}

	return -signal;
}

static double waveRectangle(double phase, double duty)
{
	if (phase < duty * M_PI * 2)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

static double waveTriangle(double phase)
{
	if (phase < M_PI)
	{
		return 2 * fmod(phase, M_PI) / M_PI - 1;
	}
	else
	{
		return 1 - 2 * fmod(phase, M_PI) / M_PI;
	}
}

static double waveNoise(void)
{
	struct timeval time;
	gettimeofday(&time, NULL);
	srandom(time.tv_usec);
	return (double)(random() % 2000000 - 1000000) / 1000000;
}

void phaseUpdate(struct Map map, struct Oscillator *osc)
{
	double offset = 2.0 * M_PI * osc->freq / (oversampling * sample_rate);

	if (osc->reset == 1 && map.pos_l == 0)
	{
		osc->phase = 0;
	}
	osc->phase += offset;
	osc->phase = fmod(osc->phase, 2 * M_PI);
}

double oscillator(struct Map map, struct Oscillator osc)
{
	double signal;
	
	if (map.ptr[map.seg].is_active == 0)
	{
		return 0;
	}

	switch(osc.waveform)
	{
		case SINE:
			signal = waveSine(osc.phase);
			break;
		case SAW:
			signal = waveSaw(osc.phase);
			break;
		case SAW_LIMITED:
			signal = waveSawLimited(osc.phase, osc.freq);
			break;
		case RECTANGLE:
			signal = waveRectangle(osc.phase, osc.duty_cycle);
			break;
		case TRIANGLE:
			signal = waveTriangle(osc.phase);
			break;
		case NOISE:
			signal = waveNoise();
			break;
		default:
			signal = 0;
			break;
	}
	
	if (osc.mode == UNI)
	{
		signal = (signal + 1) / 2;
	}

	return signal;
}
