#ifndef INPUT_RAW_H
#define INPUT_RAW_H

#include "sequence.h"

struct Raw
{
	double duration;
	double freq;
	int is_active;
};

struct Sequence rawToSequence(struct Raw *raw, int len);

#endif
