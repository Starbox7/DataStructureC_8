#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct treeNode {
    int data;
    struct treeNode* left;
    struct treeNode* right;
}treeNode;

treeNode* makeRootNode(int data, treeNode* leftNode, treeNode* rightNode) {
    treeNode* root = (treeNode*)malloc(sizeof(treeNode));
    root->data = data;
    root->left = leftNode;
    root->right = rightNode;
    return root;
}

void preorder(treeNode* root) {
    if (root) {
        printf("%d  ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(treeNode* root) {
    if (root) {
        inorder(root->left);
        printf("%d  ", root->data);
        inorder(root->right);
    }
}

void postorder(treeNode* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d  ", root->data);
    }
}

void main() {
    printf("�й� : 18114847, �̸� : �����\n");
    printf("�ǽ� #8-1 ����Ʈ���� ��ȸ -> #8-3 �Լ� ����\n");

    treeNode* n7 = makeRootNode(1111, NULL, NULL);  //��� ������ �ݴ�
    treeNode* n6 = makeRootNode(113, NULL, NULL);
    treeNode* n5 = makeRootNode(112, NULL, NULL);
    treeNode* n4 = makeRootNode(111, n7, NULL);
    treeNode* n3 = makeRootNode(12, n5, n6);
    treeNode* n2 = makeRootNode(11, n4, NULL);
    treeNode* n1 = makeRootNode(1,n2, n3);

    printf("\n preorder : ");
    preorder(n1);

    printf("\n inorder : ");
    inorder(n1);

    printf("\n postorder : ");
    postorder(n1);
}