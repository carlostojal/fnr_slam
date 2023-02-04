#include <fnr_slam/data_structures/HashTable.h>

// initialize an hashtable with a size
template <typename K, typename V>
HashTable<K,V>::HashTable(size_t size) {
	// TODO: the size will be the largest prime number smaller than size
	this->table_size = size;
	if((table = malloc(this->table_size * sizeof(V))) == nullptr) {
		std::cerr << "Error allocating the hashtable: " << strerror(errno) << std::endl;
		return;
	}
}

// destroy the pointers allocated by the hashtable
template <typename K, typename V>
HashTable<K,V>::~HashTable() {
	// TODO
}

template <typename K, typename V>
void HashTable<K,V>::setHashFunction(size_t(*func_ptr)(K key)) {
	// TODO
}

template <typename K, typename V>
void HashTable<K,V>::set(K key, V value) {
	// TODO
}

template <typename K, typename V>
V HashTable<K,V>::get(K key) {
	// TODO
}


