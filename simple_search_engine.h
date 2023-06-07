#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NUM 100
#define TABLE_SIZE 29989
#define MAX_WORD_SIZE 100 
#define SPACE " \"\t\n~!@#$%^&*()_+`1234567890-=,./<>?;':[]{}|"

//BST ��� ����ü
struct Node {
	int key;
	char* data;
	int file_num;
	int n_row;
	//char* sentence;
	struct Node* left;
	struct Node* right;
};

//�ܾ ���Ե� ���� ��ȣ�� ������ �����ϴ� ����ü
typedef struct Docs* Docs_pointer;
typedef struct {
	int file_num;
	//char* sentence;
	Docs_pointer docs_pointer;
}Docs;

//�ؽ� ���̺� ������ ����ü
typedef struct Element* Element_pointer;
typedef struct {
	int				key;
	//Word			word_original;			// ���� �ܾ�
	char			word[MAX_WORD_SIZE];	// ��� �ҹ��ڷ� �ٲ� �ܾ�
	//int			n_row;
	//Element_pointer link;
	Docs			doc;
	struct Node*	node;
}Element;


//Hash Table
Element hash_table[TABLE_SIZE];



//�Լ� ����
void fetch_file();
void read_file(char* file_name, int index);
char* refine_word(char* word); 
int hash(char* word);
void insert_hash(char* word, int file_num, int n_row);

struct Node* createNode(int key, char* data, int file_num, int n_row);
struct Node* insertNode(struct Node* root, int key, char* data, int file_num, int n_row);
struct Node* searchNode(struct Node* root, int key);
void inorderTraversal(struct Node* root);

char* what_to_search();
void search(struct Node* node);

//�� ����
int total_num_of_documents;
int total_num_of_indexed_words;
int total_number_of_comparison;
int num_comparison_search;

int file_row[1000][MAX_FILE_NUM];
