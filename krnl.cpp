#include "Wooslib/printchar.h"

extern "C" void setgdt();

extern "C" void _start(long long buffer, long long horizontal, long long vertical, long long pixels) {
	int* fb = (int*)buffer;

	printA(fb, pixels);
	printA(fb, pixels);

	setgdt();

	printA(fb, pixels);

	while (1) {
		asm volatile("hlt");
	}
}