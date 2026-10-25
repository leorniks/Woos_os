//(c) copyright 2026 leorniks. Protected by GPL license v3.

//Mr Meeseeks write an bootloader for me.

#include <efi.h>

extern "C" EFI_STATUS EFIAPI efi_main(EFI_HANDLE ih, EFI_SYSTEM_TABLE* st) {
	EFI_STATUS eh;
	EFI_BOOT_SERVICES* bs = st->BootServices;
	EFI_RUNTIME_SERVICES* rt = st->RuntimeServices;

	st->ConOut->ClearScreen(st->ConOut);
	st->ConOut->OutputString(st->ConOut, L"\r\nWelcome to Woos_os!\r\n");

	//STACK
	EFI_PHYSICAL_ADDRESS stack_begin;
	eh = bs->AllocatePages(AllocateAnyPages, EfiLoaderData, 4, &stack_begin);
	if (EFI_ERROR(eh)) {
		st->ConOut->OutputString(st->ConOut, L"Cant allocate, rebooting in 3 seconds.\r\n");
		bs->Stall(3000000);
		rs->ResetSystem(EfiResetCold, EFI_SUCCESS, 0, NULL);
	}

	UINT64 stack_end = stack_begin + 16384;

	//KERNELREAD
	EFI_GUID esfsp = EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_GUID;
	UINT64 handle_count;
	EFI_HANDLE* handle_buffer;

	eh = bs->LocateHandleBuffer(ByProtocol, &esfsp, NULL, &handle_count, &handle_buffer);
	if (EFI_ERROR(eh)) {
		st->ConOut->OutputString(st->ConOut, L"Cant locate handle buffer, rebooting in 3 seconds.\r\n");
		bs->Stall(3000000);
		rs->ResetSystem(EfiResetCold, EFI_SUCCESS, 0, NULL);
	}

	EFI_SIMPLE_FILE_SYSTEM_PROTOCOL* fs;
	EFI_FILE* root, * file;
	UINT64 size = 0x10000;

	EFI_PHYSICAL_ADDRESS kernelbase;
	eh = bs->AllocatePages(AllocateAnyPages, EfiLoaderCode, 16, &kernelbase);
	if (EFI_ERROR(eh)) {
		st->ConOut->OutputString(st->ConOut, L"Cant allocate, rebooting in 3 seconds.\r\n");
		bs->Stall(3000000);
		rs->ResetSystem(EfiResetCold, EFI_SUCCESS, 0, NULL);
	}

	for (UINT64 i = 0; i < handle_count; i++) {
		eh = bs->OpenProtocol(handle_buffer[i], &esfsp, (void**)&fs, ih, NULL, EFI_OPEN_PROTOCOL_BY_HANDLE_PROTOCOL);
		if (EFI_ERROR(eh)) {
			continue;
		}
		eh = fs->OpenVolume(fs, &root);
		if (EFI_ERROR(eh)) {
			continue;
		}
		eh = root->Open(root, &file, L"krnl.bin", EFI_FILE_MODE_READ, 0);
		if (EFI_ERROR(eh)) {
			root->Close(root);
			continue;
		}
		eh = file->Read(file, &size, (void*)kernelbase);
		if (EFI_ERROR(eh)) {
			root->Close(root);
			file->Close(file);
			continue;
		}
		file->Close(file);
		root->Close(root);

		break;
	}

	//GOP
	EFI_GUID gopg = EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID;
	EFI_GRAPHICS_OUTPUT_PROTOCOL* gop;
	EFI_GRAPHICS_OUTPUT_MODE_INFORMATION* info;
	UINT64 infosize;

	eh = bs->LocateProtocol(&gopg, NULL, (void**)&gop);
	if (EFI_ERROR(eh)) {
		st->ConOut->OutputString(st->ConOut, L"Can't locate EFI_GRAPHICS_OUTPUT_PROTOCOL, please shutdown your pc\r\n");
		while (1) {
			asm volatile("hlt");
		}
	}

	for (UINT64 i = 0; i < gop->Mode->MaxMode; i++) {
		gop->QueryMode(gop, i, &infosize, &info);
		if (info->HorizontalResolution == 800 && info->VerticalResolution == 600) {
			gop->SetMode(gop, i);
			break;
		}
	}
	if (gop->Mode->Info->HorizontalResolution != 800 || gop->Mode->Info->VerticalResolution != 600) {
		gop->SetMode(gop, 0);
	}

	UINT64 buffer = gop->Mode->FrameBufferBase;
	UINT64 horizontal = gop->Mode->Info->HorizontalResolution;
	UINT64 vertical = gop->Mode->Info->VerticalResolution;
	UINT64 pixels = gop->Mode->Info->PixelsPerScanLine;

	//EXITBOOTSERVICES
	UINT64 mms = 0;
	EFI_MEMORY_DESCRIPTOR* mm = 0;
	UINT64 mk = 0;
	UINT64 ds = 0;
	UINT32 dv = 0;

	bs->GetMemoryMap(&mms, mm, NULL, &ds, NULL);
	mms += 2 * ds;
	bs->AllocatePool(EfiLoaderData, mms, (void**)&mm);
	bs->GetMemoryMap(&mms, mm, &mk, &ds, &dv);

	bs->ExitBootServices(ih, mk);

	asm volatile ("cli");
	asm volatile ("mov %0, %%rsp" :: "r"(stack_end));

	((void(*)(UINT64, UINT64, UINT64, UINT64))kernelbase)(buffer, horizontal, vertical, pixels);

	while (1) {
		asm volatile("hlt");
	}

	return EFI_SUCCESS;
}