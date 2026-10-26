#include "Wooslib/printchar.h"

long long xp = 5;

extern "C" void printA(int* fb, long long pixels) {
	for (long long y = 15; y < 23; y++) {
		for (long long x = xp; x < xp+1; x++) {
			fb[y * pixels + x] = 0x00FFFFFF;
		}
	}
	for (long long y = 15; y < 23; y++) {
		for (long long x = xp + 5; x < xp+6; x++) {
			fb[y * pixels + x] = 0x00FFFFFF;
		}
	}
	for (long long y = 14; y < 15; y++) {
		for (long long x = xp + 1; x < xp+5; x++) {
			fb[y * pixels + x] = 0x00FFFFFF;
		}
	}
	for (long long y = 19; y < 20; y++) {
		for (long long x = xp; x < xp+5; x++) {
			fb[y * pixels + x] = 0x00FFFFFF;
		}
	}
	xp += 7;
}