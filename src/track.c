#include "track.h"
#include <math.h>

double track(struct Map map, int oct)
{
	return map.ptr[map.seg].freq * pow(2, oct);
}
