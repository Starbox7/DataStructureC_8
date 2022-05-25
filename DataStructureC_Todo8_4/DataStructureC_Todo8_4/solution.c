#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
	char key;
	struct treeNode* left;
	struct treeNode* right;
}treeNode;

treeNode* insertKey(treeNode *p, char x) 
{
	treeNode *newNode;
	if (p == NULL) {
		newNode;
	(treeNode*)malloc(sizeof(treeNode));
	newNode->key = x;
	newNode ->left = NULL;
	newNode->right = NULL;
	return newNode;
	}
	else if (x < p->key) {
		p->left = insertKey(p->left, x);
		return p;
	}
	else if (x > p->key) {
		p->left = insertKey(p->right, x);
		return p;
	}
	else {
		printf("\n 이미 같은 키가 있습니다! \n");
		return p;
	}
}

treeNode* searchBST(treeNode* root, char x) {
	treeNode* p;
	p = root;
	while (p != NULL) {
		if (x < p->key) {
			p = p->left;
		}
		else if (x == p->key) {
			return p;
		}
		else p = p->right;
	}
	printf("\n 찾는 키가 없습니다! \n");
	return p;
}

void insert(treeNode** root, char x) {
	*root = insertKey(*root, x);
}

int main() {
	treeNode* root = NULL;
	treeNode* foundedNode = NULL;
	char key;

	insert(&root, 'A');
	insert(&root, 'B');
	insert(&root, 'D');
	insert(&root, 'E');
	insert(&root, 'G');
	insert(&root, 'H');
	insert(&root, 'I');
	insert(&root, 'J');
	insert(&root, 'M');
	insert(&root, 'N');
	insert(&root, 'Q');

	printf("\n찾을 문자를 입력하세요! : ");
	scanf("%c", &key);

	while (key != 'z') {
		foundedNode = searchBST(root, key);
		if (foundedNode != NULL) {
			printf("\n	%c	키를	찾았습니다!	\n", foundedNode->key);
		}
		else {
			printf("\n 키를 찾지 못했습니다. \n");
		}

		printf("\n\n\n 찾을 문자를 입력하세요! : ");
		scanf("%c", &key);
	}
	getchar();
	return 0;
}