#pragma once
#include "universal.h"

class address{
private:
	int memory_address; //32-bit address
	int tag_size;
	int offset_size;
	int index_size;

public:
	int get_tag();
	int get_offset();
	int get_index();
	address(int tag=22, int index=6, int offset=4);
};