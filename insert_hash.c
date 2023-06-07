#include "simple_search_engine.h"

void insert_hash(char* word, int file_num, int n_row) {
	int hash_value = hash(word);
	int BSTkey = 0;
	
	struct Node* root = (struct Node*)malloc(sizeof(struct Node));
	
	if(hash_table[hash_value].key == NULL){		// �ؽ� ����� �ش��ϴ� ���̺��� ����� ���
													
		//BST�� ��带 ���� ���� ����

		hash_table[hash_value].key = hash_value;
		BSTkey = hash_value + file_num + n_row;
		root = createNode(BSTkey, word, file_num, n_row);
		root = insertNode(root, BSTkey, word, file_num, n_row); //headnode ���� �� bst����
		hash_table[hash_value].node = root;

	}
	else if(hash_table[hash_value].key != NULL) {							// �ؽ� ����� �ش��ϴ� ���̺��� �̹� �� �ִ� ���
		if (strcmp(hash_table[hash_value].word, word) == 0) {// ������ �ܾ �̹� ����
			//chaining
			BSTkey = hash_value + file_num + n_row;
			root = createNode(BSTkey, word, file_num, n_row);
			root = insertNode(root, BSTkey, word, file_num, n_row);
			hash_table[hash_value].node = root;

		}
		else if(strcmp(hash_table[hash_value].word, word) != 0) { // linear probing �ٸ� ĭ���� ����
		
			int i = hash_value;
			while (strlen(hash_table[i].word) != 0) {	//���尡 ���ִ�->����ִ� ĭ�� �����ϸ� ����
				i = (i + 1) % TABLE_SIZE;
				
			}
			BSTkey = i + file_num + n_row;
			root = createNode(BSTkey, word, file_num, n_row);
			root = insertNode(root, BSTkey, word, file_num, n_row);
			hash_table[i].node = root;
			
		}
		//printf("%d %s", hash_value, hash_table[hash_value].node->data);
	}

	for (int i = 0; i < TABLE_SIZE; i++) {
		total_num_of_indexed_words = 0;
		if (hash_table[i].node != NULL) {
			total_num_of_indexed_words++;
		}
	}

}