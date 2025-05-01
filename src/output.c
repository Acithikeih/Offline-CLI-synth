#include <stdio.h>

#include "settings.h"
#include "output.h"

void outputPrologue(void)
{
	printf("Birdsong 0.0 by Acithikeih\n\n");
}

void outputError(int ret)
{
	char text[][32] =
	{
		"",
		"Invalid sample rate.",
		"Invalid bit depth.",
		"Invalid number of channels.",
		"Invalid oversampling factor.",
		"Invalid path.",
		"Invalid file name.",
		"WAV file cannot be created."
	};

	printf("\n\n%s Execution aborted.\n", text[ret]);
}

void outputStage(int stage)
{
	char text[][32] =
	{
		"Validating settings...",
		"Generating sequence...",
		"Generating map...     ",
		"Generating signal...  ",
		"Generating data...    ",
		"Generating WAV file..."
	};

	printf("%s", text[stage]);
}

void outputDone(void)
{
	printf(" Done\n");
}

void outputEpilogue(void)
{
	printf("\nExecution completed.\n");
}
