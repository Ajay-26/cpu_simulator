#include "ram.h"

RAM::RAM(int num_blocks){
	this->num_blocks = num_blocks;
	this->blocks = new DataBlocks(block_size)[this->num_blocks];
}

DataBlock* RAM::get_block(address addr){
	return this->blocks + addr;
}

void RAM::set_block(address addr, DataBlock value){
	this->blocks[addr].size = value.size;
	this->blocks[addr].data = value.data;
	return;
}