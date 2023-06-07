#include "simple_search_engine.h"

char* refine_word(char* word) {
	
	char word_refined[MAX_WORD_SIZE]; // 특수문자를 제거한 단어를 저장할 배열
	int k = 0; // word_refined의 현재 인덱스

	for (int i = 0; i < MAX_WORD_SIZE; i++) {
		// 배열 초기화
		word_refined[i] = '\0';
	}
	// 문장 부호 제거
	for (int i = 0; i< word[i]; i++) {
		if (word[i] >= 65 && word[i] <= 90 || word[i] >= 97 && word[i] <= 122) {
			word_refined[k++] = word[i];
		}
	}
	
	// 모든 문자 소문자로 바꾸기
	int j = 0;
	while (word_refined[j] != '\0') {
		word_refined[j] = tolower(word_refined[j]);
		j++;
	}
	
	return word_refined;

}
