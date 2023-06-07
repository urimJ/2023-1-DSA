#include "simple_search_engine.h"

void searching(char* user_input, int hash_value) {
    char* item = user_input;
    int i = hash_value;
    int key = 0;
    int file_num = 0;
    int n_row = 0;
    int num_word_of_doc = 0;
    FILE* file;
    char* file_name = NULL;
    int file_row[1000][MAX_FILE_NUM] = { 0, };

    while (hash_table[hash_value].key != NULL) {
        if (item == hash_table[hash_value].node->data) {
            inorderTraversal(hash_table[hash_value].node);
            for (int i = 1; i <= MAX_FILE_NUM; i++) {
                for (int j = 1; j <= 1000; j++) {
                    num_word_of_doc += file_row[j][i];
                    sprintf(file_name, "doc%03d.txt", i);
                    file = fopen(file_name, "r");
             
                }
                printf("%d번째 문서의 검색 단어 수: %d\n", i, num_word_of_doc);
            }
            
            //printf("<doc%03d.txt>",node->file_num);
            //printf("(%s: 개수)", root->data);
            return;
        }
        else if (item != hash_table[hash_value].node->data) {
            while (hash_table[hash_value].key != NULL) {
                i = (i + 1) % TABLE_SIZE;
            }
            if (item == hash_table[hash_value].node->data) {
                inorderTraversal(hash_table[hash_value].node);
                for (int i = 1; i <= MAX_FILE_NUM; i++) {
                    for (int j = 1; j <= 1000; j++) {
                        num_word_of_doc += file_row[j][i];
                        sprintf(file_name, "doc%03d.txt", i);
                        file = fopen(file_name, "r");

                    }
                    printf("%d번째 문서의 검색 단어 수: %d\n", i, num_word_of_doc);
                }
            }
        }
    }
	


    //printf("\nSearch word :");
    //if (scanf("%s", word) != 1) {
    //    printf("Error reading input.\n");
    //}
    ////search();

    //printf("\nDocument name: ");
    //scanf("%s", filename);
    //printf("\nSearch word: ");
    //scanf("%s", search_word);
    ////search_result();

}