#ifndef ARMJIT_MEMORY
#define ARMJIT_MEMORY

#include "types.h"

#include "ARM.h"

namespace ARMJIT_Memory
{

extern void* FastMem9Start;
extern void* FastMem7Start;

void Init();
void DeInit();

void Reset();

enum
{
	memregion_Other = 0,
	memregion_ITCM,
	memregion_DTCM,
	memregion_BIOS9,
	memregion_MainRAM,
	memregion_SharedWRAM,
	memregion_IO9,
	memregion_VRAM,
	memregion_BIOS7,
	memregion_WRAM7,
	memregion_IO7,
	memregion_Wifi,
	memregion_VWRAM,

	// DSi
	memregion_BIOS9DSi,
	memregion_BIOS7DSi,
	memregion_NewSharedWRAM_A,
	memregion_NewSharedWRAM_B,
	memregion_NewSharedWRAM_C,

	memregions_Count
};

int ClassifyAddress9(u32 addr);
int ClassifyAddress7(u32 addr);

bool GetMirrorLocation(int region, u32 num, u32 addr, u32& memoryOffset, u32& mirrorStart, u32& mirrorSize);
u32 LocaliseAddress(int region, u32 num, u32 addr);

bool IsFastmemCompatible(int region);

void RemapDTCM(u32 newBase, u32 newSize);
void RemapSWRAM();
void RemapNWRAM(int num);

void SetCodeProtection(int region, u32 offset, bool protect);

void* GetFuncForAddr(ARM* cpu, u32 addr, bool store, int size);

}

#endif