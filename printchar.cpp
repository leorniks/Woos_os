//yeah i know that is shit, maybe i will rewrite it later.

#include "Wooslib/printchar.h"

long long xp = 5;

extern "C" void printSP(int* fb, long long pixels) {
	xp += 8;
}
extern "C" void printA(int* fb, long long pixels, long long color) {
	for (long long y = 15; y < 23; y++) {
		fb[y * pixels + xp] = color;
		fb[y * pixels + xp + 5] = color;
	}
	for (long long x = xp + 1; x < xp + 5; x++) {
		fb[14 * pixels + x] = color;
	}
	for (long long x = xp; x < xp + 5; x++) {
		fb[19 * pixels + x] = color;
	}
	xp += 8;
}
extern "C" void printB(int* fb, long long pixels, long long color) {
	for (long long y = 14; y < 23; y++) {
		fb[y * pixels + xp] = color;
	}
	for (long long x = xp + 1; x < xp + 5; x++) {
		fb[14 * pixels + x] = color;
		fb[18 * pixels + x] = color;
		fb[22 * pixels + x] = color;
	}
	for (long long y = 15; y < 18; y++) {
		fb[y * pixels + xp + 5] = color;
	}
	for (long long y = 19; y < 22; y++) {
		fb[y * pixels + xp + 5] = color;
	}
	xp += 8;
}
extern "C" void printC(int* fb, long long pixels, long long color) {
	for (long long y = 15; y < 22; y++) {
		fb[y * pixels + xp] = color;
	}
	for (long long x = xp + 1; x < xp + 6; x++) {
		fb[14 * pixels + x] = color;
		fb[22 * pixels + x] = color;
	}
	xp += 8;
}
extern "C" void printD(int* fb, long long pixels, long long color) {
	for (long long y = 14; y < 23; y++) {
		fb[y * pixels + xp] = color;
	}
	for (long long x = xp + 1; x < xp + 5; x++) {
		fb[14 * pixels + x] = color;
		fb[22 * pixels + x] = color;
	}
	for (long long y = 15; y < 22; y++) {
		fb[y * pixels + xp + 5] = color;
	}
	xp += 8;
}
extern "C" void printE(int* fb, long long pixels, long long color) {
	for (long long y = 14; y < 23; y++) {
		fb[y * pixels + xp] = color;
	}
	for (long long x = xp; x < xp + 6; x++) {
		fb[14 * pixels + x] = color;
		fb[18 * pixels + x] = color;
		fb[22 * pixels + x] = color;
	}
	xp += 8;
}
extern "C" void printF(int* fb, long long pixels, long long color) {
	for (long long y = 14; y < 23; y++) {
		fb[y * pixels + xp] = color;
	}
	for (long long x = xp; x < xp + 6; x++) {
		fb[14 * pixels + x] = color;
		fb[18 * pixels + x] = color;
	}
	xp += 8;
}
extern "C" void printG(int* fb, long long pixels, long long color) {
	for (long long y = 15; y < 22; y++) {
		fb[y * pixels + xp] = color;
	}
	for (long long x = xp + 1; x < xp + 6; x++) {
		fb[14 * pixels + x] = color;
	}
	for (long long x = xp + 1; x < xp + 5; x++) {
		fb[22 * pixels + x] = color;
	}
	for (long long y = 19; y < 22; y++) {
		fb[y * pixels + xp + 5] = color;
	}
	fb[18 * pixels + xp + 3] = color;
	fb[18 * pixels + xp + 4] = color;
	xp += 8;
}
extern "C" void printH(int* fb, long long pixels, long long color) {
	for (long long y = 14; y < 23; y++) {
		fb[y * pixels + xp] = color;
	}
	for (long long y = 14; y < 23; y++) {
		fb[y * pixels + xp + 5] = color;
	}
	for (long long x = xp + 1; x < xp + 5; x++) {
		fb[18 * pixels + x] = color;
	}
	xp += 8;
}
extern "C" void printI(int* fb, long long pixels, long long color) {
	for (long long y = 14; y < 23; y++) {
		fb[y * pixels + xp] = color;
	}
	xp += 3;
}
extern "C" void printJ(int* fb, long long pixels, long long color) {
	for (long long x = xp; x < xp + 6; x++) {
		fb[14 * pixels + x] = color;
	}
	for (long long y = 14; y < 22; y++) {
		fb[y * pixels + xp + 5] = color;
	}
	for (long long x = xp + 1; x < xp + 5; x++) {
		fb[22 * pixels + x] = color;
	}
	fb[21 * pixels + xp] = color;
	xp += 8;
}
extern "C" void printK(int* fb, long long pixels, long long color) {
	for (long long y = 14; y < 23; y++) {
		fb[y * pixels + xp] = color;
	}
	fb[18 * pixels + xp + 1] = color;
	fb[19 * pixels + xp + 2] = color;
	fb[20 * pixels + xp + 3] = color;
	fb[21 * pixels + xp + 4] = color;
	fb[22 * pixels + xp + 5] = color;
	fb[17 * pixels + xp + 2] = color;
	fb[16 * pixels + xp + 3] = color;
	fb[15 * pixels + xp + 4] = color;
	fb[14 * pixels + xp + 5] = color;
	xp += 8;
}
extern "C" void printL(int* fb, long long pixels, long long color) {
	for (long long y = 14; y < 22; y++) {
		fb[y * pixels + xp] = color;
	}
	for (long long x = xp; x < xp + 6; x++) {
		fb[22 * pixels + x] = color;
	}
	xp += 8;
}
extern "C" void printM(int* fb, long long pixels, long long color) {
	for (long long y = 14; y < 23; y++) {
		fb[y * pixels + xp] = color;
		fb[y * pixels + xp + 5] = color;
	}
	fb[15 * pixels + xp + 1] = color;
	fb[16 * pixels + xp + 2] = color;
	fb[16 * pixels + xp + 3] = color;
	fb[15 * pixels + xp + 4] = color;
	xp += 8;
}
extern "C" void printN(int* fb, long long pixels, long long color) {
	for (long long y = 14; y < 23; y++) {
		fb[y * pixels + xp] = color;
		fb[y * pixels + xp + 5] = color;
	}
	fb[15 * pixels + xp + 1] = color;
	fb[16 * pixels + xp + 2] = color;
	fb[17 * pixels + xp + 3] = color;
	fb[18 * pixels + xp + 4] = color;
	xp += 8;
}
extern "C" void printO(int* fb, long long pixels, long long color) {
	for (long long y = 15; y < 22; y++) {
		fb[y * pixels + xp] = color;
		fb[y * pixels + xp + 5] = color;
	}
	for (long long x = xp + 1; x < xp + 5; x++) {
		fb[14 * pixels + x] = color;
		fb[22 * pixels + x] = color;
	}
	xp += 8;
}
extern "C" void printP(int* fb, long long pixels, long long color) {
	for (long long y = 14; y < 23; y++) {
		fb[y * pixels + xp] = color;
	}
	for (long long x = xp; x < xp + 5; x++) {
		fb[14 * pixels + x] = color;
		fb[18 * pixels + x] = color;
	}
	for (long long y = 15; y < 18; y++) {
		fb[y * pixels + xp + 5] = color;
	}
	xp += 8;
}
extern "C" void printQ(int* fb, long long pixels, long long color) {
	for (long long y = 15; y < 22; y++) {
		fb[y * pixels + xp] = color;
		fb[y * pixels + xp + 5] = color;
	}
	for (long long x = xp + 1; x < xp + 5; x++) {
		fb[14 * pixels + x] = color;
		fb[22 * pixels + x] = color;
	}
	fb[21 * pixels + xp + 4] = color;
	fb[22 * pixels + xp + 5] = color;
	fb[23 * pixels + xp + 6] = color;
	xp += 8;
}
extern "C" void printR(int* fb, long long pixels, long long color) {
	for (long long y = 14; y < 23; y++) {
		fb[y * pixels + xp] = color;
	}
	for (long long x = xp; x < xp + 5; x++) {
		fb[14 * pixels + x] = color;
		fb[18 * pixels + x] = color;
	}
	for (long long y = 15; y < 18; y++) {
		fb[y * pixels + xp + 5] = color;
	}
	fb[19 * pixels + xp + 1] = color;
	fb[20 * pixels + xp + 2] = color;
	fb[21 * pixels + xp + 3] = color;
	fb[22 * pixels + xp + 4] = color;
	fb[22 * pixels + xp + 5] = color;
	xp += 8;
}
extern "C" void printS(int* fb, long long pixels, long long color) {
	for (long long x = xp + 1; x < xp + 5; x++) {
		fb[14 * pixels + x] = color;
		fb[18 * pixels + x] = color;
		fb[22 * pixels + x] = color;
	}
	for (long long y = 15; y < 18; y++) {
		fb[y * pixels + xp] = color;
	}
	for (long long y = 19; y < 22; y++) {
		fb[y * pixels + xp + 5] = color;
	}
	xp += 8;
}
extern "C" void printT(int* fb, long long pixels, long long color) {
	for (long long x = xp; x < xp + 6; x++) {
		fb[14 * pixels + x] = color;
	}
	for (long long y = 15; y < 23; y++) {
		fb[y * pixels + xp + 2] = color;
	}
	xp += 8;
}
extern "C" void printU(int* fb, long long pixels, long long color) {
	for (long long y = 14; y < 22; y++) {
		fb[y * pixels + xp] = color;
		fb[y * pixels + xp + 5] = color;
	}
	for (long long x = xp + 1; x < xp + 5; x++) {
		fb[22 * pixels + x] = color;
	}
	xp += 8;
}
extern "C" void printV(int* fb, long long pixels, long long color) {
	for (long long y = 14; y < 18; y++) {
		fb[y * pixels + xp] = color;
		fb[y * pixels + xp + 5] = color;
	}
	for (long long y = 18; y < 21; y++) {
		fb[y * pixels + xp + 1] = color;
		fb[y * pixels + xp + 4] = color;
	}
	for (long long y = 21; y < 23; y++) {
		fb[y * pixels + xp + 2] = color;
		fb[y * pixels + xp + 3] = color;
	}
	xp += 8;
}
extern "C" void printW(int* fb, long long pixels, long long color) {
	for (long long y = 14; y < 19; y++) {
		fb[y * pixels + xp] = color;
		fb[y * pixels + xp + 5] = color;
	}
	for (long long y = 19; y < 23; y++) {
		fb[y * pixels + xp + 1] = color;
		fb[y * pixels + xp + 4] = color;
	}
	fb[18 * pixels + xp + 2] = color;
	fb[18 * pixels + xp + 3] = color;
	xp += 8;
}
extern "C" void printX(int* fb, long long pixels, long long color) {
	fb[14 * pixels + xp] = color;
	fb[14 * pixels + xp + 5] = color;
	fb[22 * pixels + xp] = color;
	fb[22 * pixels + xp + 5] = color;
	for (long long y = 15; y < 17; y++) {
		fb[y * pixels + xp + 1] = color;
		fb[y * pixels + xp + 4] = color;
	}
	for (long long y = 20; y < 22; y++) {
		fb[y * pixels + xp + 1] = color;
		fb[y * pixels + xp + 4] = color;
	}
	for (long long y = 17; y < 20; y++) {
		fb[y * pixels + xp + 2] = color;
		fb[y * pixels + xp + 3] = color;
	}
	xp += 8;
}
extern "C" void printY(int* fb, long long pixels, long long color) {
	fb[14 * pixels + xp] = color;
	for (long long y = 14; y < 16; y++) {
		fb[y * pixels + xp + 1] = color;
		fb[y * pixels + xp + 5] = color;
	}
	for (long long y = 16; y < 18; y++) {
		fb[y * pixels + xp + 2] = color;
		fb[y * pixels + xp + 4] = color;
	}
	for (long long y = 18; y < 23; y++) {
		fb[y * pixels + xp + 3] = color;
	}
	xp += 8;
}
extern "C" void printZ(int* fb, long long pixels, long long color) {
	for (long long x = xp; x < xp + 5; x++) {
		fb[14 * pixels + x] = color;
		fb[22 * pixels + x] = color;
	}
	fb[15 * pixels + xp + 4] = color;
	fb[16 * pixels + xp + 3] = color;
	fb[17 * pixels + xp + 2] = color;
	fb[18 * pixels + xp + 1] = color;
	fb[19 * pixels + xp] = color;
	fb[20 * pixels + xp] = color;
	fb[21 * pixels + xp] = color;
	xp += 8;
}