#pragma once
#include "address.h"
#include "datablock.h"

class RAM{
public:
	int num_blocks;
	DataBlock *blocks;
	RAM(int num_blocks, int block_size);

	DataBlock* get_block(address addr);
	void set_block(address addr, DataBlock value);
}