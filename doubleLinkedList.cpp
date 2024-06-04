#include <stdio.h>
#include <stdlib.h>

typedef struct doubleNode
{
	int value;
	struct doubleNode* next;
	struct doubleNode* prev;
}dnode;

dnode* head = NULL;		//첫번째 노드의 주소를 저장
dnode* tail = NULL;		//마지막 ''

void insertFront(int data) {
	dnode* newnode = (dnode*)malloc(sizeof(dnode));
	newnode->value = data;
	newnode->prev = NULL;
	newnode->next = NULL;

	if (head == NULL) {
		head = newnode;
		tail = newnode;
		return;
	}

	newnode->next = head;
	head->prev = newnode;
	head = newnode;
}

void insertTail(int data) {
	dnode* newnode = (dnode*)malloc(sizeof(dnode));
	newnode->value = data;
	newnode->prev = NULL;
	newnode->next = NULL;

	if (head == NULL) {
		head = newnode;
		tail = newnode;
		return;
	}

	tail->next = newnode;
	newnode->prev = tail;
	tail = newnode;
}

void removeFront() {
	if (head == NULL)return;
	if (head->next == NULL) {
		free(head);
		head = NULL;
		tail = NULL;
		return;
	}
	dnode* delenode = (dnode*)malloc(sizeof(dnode));
	delenode = head;
	head = head->next;
	head->prev = NULL;
	free(delenode);
}
//최종
void removeValue(int target)
{
	dnode* deleNode;
	if (head == NULL)return;
	if (head->value == target) {
		deleNode = head;
		head= head->next;
		free(deleNode);
		head->prev = NULL;
		return;
	}
	if (head->value == target) {
		deleNode = tail;
		tail= tail->prev;
		free(deleNode);
		tail->next = NULL;
		return;
	}
	deleNode = head;
	while (deleNode->next != NULL)
	{
		deleNode = deleNode->next;
		if (deleNode->value == target) {
			deleNode->prev->next = deleNode->next;
			deleNode->next->prev = deleNode->prev;
			free(deleNode);
			return;
		}
	}
}

void insert(int data) {
	dnode* newnode = (dnode*)malloc(sizeof(dnode));
	newnode->value = data;
	newnode->prev = NULL;
	newnode->next = NULL;

	if (head == NULL) {
		head = newnode;
		tail = newnode;
		return;
	}
	if (head->prev == NULL) {
		newnode->next = head;
		head->prev = newnode;
		head = newnode;
	}
	if (tail->next == NULL) {
		tail->next = newnode;
		newnode->prev = tail;
		tail = newnode;
	}
}