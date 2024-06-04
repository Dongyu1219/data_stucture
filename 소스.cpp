#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node* next;
}node;

node* head = NULL;

void insert_node_front() {		//�� �տ� ��� �߰�
	node* newnode;
	newnode = (node*)malloc(sizeof(node));		//node �޸� �Ҵ� (nodeŸ���� �ּ�)
	scanf("%d", &newnode->value);
	newnode->next = NULL;
	if (head == NULL) {
		head = newnode; 
		return;
	}
	newnode->next = head;
	head = newnode;
}

void display() {				//��� ��ȸ
	node* currentNode;
	currentNode = head;
	while (currentNode->next != NULL) {
		printf("%d", currentNode->value);
		currentNode = currentNode->next;
	}
	printf("%d", currentNode->value);

}
 
void insert_node_rear() {
	node* newnode;
	node* currentNode;
	newnode = (node*)malloc(sizeof(node));
	scanf("%d", &newnode->value);
	newnode->next = NULL;
	if (head == NULL) {
		head = newnode;
		return;
	}
	currentNode = head;
	while (currentNode->next != NULL) {
		currentNode = currentNode->next;
	}
	currentNode->next = newnode; 
}

void deleteNode() {		//ù��� ����
	node* delNode;
	if (head == NULL) {
		return;
	}
	delNode = head;
	head = head->next;
	free(delNode);	//��� ����
}

void deleteAllNode() {		//��ü ��� ����
	node* delNode;
	delNode = head;
	while (head != NULL) {
		head = head->next;
		free(delNode);
		delNode = head;
	}
}
int num;
node* searchNode(int num) {
	node* currentNode;
	if (head == NULL) return NULL;
	currentNode = head;
	while (currentNode != NULL) {
		if (num == currentNode->value) {
			return currentNode;
		}
		else {
			currentNode = currentNode->next;
		}
	}
	return NULL; //ã���� �ϴ� �� ����
}

void removeNodeValue(int num) {		//Ư���� ��� ����
	node* deleNode;
	node* prevNode;
	if (head == NULL) return;
	if (head->value == num) {		//����: ù��� ����
		deleNode = head;
		head = head->next;
		free(deleNode);	//��� ����
	}
	deleNode = head;
	prevNode = head;
	while (deleNode->next != NULL) {
		deleNode = deleNode->next;
			if (deleNode->value == num) {
				prevNode->next = deleNode->next;
				free(deleNode);
				return;
		}
		prevNode = prevNode->next;
	}
}
//9 ����
void insertNodeSort() {			//��� ����, ����
	node* newNode = (node*)malloc(sizeof(node));
	node* currentNode;
	node* prevNode;
	currentNode = head;
	prevNode = head;
	scanf("%d", &newNode->value);
	newNode->next = NULL;

	if (head == NULL) {
		head = newNode;
		return;
	}
	if (newNode->value < head->value) {
		head->next = head;
		head = newNode;
	}
	while (currentNode->next != NULL) {
		currentNode = currentNode->next;
		if (currentNode->value > newNode->value) {
			prevNode->next = newNode;
			newNode->next = currentNode;
			return;
		}
		prevNode = prevNode->next;
	}
	currentNode->next = newNode;
}


