#include "simple_search_engine.h"

void show_hash() {
	
	
	for (int i = 0; i < TABLE_SIZE; i++) {
		int key = hash(hash_table[i].word);
		char* word = hash_table[i].word;
		printf("%d, %s", key, word);
	}


}