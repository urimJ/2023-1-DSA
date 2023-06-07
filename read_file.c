#include "simple_search_engine.h"

void read_file(char* file_name, int index) {
	FILE* file;
	Element element;
	element.key = 0;
	element.word[MAX_WORD_SIZE]=NULL;
	element.doc.docs_pointer = NULL;
	element.doc.file_num = 0;


	int line_num = 1;
	
	element.doc.file_num = index;
	file = fopen(file_name, "r");
	if (file == NULL)
	{
		printf("%s 파일 오픈 불가\n", file_name);    //화면에 오류 표시
		return;
	}

	while (!feof(file)) {
		char c;
		int n = 0;
		char* word = malloc(sizeof(char));
		char* element_word = malloc(sizeof(char));
		

		do {
			c = fgetc(file);

			if (c == '\n') {
				line_num++;
				n--;
			}
			*(word + n) = c;
			n++;

			if (c == ' ') {
				*(word + n - 1) = '\0';

				//단어 처리
				if (*(word) != '\0' &&*(word)!='\n') {
					element_word = word;
					word = malloc(sizeof(char));
					strcpy(element.word, element_word);
					strcpy(element.word, refine_word(element.word));	// 문장부호 제거 및 소문자로 변환
					//printf("element word: %s\n", element.word);
					insert_hash(element.word, element.doc.file_num, line_num); // 해시테이블에 저장
					
				}
				

				n = 0;
				
				if (c < n) {
					break;
				}
				
			
			}
			else if (c == -1) {

				*(word + n-1) = '\0';
				//단어 처리
				if (*(word) != '\0' && *(word) != '\n') {
					element_word = word;
					word = malloc(sizeof(char));
					strcpy(element.word, element_word);
					strcpy(element.word, refine_word(element.word));	// 문장부호 제거 및 소문자로 변환
					//printf("element word: %s\n", element.word);
					insert_hash(element.word, element.doc.file_num, line_num); // 해시테이블에 저장

				}



				n = 0;


				if (c < n) {
					break;
				}
			}
			else if (c == '\n') {

				*(word + n - 1) = '\0';
				//단어 처리
				if (*(word) != '\0' && *(word) != '\n') {
					element_word = word;
					word = malloc(sizeof(char));
					strcpy(element.word, element_word);
					strcpy(element.word, refine_word(element.word));	// 문장부호 제거 및 소문자로 변환
					//printf("element word: %s\n", element.word);
					insert_hash(element.word, element.doc.file_num, line_num); // 해시테이블에 저장

				}



				n = 0;


				if (c < n) {
					break;
				}
			}
				
		} while (*(word + n + 1) != ' ');	//

			//free(word);
			//free(element_word);
		break;
	}
	

	total_num_of_indexed_words = 0;
	for (int i = 0; i < TABLE_SIZE; i++) {

		if (hash_table[i].key != NULL) {
			total_num_of_indexed_words++;
		}
	}



	fclose(file);
	
}