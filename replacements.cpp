#include "replacements.h"

void random(Cache *cache, node *arr, DataBlock *block_used){
	int n = cache->num_blocks;
	int i;
	int random_idx;
	int counter = 0;
	node *curr = arr;	
}

void fifo(Cache *cache, DataBlock *arr, DataBlock *block_used){
	int n = cache->num_blocks;
	int i;
	for(i=0;i<n;i++){
		if(arr[i].block.used == false){
			arr[i].data = block_used->data;
		}
	}
}