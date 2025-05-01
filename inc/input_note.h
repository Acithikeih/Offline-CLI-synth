#ifndef INPUT_NOTE_H
#define INPUT_NOTE_H

#include "sequence.h"

#define S001 1
#define S002 0.5
#define S004 0.25
#define S008 0.125
#define S016 0.0625
#define S032 0.03125
#define S064 0.015625
#define S128 0.0078125
#define S256 0.00390625
#define S512 0.001953125
#define D001 1.5
#define D002 0.75
#define D004 0.375
#define D008 0.1875
#define D016 0.09375
#define D032 0.046875
#define D064 0.0234375
#define D128 0.01171875
#define D256 0.005859375
#define D512 0.0029296875
#define T001 2.0 / 3.0
#define T002 1.0 / 3.0
#define T004 1.0 / 6.0
#define T008 1.0 / 12.0
#define T016 1.0 / 24.0
#define T032 1.0 / 48.0
#define T064 1.0 / 96.0
#define T128 1.0 / 192.0
#define T256 1.0 / 384.0
#define T512 1.0 / 768.0

enum Pitches
{
	A0N = 21,
	A0S,
	B0N,
	C1N,
	C1S,
	D1N,
	D1S,
	E1N,
	F1N,
	F1S,
	G1N,
	G1S,
	A1N,
	A1S,
	B1N,
	C2N,
	C2S,
	D2N,
	D2S,
	E2N,
	F2N,
	F2S,
	G2N,
	G2S,
	A2N,
	A2S,
	B2N,
	C3N,
	C3S,
	D3N,
	D3S,
	E3N,
	F3N,
	F3S,
	G3N,
	G3S,
	A3N,
	A3S,
	B3N,
	C4N,
	C4S,
	D4N,
	D4S,
	E4N,
	F4N,
	F4S,
	G4N,
	G4S,
	A4N,
	A4S,
	B4N,
	C5N,
	C5S,
	D5N,
	D5S,
	E5N,
	F5N,
	F5S,
	G5N,
	G5S,
	A5N,
	A5S,
	B5N,
	C6N,
	C6S,
	D6N,
	D6S,
	E6N,
	F6N,
	F6S,
	G6N,
	G6S,
	A6N,
	A6S,
	B6N,
	C7N,
	C7S,
	D7N,
	D7S,
	E7N,
	F7N,
	F7S,
	G7N,
	G7S,
	A7N,
	A7S,
	B7N,
	C8N,
	B0S = 24,
	B1S = 36,
	B2S = 48,
	B3S = 60,
	B4S = 72,
	B5S = 84,
	B6S = 96,
	B7S = 108,
	E1S = 29,
	E2S = 41,
	E3S = 53,
	E4S = 65,
	E5S = 77,
	E6S = 89,
	E7S = 101,
	B0F = 22,
	C1F = 23,
	D1F = 25,
	E1F = 27,
	F1F = 28,
	G1F = 30,
	A1F = 32,
	B1F = 34,
	C2F = 35,
	D2F = 37,
	E2F = 39,
	F2F = 40,
	G2F = 42,
	A2F = 44,
	B2F = 46,
	C3F = 47,
	D3F = 49,
	E3F = 51,
	F3F = 52,
	G3F = 54,
	A3F = 56,
	B3F = 58,
	C4F = 59,
	D4F = 61,
	E4F = 63,
	F4F = 64,
	G4F = 66,
	A4F = 68,
	B4F = 70,
	C5F = 71,
	D5F = 73,
	E5F = 75,
	F5F = 76,
	G5F = 78,
	A5F = 80,
	B5F = 82,
	C6F = 83,
	D6F = 85,
	E6F = 87,
	F6F = 88,
	G6F = 90,
	A6F = 92,
	B6F = 94,
	C7F = 95,
	D7F = 97,
	E7F = 99,
	F7F = 100,
	G7F = 102,
	A7F = 104,
	B7F = 106,
	C8F = 107
};

enum NoteRest
{
	N,
	R
};

struct Note 
{
	int note_rest;
	int pitch;
	double value;
};

struct Sequence notesToSequence(struct Note *notes, int len, double tuning, double bpm);

#endif
