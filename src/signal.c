#include <stdlib.h>

#include "settings.h"
#include "signal.h"
#include "map.h"
#include "synthesizer.h"

static int getLen(struct Map map)
{
	int i;
	int len = 0;

	for (i = 0; i < map.len; i++)
	{
		len += map.ptr[i].len;
	}

	return len;
}

static void mapUpdate(struct Map *map, int pos)
{
	int i;
	
	map->pos_g = pos;

	for (i = 0; i < map->len; i++)
	{
		if (pos >= map->ptr[i].start && pos < map->ptr[i].start + map->ptr[i].len)
		{
			map->pos_l = pos - map->ptr[i].start;
			map->seg = i;
		}
	}
}

struct Signal signalGenerate(struct Map map)
{
	int i;
	struct Signal sig;
	
	sig.len = getLen(map);
	sig.ptr = malloc(sizeof(double) * sig.len);

	for (i = 0; i < sig.len; i++)
	{
		mapUpdate(&map, i);
		sig.ptr[i] = synthesizer(map);
	}

	return sig;
}

void signalFree(struct Signal *sig)
{
	free(sig->ptr);
	sig->ptr = NULL;
	sig->len = 0;
}
