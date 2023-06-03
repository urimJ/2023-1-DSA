#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NUM 100
#define TABLE_SIZE 30000

//Hash Table
typedef struct Element* Element_pointer;
typedef struct {
	int            key[300];         // 키 값
	char         word[300];         // 모두 소문자로 바꾼 단어
	char         word_original[300];   // 원래 단어
	Element_pointer link;
	Docs         docs[MAX_FILE_NUM]; //단어가 포함된 파일의 배열
}Element;

Element hash_table[TABLE_SIZE];

//원본 단어만을 저장하는 구조체
typedef struct {
	char word_original[300];
}Word;

//단어가 포함된 문서와 빈도, 문장을 포함하는 구조체
typedef struct {
	int file_num;
	int frequency;
	char sentence[10000];
}Docs;

// 파일 관리


//함수 선언
void call_file();
void read_file(int file_index);



//
// 
// 
////비교횟수를 저장하는 변수
//int num_comparison = 0;
//char file_name[50];
////중복 제거된 word의 개수 를 저장하는 변수
//int indexed_word = 0;
//typedef struct Element* Element_pointer;//기본적으로 파일을 읽어와, 파일의 번호, 단어의 순서, 원본 단어, 수정된 단어를 저장하는 구조체
//typedef struct Element {
//   char word[50];
//   char originword[50];
//   int file_num;
//   int word_order;
//   Element_pointer link;
//}Element;
//Element hash_table[TABLE_SIZE];//해시 테이블
//
//typedef struct Element2 {//원본 단어만 저장하는 구조체
//   char word[50];
//}Element2;
//Element2 search_table[MAX_FILE_NUM][TABLE_SIZE];//해당 단어의 파일의 번호, 해쉬에 단어를 저장
//
//typedef struct Element3 {//몇번째 파일에 어떤 단어가 몇번 들어가는지 저장하는 구조체
//   int index;
//   int data;
//}Element3;
//Element3 sequence_array[MAX_FILE_NUM];
//int data_array[MAX_FILE_NUM];