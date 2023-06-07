#include "simple_search_engine.h"

void insert_hash(char* word, int file_num, int n_row) {
	int hash_value = hash(word);
	int BSTkey = 0;
	total_number_of_comparison = 0;
	
	struct Node* root = (struct Node*)malloc(sizeof(struct Node));
	
	if(hash_table[hash_value].key==NULL){		// �ؽ� ����� �ش��ϴ� ���̺��� ����� ���
													
		hash_table[hash_value].key = hash_value;
		strcpy(hash_table[hash_value].word, word);
		
		BSTkey = hash_value + file_num + n_row;
		root = createNode(BSTkey, word, file_num, n_row);
		root = insertNode(root, BSTkey, word, file_num, n_row); //node ���� �� bst����
		
		hash_table[hash_value].node = root;

	}
	else if(hash_table[hash_value].key != NULL) {							// �ؽ� ����� �ش��ϴ� ���̺��� �̹� �� �ִ� ��� strlen(hash_table[hash_value].node->data) !=0
		if (strcmp(hash_table[hash_value].word, word) == 0) {// ������ �ܾ �̹� ����
			//chaining
			
			BSTkey = hash_value + file_num + n_row;
			root = createNode(BSTkey, word, file_num, n_row);
			root = insertNode(root, BSTkey, word, file_num, n_row); //node ���� �� bst����
			total_number_of_comparison++;
		}
		else if(strcmp(hash_table[hash_value].word, word) != 0) { // linear probing �ٸ� ĭ���� ����
		
			int i = hash_value;
			while (hash_table[i].key!=NULL) {	//���尡 ���ִ�->����ִ� ĭ�� �����ϸ� ���� strlen(hash_table[i].word) != 0
				i = (i + 1) % TABLE_SIZE;
				
			}
			hash_table[i].key = i;
			strcpy(hash_table[i].word, word);
			BSTkey = i + file_num + n_row;
			root = createNode(BSTkey, word, file_num, n_row);
			root = insertNode(root, BSTkey, word, file_num, n_row);
			hash_table[i].node = root;
			total_number_of_comparison++;
			
		}
		
	}
	
	

	

}