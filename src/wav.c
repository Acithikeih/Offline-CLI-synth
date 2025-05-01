#include <stdio.h>

#include "settings.h"
#include "wav.h"

int wavGenerate(struct Data dat)
{
	FILE *file;
	char path_name[1024];
	int i;
	int j;
	int k;

	int byte_rate = channels * sample_rate * bit_depth / 8;
	int block_align = channels * bit_depth / 8;
	int size_data = dat.len * channels * bit_depth / 8;
	int size_file = size_data + 44;
	int sample;

	unsigned char *p_sr = (unsigned char *)(&sample_rate);
	unsigned char *p_bd = (unsigned char *)(&bit_depth);
	unsigned char *p_ch = (unsigned char *)(&channels);
	unsigned char *p_br = (unsigned char *)(&byte_rate);
	unsigned char *p_ba = (unsigned char *)(&block_align);
	unsigned char *p_sd = (unsigned char *)(&size_data);
	unsigned char *p_sf = (unsigned char *)(&size_file);
	unsigned char *p_sm = (unsigned char *)(&sample);

	snprintf(path_name, sizeof(path_name), "%s%s", path, name);
	file = fopen(path_name, "w");
	if (file == NULL)
	{
		return 7;
	}

	//Header
	fprintf(file, "RIFF");							//Chunk ID
	fprintf(file, "%c%c%c%c", p_sf[0], p_sf[1], p_sf[2], p_sf[3]);		//Chunk size
	fprintf(file, "WAVE");							//Wave ID

	//Format
	fprintf(file, "fmt ");							//Chunk ID
	fprintf(file, "%c%c%c%c", 16, 0, 0, 0);					//Chunk size
	fprintf(file, "%c%c", 1, 0);						//Format tag
	fprintf(file, "%c%c", p_ch[0], p_ch[1]);				//Channels
	fprintf(file, "%c%c%c%c", p_sr[0], p_sr[1], p_sr[2], p_sr[3]);		//Sample rate
	fprintf(file, "%c%c%c%c", p_br[0], p_br[1], p_br[2], p_br[3]);		//Byte rate
	fprintf(file, "%c%c", p_ba[0], p_ba[1]);				//Block align
	fprintf(file, "%c%c", p_bd[0], p_bd[1]);				//Bits per sample

	//Data
	fprintf(file, "data");							//Chunk ID
	fprintf(file, "%c%c%c%c", p_sd[0], p_sd[1], p_sd[2], p_sd[3]);		//Chunk size
	for (i = 0; i < dat.len; i++)						//Data
	{
		sample = dat.ptr[i];
		for (j = 0; j < channels; j++)
		{
			for (k = 0; k < bit_depth / 8; k++)
			{
				fprintf(file, "%c", p_sm[k]);
			}
		}
	}
	if (size_data % 2 == 1)							//Padding byte
	{
		fprintf(file, "%c", 0);
	}

	fclose(file);

	return 0;
}
