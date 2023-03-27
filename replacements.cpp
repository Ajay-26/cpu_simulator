#include "replacements.h"

void random(Cache *cache, DataBlock *arr, DataBlock *block_used){
	int n = cache->num_blocks;
	int i;
	int random_idx;
	DataBlock tmp;
	for(i=0;i<n;i++){
		if(arr[i].used == false){
			arr[i].data = block_used->data;
			return;
		}
	}
	for(i=0;i<n;i++){
		random_idx = rand()%n;
		tmp = arr[i];
		arr[i] = arr[random_idx];
		arr[random_idx] = tmp;
	}
	return;
}

void fifo(Cache *cache, DataBlock *arr, DataBlock *block_used){
	int n = cache->num_blocks;
	int i;
	for(i=0;i<n;i++){
		if(arr[i].used == false){
			return;
		}
	}
}