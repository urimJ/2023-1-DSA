#include "simple_search_engine.h"

char* refine_word(char* word) {
	
	char word_refined[MAX_WORD_SIZE]; // Ư�����ڸ� ������ �ܾ ������ �迭
	int k = 0; // word_refined�� ���� �ε���

	for (int i = 0; i < MAX_WORD_SIZE; i++) {
		// �迭 �ʱ�ȭ
		word_refined[i] = '\0';
	}
	// ���� ��ȣ ����
	for (int i = 0; i< word[i]; i++) {
		if (word[i] >= 65 && word[i] <= 90 || word[i] >= 97 && word[i] <= 122) {
			word_refined[k++] = word[i];
		}
	}
	
	// ��� ���� �ҹ��ڷ� �ٲٱ�
	int j = 0;
	while (word_refined[j] != '\0') {
		word_refined[j] = tolower(word_refined[j]);
		j++;
	}
	
	return word_refined;

}
