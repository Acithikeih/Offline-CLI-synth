#include <unistd.h>
#include <string.h>

#include "settings.h"
#include "validation.h"

int validation(void)
{
	if (sample_rate < 4000 || sample_rate > 384000)
	{
		return 1;
	}
	else if (bit_depth != 8 && bit_depth != 16 && bit_depth != 24 && bit_depth != 32)
	{
		return 2;
	}
	else if (channels < 1 || channels > 9)
	{
		return 3;
	}
	else if (oversampling < 1)
	{
		return 4;
	}
	else if (access(path, F_OK) == -1)
	{
		return 5;
	}
	else if (strnlen(name, 256) == 256)
	{
		return 6;
	}
	else
	{
		return 0;
	}
}
