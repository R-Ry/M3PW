#ifndef HASH
#define HASH

const unsigned int kHashTableSize = 5087;

class HashTable{
private:
	void* data_[kHashTableSize];
public:
	/*default constructor*/
	HashTable();
	
	void* find(const char* key);
	void add(const char* key, void* data);
	unsigned int hash(const char* key);
};

#endif
