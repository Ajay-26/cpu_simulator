#pragma once
#include "address.h"
#include "datablock.h"
#include <cstdlib>
#include <cstdio>

typedef (void)*cache_replacement_func(Cache*, DataBlock *, DataBlock *);

struct node{
	DataBlock block;
	node *next;
};

void random(Cache *cache, node *arr, DataBlock *block_used);

void fifo(Cache *cache, node *arr, DataBlock *block_used);

void lru(Cache *cache, node *arr, DataBlock *block_used);