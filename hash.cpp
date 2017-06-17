#include "hash.h"

HashTable::HashTable(){
	for(int i = 0; i < kHashTableSize; ++i) data_[i] = 0;
}

void* HashTable::find(const char* key){
	/*first check if an empty string*/
	if(key == 0) return 0;
	
	unsigned long h = 0;
	
	for(int i = 0; key[i]; ++i){
		h = (h << 8) + (h >> (sizeof(h)*8 - 8)) + key[i];
	}
	return data_[h % kHashTableSize];
}

void HashTable::add(const char* key, void* data){
	unsigned long h = 0;
	
	for(int i = 0; key[i]; ++i){
		h = (h << 8) + (h >> (sizeof(h)*8 - 8)) + key[i];
	}
	
	data_[h % kHashTableSize] = data;
}

unsigned int HashTable::hash(const char* key){
	unsigned long h = 0;
	
	for(int i = 0; key[i]; ++i){
		h = (h << 8) + (h >> (sizeof(h)*8 - 8)) + key[i];
	}
	return h % kHashTableSize;
}