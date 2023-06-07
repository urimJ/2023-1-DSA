#include "simple_search_engine.h"

void insert_hash(char* word, int file_num, int n_row) {
	int hash_value = hash(word);
	int BSTkey = 0;
	total_number_of_comparison = 0;
	
	struct Node* root = (struct Node*)malloc(sizeof(struct Node));
	
	if(hash_table[hash_value].key==NULL){		// 해시 밸류에 해당하는 테이블이 비었을 경우
													
		hash_table[hash_value].key = hash_value;
		strcpy(hash_table[hash_value].word, word);
		
		BSTkey = hash_value + file_num + n_row;
		root = createNode(BSTkey, word, file_num, n_row);
		root = insertNode(root, BSTkey, word, file_num, n_row); //node 생성 후 bst삽입
		
		hash_table[hash_value].node = root;

	}
	else if(hash_table[hash_value].key != NULL) {							// 해시 밸류에 해당하는 테이블이 이미 차 있는 경우 strlen(hash_table[hash_value].node->data) !=0
		if (strcmp(hash_table[hash_value].word, word) == 0) {// 들어가려는 단어가 이미 있음
			//chaining
			
			BSTkey = hash_value + file_num + n_row;
			root = createNode(BSTkey, word, file_num, n_row);
			root = insertNode(root, BSTkey, word, file_num, n_row); //node 생성 후 bst삽입
			total_number_of_comparison++;
		}
		else if(strcmp(hash_table[hash_value].word, word) != 0) { // linear probing 다른 칸으로 간다
		
			int i = hash_value;
			while (hash_table[i].key!=NULL) {	//워드가 차있다->비어있는 칸에 도달하면 종료 strlen(hash_table[i].word) != 0
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