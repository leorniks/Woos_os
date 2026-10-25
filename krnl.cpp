extern "C" void _start(long long buffer, long long horizontal, long long vertical, long long pixels) {
	int* fb = (int*)buffer;

	for (long long y = 0; y < vertical; y++) {
		for (long long x = 0; x < horizontal / 3; x++) {
			fb[y * pixels + x] = 0xFE0000;
		}
	}
	for (long long y = 0; y < vertical; y++) {
		for (long long x = horizontal / 3; x < horizontal / 3 * 2; x++) {
			fb[y * pixels + x] = 0x0000FF;
		}
	}
	for (long long y = 0; y < vertical; y++) {
		for(long long x = horizontal / 3 * 2; x < horizontal; x++) {
			fb[y * pixels + x] = 0x02FF01;
		}
	}

	while (1) {
		asm volatile("hlt");
	}
}