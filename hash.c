#include "simple_search_engine.h"

int hash(char* word) {
	
	unsigned long long int value = 0;
	int length = strlen(word);
	value = 19991*(unsigned long long int)word[0]+19997*(unsigned long long int)word[length-2] - ((unsigned long long int)word[0]+ (unsigned long long int)word[length-2]);

	return (value % TABLE_SIZE);
}