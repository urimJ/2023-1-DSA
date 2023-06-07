#include "simple_search_engine.h"

void print_indexing_result() // �ε����� ����� ����ϴ� �Լ�
{
	printf(" ********************* INDEXING RESULT *********************\n");
	printf(" Total number of documents: %d\n", total_num_of_documents); // ���� documents�� ���� ���
	printf(" Total number of indexed words: %d\n", total_num_of_indexed_words); // ���������� �ε����� word�� ���� ���
	printf(" Total number of comparison: %d\n", total_number_of_comparison); // strcmp�� ���� Ƚ���� ���
	printf(" ***********************************************************\n");
}


int main() {
	//fetch_file();
	
	read_file("doc001.txt",1);
	for (int i = 0; i < TABLE_SIZE; i++) {
		if (hash_table[i].key != NULL) {
			printf("�ؽ����̺�: %s\n", hash_table[i].word);
		}
	}
	print_indexing_result();
	what_to_search();


	return 0;
}
