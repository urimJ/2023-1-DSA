#include "simple_search_engine.h"

char* make_lowercase(char* word) {

	char word_lowered[MAX_WORD_SIZE]; // 특수문자를 제거한 단어를 저장할 배열
	int k = 0; // word_refined의 현재 인덱스

	for (int i = 0; i < MAX_WORD_SIZE; i++) {
		// 배열 초기화
		word_lowered[i] = '\0';
	}

	// 모든 문자 소문자로 바꾸기
	int j = 0;
	while (word_lowered[j] != '\0') {
		word_lowered[j] = tolower(word_lowered[j]);
		j++;
	}

	return word_lowered;
}