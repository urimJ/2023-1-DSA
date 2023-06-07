#include "simple_search_engine.h"

void insert_hash(char* word, int file_num, int n_row) {
	int hash_value = hash(word);
	int BSTkey = 0;
	
	struct Node* root = (struct Node*)malloc(sizeof(struct Node));
	
	if(hash_table[hash_value].key == NULL){		// 해시 밸류에 해당하는 테이블이 비었을 경우
													
		//BST의 노드를 만들어서 값을 저장

		hash_table[hash_value].key = hash_value;
		BSTkey = hash_value + file_num + n_row;
		root = createNode(BSTkey, word, file_num, n_row);
		root = insertNode(root, BSTkey, word, file_num, n_row); //headnode 생성 후 bst삽입
		hash_table[hash_value].node = root;

	}
	else if(hash_table[hash_value].key != NULL) {							// 해시 밸류에 해당하는 테이블이 이미 차 있는 경우
		if (strcmp(hash_table[hash_value].word, word) == 0) {// 들어가려는 단어가 이미 있음
			//chaining
			BSTkey = hash_value + file_num + n_row;
			root = createNode(BSTkey, word, file_num, n_row);
			root = insertNode(root, BSTkey, word, file_num, n_row);
			hash_table[hash_value].node = root;

		}
		else if(strcmp(hash_table[hash_value].word, word) != 0) { // linear probing 다른 칸으로 간다
		
			int i = hash_value;
			while (strlen(hash_table[i].word) != 0) {	//워드가 차있다->비어있는 칸에 도달하면 종료
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