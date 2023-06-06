#include "simple_search_engine.h"

// 새로운 노드를 생성하는 함수
struct Node* createNode(int key, char* data, int file_num, int n_row) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->data = data;
    newNode->file_num = file_num;
    newNode->n_row = n_row;

    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// 이진 검색 트리에 노드를 삽입하는 함수
struct Node* insertNode(struct Node* root, int key, char* data, int file_num, int n_row) {
    if (root == NULL) {
        return createNode(key, data, file_num, n_row);
    }

    if (key < root->key) {
        root->left = insertNode(root->left, key, data, file_num, n_row);
    }
    else if (key > root->key) {
        root->right = insertNode(root->right, key, data, file_num, n_row);
    }

    return root;
}

// 이진 검색 트리에서 특정 key 값을 가진 노드를 탐색하는 함수
struct Node* searchNode(struct Node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }

    if (key < root->key) {
        return searchNode(root->left, key);
    }
    else {
        return searchNode(root->right, key);
    }
}

// 이진 검색 트리를 중위 순회하는 함수
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("Key: %d, Data: %s\n", root->key, root->data);
        inorderTraversal(root->right);
    }
}