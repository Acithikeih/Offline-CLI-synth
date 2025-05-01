#ifndef OUTPUT_H
#define OUTPUT_H

enum Stages
{
	ST_VAL,
	ST_SEQ,
	ST_MAP,
	ST_SIG,
	ST_DAT,
	ST_WAV
};

void outputPrologue(void);

void outputError(int ret);

void outputStage(int stage);

void outputDone(void);

void outputEpilogue(void);

#endif
