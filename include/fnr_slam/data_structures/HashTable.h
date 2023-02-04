#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <iostream>
#include <cstring>
#include <cerrno>
#include <cstdint>

template <typename K, typename V>
class HashTable {
	
	private:
		size_t(*hash_func)(K key) = nullptr; // the hash function returns an integer index
		V *table = nullptr; // the table itself
		size_t table_size;

	public:
		HashTable(size_t size);
		~HashTable();
		void setHashFunction(size_t(*func_ptr)(K key)); // the hash function depends on the key type, must be implemented outside
		void set(K key, V value);
		V get(K key);
};

#endif
