// Queue Linked List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
	int data;
	struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void Enqueue(int x)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = NULL;
	if (front == NULL && rear == NULL)
	{
		front = rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
}

void Dequeue() {
	struct Node* temp = front;
	if (front == NULL) {
		printf("Queue is Empty\n");
		return;
	}
	if (front == rear) {
		front = rear = NULL;
	}
	else
	{
		front = front->next;
	}
	free(temp);

}

int Front() {
	if (front == NULL) {
		printf("Queue is empty\n");
		return -1;
	}
	return front->data;
}

void Print()
{
	struct Node* temp = front;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}


int main()
{
	Enqueue(2); Print();
	Enqueue(4); Print();
	Enqueue(6); Print();
	Dequeue(); Print();
	Dequeue(); Print();
	Enqueue(8); Print();

    return 0;
}

