#ifndef DATA_H 
#define DATA_H

#include "signal.h"

struct Data
{
	int *ptr;
	int len;
};

struct Data dataGenerate(struct Signal sig);

void dataFree(struct Data *dat);

#endif
