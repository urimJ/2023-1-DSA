#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NUM 100
#define TABLE_SIZE 30000

//Hash Table
typedef struct Element* Element_pointer;
typedef struct {
	int            key[300];         // Ű ��
	char         word[300];         // ��� �ҹ��ڷ� �ٲ� �ܾ�
	char         word_original[300];   // ���� �ܾ�
	Element_pointer link;
	Docs         docs[MAX_FILE_NUM]; //�ܾ ���Ե� ������ �迭
}Element;

Element hash_table[TABLE_SIZE];

//���� �ܾ�� �����ϴ� ����ü
typedef struct {
	char word_original[300];
}Word;

//�ܾ ���Ե� ������ ��, ������ �����ϴ� ����ü
typedef struct {
	int file_num;
	int frequency;
	char sentence[10000];
}Docs;

// ���� ����


//�Լ� ����
void call_file();
void read_file(int file_index);



//
// 
// 
////��Ƚ���� �����ϴ� ����
//int num_comparison = 0;
//char file_name[50];
////�ߺ� ���ŵ� word�� ���� �� �����ϴ� ����
//int indexed_word = 0;
//typedef struct Element* Element_pointer;//�⺻������ ������ �о��, ������ ��ȣ, �ܾ��� ����, ���� �ܾ�, ������ �ܾ �����ϴ� ����ü
//typedef struct Element {
//   char word[50];
//   char originword[50];
//   int file_num;
//   int word_order;
//   Element_pointer link;
//}Element;
//Element hash_table[TABLE_SIZE];//�ؽ� ���̺�
//
//typedef struct Element2 {//���� �ܾ �����ϴ� ����ü
//   char word[50];
//}Element2;
//Element2 search_table[MAX_FILE_NUM][TABLE_SIZE];//�ش� �ܾ��� ������ ��ȣ, �ؽ��� �ܾ ����
//
//typedef struct Element3 {//���° ���Ͽ� � �ܾ ��� ������ �����ϴ� ����ü
//   int index;
//   int data;
//}Element3;
//Element3 sequence_array[MAX_FILE_NUM];
//int data_array[MAX_FILE_NUM];