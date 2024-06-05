#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct champion {
	char name[20];
	int hp;
	int mp;
	int speed;
	int ad;
	char position[10];
	struct champion* next;
}champion;

champion* head = NULL;
champion* tail = NULL;

champion champions[100] = {
{"Jayce", 3466, 8307, 452, 73, "mid"},
{ "Vayne",3318,2790,390,60,"support" },
{ "Lee Sin",9864,6257,747,19,"support" },
{ "Teemo",1915,1313,700,68,"mid" },
{ "Nami",2968,2153,803,74,"support" },
{ "Jinx",2583,3042,123,53,"jungle" },
{ "Cassiopeia",6067,7330,683,24,"top" },
{ "Ahr",4573,7079,177,79,"top" },
{ "Fiora",2591,9329,337,81,"jungle" },
{ "Zac",9864,7272,405,49,"bottom" },
{ "Janna",4922,2275,690,66,"jungle" },
{ "Ashe",7421,5549,428,31,"top" },
{ "Twitch",2980,7703,204,91,"mid" },
{ "Ezreal",3660,9835,274,44,"mid" },
{ "Sona",5655,8442,252,26,"bottom" },
{ "Lulu",3231,2014,503,32,"support" },
{ "Amumu",6763,3994,427,19,"jungle" },
{ "Master Yi",5737,7168,434,61,"top" },
{ "Jarvan",1895,3070,323,80,"mid" },
{ "Shen",4794,9220,783,42,"mid" },
{ "Fizz",9864,1913,433,38,"bottom" },
{ "Taric",6158,7451,160,36,"bottom" }
};

int num = 22;

void printAll(champion *head) {
	champion* currentNode;
	currentNode = head;

	if (head == NULL)return;

	while (currentNode->next != NULL)
	{
		printf("이름: %s HP: %d\n", currentNode->name, currentNode->hp);
		currentNode = currentNode->next;
	}
}

void sort(champion** head) {
	champion** currentNode;
	champion* temp;
	int swapped;

	if (*head == NULL || (*head)->next == NULL)return;

	do
	{
		swapped = 0;
		currentNode = head;

		while ((*currentNode)->next != NULL)
		{
			if ((*currentNode)->hp < (*currentNode)->next->hp) {
				temp = (*currentNode)->next;
				(*currentNode)->next = temp->next;
				temp->next = (*currentNode);
				(*currentNode) = temp;
				swapped = 1;
			}
			currentNode = &(*currentNode)->next;
		}
	} while (swapped);
}

void sort2(champion** head) {
	champion** currentNode;
	champion* temp;
	int swapped;

	if (*head == NULL || (*head)->next == NULL)return;

	do
	{
		swapped = 0;
		currentNode = head;

		while ((*currentNode)->next != NULL)
		{
			if ((*currentNode)->hp > (*currentNode)->next->hp) {
				temp = (*currentNode)->next;
				(*currentNode)->next = temp->next;
				temp->next = (*currentNode);
				(*currentNode) = temp;
				swapped = 1;
			}
			currentNode = &(*currentNode)->next;
		}
	} while (swapped);
}

void printAll2(champion* head) {
	champion* currentNode;
	currentNode = head->next;

	if (head == NULL)return;

	while (currentNode->next != NULL)
	{
		printf("이름: %s HP: %d\n", currentNode->name, currentNode->hp);
		currentNode = currentNode->next;
	}
}

int main() {
	for (int i = 0; i < num; i++)
	{
		champions[i].next = &champions[i + 1];
	}
	head = &champions[0];
	champions[num].next = NULL;

	printAll(head);
	printf("\n");
	printf("\n");
	printf("내림차순 정렬\n");

	sort(&head);

	printAll(head);


	printf("\n");
	printf("\n");

	printf("오름차순 정렬\n");

	sort2(&head);

	printAll2(head);
	
}