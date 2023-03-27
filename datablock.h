#pragma once
#include "universal.h"
class DataBlock{
public:	
	int size;
	byte *data;
	bool used;

	DataBlock(int s);
}