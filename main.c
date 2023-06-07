#include "simple_search_engine.h"

void print_indexing_result() // 인덱싱의 결과를 출력하는 함수
{
	printf(" ********************* INDEXING RESULT *********************\n");
	printf(" Total number of documents: %d\n", total_num_of_documents); // 읽은 documents의 수를 출력
	printf(" Total number of indexed words: %d\n", total_num_of_indexed_words); // 정상적으로 인덱싱한 word의 수를 출력
	printf(" Total number of comparison: %d\n", total_number_of_comparison); // strcmp를 행한 횟수를 출력
	printf(" ***********************************************************\n");
}


int main() {
	//fetch_file();
	
	read_file("doc001.txt",1);
	for (int i = 0; i < TABLE_SIZE; i++) {
		if (hash_table[i].key != NULL) {
			printf("해시테이블: %s\n", hash_table[i].word);
		}
	}
	print_indexing_result();
	what_to_search();


	return 0;
}
