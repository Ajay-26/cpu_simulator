#include "replacements.h"

void random(Cache *cache, SmartList arr, DataBlock *block_used){
	if(arr->num_elements < cache->num_blocks){
		arr->locations[block_used] = new node<DataBlock*>;
		arr->locations[block_used]->next = nullptr;
		arr->locations[block_used]->prev = nullptr;
		arr->locations[block_used]->value = block_used;
		arr->tail->next = arr->locations[block_used];
		arr->locations[block_used]->prev = arr->tail;
		arr->tail = arr->locations[block_used];
		arr->num_elements++;
		return;
	}
	node<DataBlock*> curr = arr->head;
	int num = std::rand() % arr->num_elements;
	while(num > 0){
		curr = curr->next;
		num = num - 1;
	}
	arr->locations.erase(curr->value);
	curr->value = block_used;
	arr->locations[block_used] = curr;
	return;
}

void fifo(Cache *cache, DataBlock *arr, DataBlock *block_used){
	if(arr->num_elements < cache->num_blocks){
		arr->locations[block_used] = new node<DataBlock*>;
		arr->locations[block_used]->next = nullptr;
		arr->locations[block_used]->prev = nullptr;
		arr->locations[block_used]->value = block_used;
		arr->tail->next = arr->locations[block_used];
		arr->locations[block_used]->prev = arr->tail;
		arr->tail = arr->locations[block_used];
		arr->num_elements++;
		return;
	}
	if(arr->locations.find(block_used) == arr->locations.end()){
		arr->locations.erase(arr->tail->value);
		arr->tail->prev->next = nullptr;
		arr->tail->prev = nullptr;
		arr->locations[block_used] = new node<DataBlock*>;
		arr->locations[block_used]->prev = nullptr;
		arr->locations[block_used]->value = block_used;
		arr->locations[block_used]->next = arr->head;
		arr->head->prev = arr->locations[block_used];
		return;
	}else{
		return; //if it is already in the list do not change anything
	}

}

void lru(Cache *cache, DataBlock *arr, DataBlock *block_used){
	if(arr->num_elements < cache->num_blocks){
		arr->locations[block_used] = new node<DataBlock*>;
		arr->locations[block_used]->next = nullptr;
		arr->locations[block_used]->prev = nullptr;
		arr->locations[block_used]->value = block_used;
		arr->tail->next = arr->locations[block_used];
		arr->locations[block_used]->prev = arr->tail;
		arr->tail = arr->locations[block_used];
		arr->num_elements++;
		return;
	}
	if(arr->locations.find(block_used) == arr->locations.end()){
		arr->locations.erase(arr->tail->value);
		arr->tail->prev->next = nullptr;
		arr->tail->prev = nullptr;
		arr->locations[block_used] = new node<DataBlock*>;
		arr->locations[block_used]->prev = nullptr;
		arr->locations[block_used]->value = block_used;
		arr->locations[block_used]->next = arr->head;
		arr->head->prev = arr->locations[block_used];
		return;
	}else{
		node<DataBlock*> temp = arr->locations[block_used];
		node<DataBlock*> nxt = n->next;
		node<DataBlock*> prv = n->prev;
		if(prv != nullptr)		prv->next = nxt;
		if(nxt != nullptr)		nxt->prev = prv;
		node<DataBlock*> new_head = new node<DataBlock*>;
		new_head->prev = nullptr;
		new_head->next = arr->head;
		arr->locations[block_used] = new_head;
		arr->head->prev = new_head;
		arr->head = new_head;
		return;
	}
}