#include "simple_search_engine.h"

void read_file(char* file_name, int index) {

	FILE* file;
	Word word_original;
	
	int line = 0;

	file = fopen( file_name, "r");

	while (1) {
		if (file == NULL)
		{
			printf("%s 화일 오픈 불가\n", file_name);    //화면에 오류 표시
			
			break;
		}
		fscanf(file, "%s ", word_original.word_original);
		if (fgetc(file) != '\n') {
			line++;
		}
		
		strcpy(word_original.word_original, refine_word(word_original.word_original)); // 단어만 저장
		strcpy(word_original.word_original, _strlwr(word_original.word_original)); // 소문자로 저장
		//hash_insert(element.word, element.doc.file_num, line); // 해시테이블에 저장
		printf("%s ", word_original.word_original);

		if (feof(file)) break;
	}
	fclose(file);

}