#include <stdlib.h>

#include "input_raw.h"

struct Sequence rawToSequence(struct Raw *raw, int len)
{
	int i;
	struct Sequence seq;

	seq.ptr = malloc(sizeof(struct Raw) * len);
	seq.len = len;

	for (i = 0; i < len; i++)
	{
		seq.ptr[i].duration = raw[i].duration;
		seq.ptr[i].freq = raw[i].freq;
		seq.ptr[i].is_active = raw[i].is_active;
	}

	return seq;
}
