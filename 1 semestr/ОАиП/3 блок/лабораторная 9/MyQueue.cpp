#include <iostream>
#include "myQueue.h"

using namespace std;

void enter_new(Queue** head, Queue** tail, int number)
{
	Queue* temp = new Queue;
	if (*head == NULL)
	{
		*head = temp;
		(*head)->number = number;
		*tail = *head;
	}
	else
	{
		temp->next = NULL;
		temp->number = number;
		(*tail)->next = temp;
		*tail = temp;
	}
}



int del(Queue** head, Queue** tail)
{
	Queue* temp;
	if (head == NULL)
	{
		return 0;
	}
	else
	{
		temp = *head;
		*head = (*head)->next;
		delete temp;
		return 1;
	}
}


void show(Queue** head)
{
	Queue* temp = *head;
	int count = 0;
	if (temp == NULL)
	{
		cout << "Очередь пуста!" << endl;
	}
	else
	{
		while (temp != NULL)
		{
			cout << temp->number << " ";
			temp = temp->next;
			count++;
		}
		cout << endl << "Элементов в очереди: " << count << endl;
	}
}



void max_min(Queue** head)
{
	Queue* temp = *head;
	int max = temp->number, min = temp->number;
	if (temp == NULL)
	{
		cout << "Очередь пуста!" << endl;
	}
	else
	{
		while (temp != NULL)
		{
			if (temp->number > max)
			{
				max = temp->number;
			}
			if (temp->number < min)
			{
				min = temp->number;
			}
			temp = temp->next;
		}
	}
	cout << "Минимальный элемент в очереди - " << min << endl;
	cout << "Максимальный элемент в очереди - " << max << endl;
}
