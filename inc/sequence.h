#ifndef SEQUENCE_H 
#define SEQUENCE_H

struct Event 
{
	double duration;
	double freq;
	int is_active;
};

struct Sequence
{
	struct Event *ptr;
	int len;
};

struct Sequence sequenceGenerate(void);

void sequenceFree(struct Sequence *seq);

#endif
