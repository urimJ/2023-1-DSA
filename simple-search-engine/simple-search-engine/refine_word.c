#include "simple_search_engine.h"

char* refine_word(char* word) {
	char word_refined[MAX_WORD_SIZE]; // Ư�����ڸ� ������ �ܾ ������ �迭
	int k = 0; // word_refined�� ���� �ε���

	for (int i = 0; i < MAX_WORD_SIZE; i++) {
		// �迭 �ʱ�ȭ
		word_refined[i] = "";
	}

	for (int i = 0; word[i]!='\0'; i++) {
		if (word[i] >= 65 && word[i] <= 90 || word[i] >= 97 && word[i] <= 122) {
			word_refined[k++] = word[i];
		}
	}

	return word_refined;

}