#include "simple_search_engine.h"

void read_file(char* file_name, int index) {

	FILE* file;
	Word word_original;
	
	int line = 0;

	file = fopen( file_name, "r");

	while (1) {
		if (file == NULL)
		{
			printf("%s ȭ�� ���� �Ұ�\n", file_name);    //ȭ�鿡 ���� ǥ��
			
			break;
		}
		fscanf(file, "%s ", word_original.word_original);
		if (fgetc(file) != '\n') {
			line++;
		}
		
		strcpy(word_original.word_original, refine_word(word_original.word_original)); // �ܾ ����
		strcpy(word_original.word_original, _strlwr(word_original.word_original)); // �ҹ��ڷ� ����
		//hash_insert(element.word, element.doc.file_num, line); // �ؽ����̺� ����
		printf("%s ", word_original.word_original);

		if (feof(file)) break;
	}
	fclose(file);

}