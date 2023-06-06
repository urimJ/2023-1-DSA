#include "simple_search_engine.h"

// ���ο� ��带 �����ϴ� �Լ�
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

// ���� �˻� Ʈ���� ��带 �����ϴ� �Լ�
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

// ���� �˻� Ʈ������ Ư�� key ���� ���� ��带 Ž���ϴ� �Լ�
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

// ���� �˻� Ʈ���� ���� ��ȸ�ϴ� �Լ�
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("Key: %d, Data: %s\n", root->key, root->data);
        inorderTraversal(root->right);
    }
}