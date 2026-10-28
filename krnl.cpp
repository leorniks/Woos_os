#include "Wooslib/printchar.h"

extern "C" void setgdt();

extern "C" void _start(long long buffer, long long horizontal, long long vertical, long long pixels) {
	int* fb = (int*)buffer;

	setgdt();

	printA(fb, pixels, 0x00FFFFFF);
	printB(fb, pixels, 0x00FFFFFF);
	printC(fb, pixels, 0x00FFFFFF);
	printD(fb, pixels, 0x00FFFFFF);
	printE(fb, pixels, 0x00FFFFFF);
	printF(fb, pixels, 0x00FFFFFF);
	printG(fb, pixels, 0x00FFFFFF);
	printH(fb, pixels, 0x00FFFFFF);
	printI(fb, pixels, 0x00FFFFFF);
	printJ(fb, pixels, 0x00FFFFFF);
	printK(fb, pixels, 0x00FFFFFF);
	printL(fb, pixels, 0x00FFFFFF);
	printM(fb, pixels, 0x00FFFFFF);
	printN(fb, pixels, 0x00FFFFFF);
	printO(fb, pixels, 0x00FFFFFF);
	printP(fb, pixels, 0x00FFFFFF);
	printQ(fb, pixels, 0x00FFFFFF);
	printR(fb, pixels, 0x00FFFFFF);
	printS(fb, pixels, 0x00FFFFFF);
	printT(fb, pixels, 0x00FFFFFF);
	printU(fb, pixels, 0x00FFFFFF);
	printV(fb, pixels, 0x00FFFFFF);
	printW(fb, pixels, 0x00FFFFFF);
	printX(fb, pixels, 0x00FFFFFF);
	printY(fb, pixels, 0x00FFFFFF);
	printZ(fb, pixels, 0x00FFFFFF);

	while (1) {
		asm volatile("hlt");
	}
}