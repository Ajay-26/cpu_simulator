#include "datablock.h"

DataBlock::DataBlock(int s){
	this->size = s;
	this->data = new byte[this->size];
	this->used = false;
}