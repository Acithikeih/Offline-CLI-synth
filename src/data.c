#include <stdlib.h>
#include <math.h>

#include "settings.h"
#include "data.h"
#include "signal.h"

static int signalToSample(double sig)
{
	int max = (pow(2, bit_depth - 1) - 1);

	if (sig > 1)
	{
		return max;
	}
	else if (sig < -1)
	{
		return -max;
	}
	else
	{
		return sig * max;
	}
}

struct Data dataGenerate(struct Signal sig)
{
	int i;
	struct Data dat;
	
	dat.ptr = malloc(sizeof(int) * sig.len / oversampling);
	dat.len = sig.len / oversampling;

	for (i = 0; i < dat.len; i++)
	{
		dat.ptr[i] = signalToSample(sig.ptr[i * oversampling]);
	}

	return dat;
}

void dataFree(struct Data *dat)
{
	free(dat->ptr);
	dat->ptr = NULL;
	dat->len = 0;
}
