#ifndef MAP_H 
#define MAP_H

#include "sequence.h"

struct Segment
{
	int start;
	int len;
	double freq;
	int is_active;
};

struct Map
{
	struct Segment *ptr;
	int len;
	int pos_g;
	int pos_l;
	int seg;
};

struct Map mapGenerate(struct Sequence seq);

void mapFree(struct Map *map);

#endif
