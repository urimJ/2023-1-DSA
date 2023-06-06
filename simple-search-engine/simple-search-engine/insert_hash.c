#include "simple_search_engine.h"

void insert_hash(char* word, int file_num, int n_row) {
	int hash_value = hash(word);
	int BSTkey = 0;
	struct Node* head_node;


	if (hash_table[hash_value].word != NULL) {		// �ؽ� ����� �ش��ϴ� ���̺��� ����� ���

		//BST�� ��带 ���� ���� ����

		hash_table[hash_value].key = hash_value;
		BSTkey = hash_value + file_num;
		//strcpy(hash_table[hash_value].word, word);	// �ش� �ܾ� ����
		//hash_table[hash_value].doc.file_num = file_num;
		//hash_table[hash_value].doc.sentence = sentence;

		head_node = createNode(BSTkey, word, file_num, n_row);
		hash_table[hash_value].node = head_node;


	}
	else {							// �ؽ� ����� �ش��ϴ� ���̺��� �̹� �� �ִ� ���
		BSTkey = hash_value + n_row;
		insertNode(hash_table[hash_value].node, BSTkey, word, file_num, n_row);
	}
	for (int i = 0; i < TABLE_SIZE; i++) {
		total_num_of_indexed_words = 0;
		if (hash_table[i].node != NULL) {
			total_num_of_indexed_words++;
		}
	}


}