#include "address.h"

address::address(int tag,int index, int offset){
	this->tag_size = tag;
	this->index_size = index;
	this->offset_size = offset;
}

int address::get_tag(){
	return this->address >> (this->index_size + this->offset_size);
}

int address::get_index(){
	return (this->address >> this->offset_size) & ((1 << this->index_size) - 1);
}

this address::get_offset(){
	return (this->address) & ((1 << this->offset_size) - 1);
}