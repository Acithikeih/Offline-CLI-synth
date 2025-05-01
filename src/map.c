#include <stdlib.h>

#include "settings.h"
#include "map.h"

struct Map mapGenerate(struct Sequence seq)
{
	int i;
	int sum = 0;
	struct Map map;
	
	map.ptr = malloc(sizeof(struct Segment) * seq.len);
	map.len = seq.len;
	map.pos_g = 0;
	map.pos_l = 0;
	map.seg = 0;

	for (i = 0; i < seq.len; i++)
	{
		map.ptr[i].start = sum;
		map.ptr[i].len = seq.ptr[i].duration * sample_rate * oversampling;
		map.ptr[i].freq = seq.ptr[i].freq;
		map.ptr[i].is_active = seq.ptr[i].is_active;

		sum += map.ptr[i].len;
	}

	return map;
}

void mapFree(struct Map *map)
{
	free(map->ptr);
	map->ptr = NULL;
	map->len = 0;
	map->pos_g = 0;
	map->pos_l = 0;
	map->seg = 0;
}
