#pragma once 

#include <string>

#include "address.h"
#include "datablock.h"
#include "replacements.h"
#include "smartlist.h"

class Cache{
public:
	int num_sets;
	int num_blocks;
	int associativity;
	SmartList<DataBlock*>* cache_arr; 
	cache_replacement_func *repl_func;
	Cache(int n_sets, int n_blocks, std::string replacement_policy, int k);

	byte get_byte(address addr);
	void set_byte(address addr, byte input_byte);

	DataBlock* get_datablock(address addr):
	void set_datablock(address addr, DataBlock block);
};