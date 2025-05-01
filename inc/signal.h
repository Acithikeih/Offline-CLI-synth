#ifndef SIGNAL_H
#define SIGNAL_H

#include "map.h"

struct Signal 
{
	double *ptr;
	int len;
};

struct Signal signalGenerate(struct Map map);

void signalFree(struct Signal *sig);

#endif
