#include "simple_search_engine.h"

char* what_to_search() {

	char* user_input = ' ';
	char* word_to_search;
	int hash_value;

	printf("Total number of documents : %d\n", total_num_of_documents);
	printf("Total number of indexed words : %d\n", total_num_of_indexed_words);
	printf("Total number of comparison : \n");
	
	printf("user input: ");
	scanf("%s", user_input);

	word_to_search = user_input;
	hash_value = hash(word_to_search);


	search(hash_table[hash_value].node);
}