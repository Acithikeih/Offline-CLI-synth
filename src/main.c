#include "validation.h"
#include "output.h"
#include "sequence.h"
#include "map.h"
#include "signal.h"
#include "data.h"
#include "wav.h"

int main(void)
{
	struct Sequence seq;
	struct Map map;
	struct Signal sig;
	struct Data dat;
	int ret;

	//Prologue
	outputPrologue();

	//Validation
	outputStage(ST_VAL);
	ret = validation();
	if (ret != 0)
	{
		outputError(ret);
		return ret;
	}
	outputDone();

	//Sequence
	outputStage(ST_SEQ);
	seq = sequenceGenerate();
	outputDone();
	
	//Map
	outputStage(ST_MAP);
	map = mapGenerate(seq);
	sequenceFree(&seq);
	outputDone();
	
	//Signal
	outputStage(ST_SIG);
	sig = signalGenerate(map);
	mapFree(&map);
	outputDone();

	//Data
	outputStage(ST_DAT);
	dat = dataGenerate(sig);
	signalFree(&sig);
	outputDone();

	//WAV
	outputStage(ST_WAV);
	ret = wavGenerate(dat);
	dataFree(&dat);
	if (ret != 0)
	{
		outputError(ret);
		return ret;
	}
	outputDone();

	//Epilogue
	outputEpilogue();

	return 0;
}
