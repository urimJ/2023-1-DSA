#include "simple_search_engine.h"

void read_file(char* file_name, int index) {

	FILE* file;
	Element element;
	
	int line = 0;

	file = fopen(file_name, "r");

	element.doc.file_num = index;

	while (1) {
		fscanf(file, "%s ", element.word_original);
		if (fgetc(file) != '\n') {
			line++;
		}
		
		strcpy(element.word_original, refine_word(element.word_original)); // 단어만 저장
		strcpy(element.word_original, _strlwr(element.word)); // 소문자로 저장
		//hash_insert(element.word, element.doc.file_num, line); // 해시테이블에 저장
		printf("%s ", element.word);

		if (feof(file)) break;
	}
	fclose(file);

}