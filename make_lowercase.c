#include "simple_search_engine.h"

char* make_lowercase(char* word) {

	char word_lowered[MAX_WORD_SIZE]; // Ư�����ڸ� ������ �ܾ ������ �迭
	int k = 0; // word_refined�� ���� �ε���

	for (int i = 0; i < MAX_WORD_SIZE; i++) {
		// �迭 �ʱ�ȭ
		word_lowered[i] = '\0';
	}

	// ��� ���� �ҹ��ڷ� �ٲٱ�
	int j = 0;
	while (word_lowered[j] != '\0') {
		word_lowered[j] = tolower(word_lowered[j]);
		j++;
	}

	return word_lowered;
}