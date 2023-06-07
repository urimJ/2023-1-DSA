#include "simple_search_engine.h"

char* what_to_search() {

	char* user_input = ' ';
	char* word_to_search;
	int hash_value;
	
	printf("user input: ");
	scanf("%s", user_input);

	word_to_search = user_input;
	hash_value = hash(word_to_search);


	searching(user_input, hash_value);
}