#include "simple_search_engine.h"

void read_file(char* file_name, int index) {
	FILE* file;
	Element element;

	int line_num = 1;
	
	element.doc.file_num = index;
	file = fopen(file_name, "r");
	if (file == NULL)
	{
		printf("%s ���� ���� �Ұ�\n", file_name);    //ȭ�鿡 ���� ǥ��
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

				//�ܾ� ó��
				element_word = word;
				strcpy(element.word, element_word);
				strcpy(element.word, refine_word(element.word));	// �����ȣ ���� �� �ҹ��ڷ� ��ȯ
				//printf("element word: %s\n", element.word);
				insert_hash(element.word, element.doc.file_num, line_num); // �ؽ����̺� ����
				n = 0;

			}
		} while (c != NULL);
		free(word);
	}
	fclose(file);
}