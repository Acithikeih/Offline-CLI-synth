#include <stdlib.h>

#include "sequence.h"
#include "sequencer.h"

struct Sequence sequenceGenerate(void)
{
	return sequencer();
}

void sequenceFree(struct Sequence *seq)
{
	free(seq->ptr);
	seq->ptr = NULL;
	seq->len = 0;
}
