#include "simple_search_engine.h"

void read_file(char* file_name, int index) {
	FILE* file;
	Element element;

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
		//char* word = malloc(sizeof(char));
		char* element_word;
		//fscanf(file, "%s", element.word);

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
				element_word = word;
				strcpy(element.word, element_word);
				strcpy(element.word, refine_word(element.word));	// 문장부호 제거 및 소문자로 변환
				//printf("element word: %s\n", element.word);
				insert_hash(element.word, element.doc.file_num, line_num); // 해시테이블에 저장
				n = 0;

			}
		} while (c != NULL);
		free(word);
	}
	fclose(file);
}