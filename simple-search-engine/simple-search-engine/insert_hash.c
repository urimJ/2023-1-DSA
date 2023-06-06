#include "simple_search_engine.h"

void insert_hash(char* word, int file_num, int n_row) {
	int hash_value = hash(word);
	int BSTkey = 0;
	struct Node* head_node;
	struct Node* new_node;

	if (hash_table[hash_value].word != NULL) {		// �ؽ� ����� �ش��ϴ� ���̺��� ����� ���
		//BST�� ��带 ���� ���� ����

		struct Node* new_node;

		hash_table[hash_value].key = hash_value + n_row;
		BSTkey = hash_value + n_row;
		//strcpy(hash_table[hash_value].word, word);	// �ش� �ܾ� ����
		//hash_table[hash_value].doc.file_num = file_num;
		//hash_table[hash_value].doc.sentence = sentence;

		head_node = createNode(BSTkey, word, file_num, n_row);
		hash_table[hash_value].node = head_node;


	}
	else {											// �ؽ� ����� �ش��ϴ� ���̺��� �̹� �� �ִ� ���
		BSTkey = hash_value + n_row;
		insertNode(hash_table[hash_value].node, BSTkey, word, file_num, n_row);
	}

}