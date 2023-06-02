#include "simple_search_engine.h"

char* refine_word(char* word) {
	char word_refined[MAX_WORD_SIZE]; // 특수문자를 제거한 단어를 저장할 배열
	int k = 0; // word_refined의 현재 인덱스

	for (int i = 0; i < MAX_WORD_SIZE; i++) {
		// 배열 초기화
		word_refined[i] = "";
	}

	for (int i = 0; word[i]!='\0'; i++) {
		if (word[i] >= 65 && word[i] <= 90 || word[i] >= 97 && word[i] <= 122) {
			word_refined[k++] = word[i];
		}
	}

	return word_refined;

}