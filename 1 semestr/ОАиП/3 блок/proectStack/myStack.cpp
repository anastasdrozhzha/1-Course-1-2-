#include <iostream>
#include <fstream>
#include "Header.h"

using namespace std;

void menu()
{
	cout << "\n\n1. ���� ������ �����\n";
	cout << "2. ������� ����\n";
	cout << "3. �������� �������� ��������\n";
	cout << "4. �������� ����\n";
	cout << "5. ������ � ����\n";
	cout << "6. ������ ������ �� �����\n";
	cout << "7. ����� ���������� ������������� ���������\n";

}


void push(int number, Stack** head)
{
	Stack* newStack = new Stack;
	newStack->number = number;
	newStack->next = *head;
	*head = newStack;
	cout << "\n--����� ������� �������--";

}

int pop(Stack* head)
{
	Stack* temp = head;
	int a = temp->number;
	head = head->next;
	delete temp;
	return a;
}

void show(Stack* head)
{
	while (head != NULL)
	{
		cout << head->number;
		cout << endl;
		head = head->next;
	}

}

void clear(Stack* head)
{
	while (head != NULL)
	{
		Stack* temp = head;
		head = head->next;
		delete temp;
	}
}

void write(Stack* head)
{
	ofstream fwrite("write.txt");
	if (fwrite.fail())
	{
		cout << "\n --������ �������� �����--";
		exit(1);
	}
	else {
		while (head != NULL)
		{
			fwrite << head->number << " ";
			head = head->next;
		}

	}
	fwrite.close();

}

void read(Stack* head)
{
	int value;
	ifstream fread("read.txt");
	if (fread.fail())
	{
		cout << "\n --������ �������� �����--";
		exit(1);
	}
	else {
		while (!fread.eof())
		{
			fread >> value;
			push(value, &head);
		}

	}
	fread.close();

}

int task(Stack* head)
{
	int count = 0;
	Stack* b = head;
	Stack* a = head;
	b = b->next;
	while (a != NULL)
	{
		b = a->next;
		while (b != NULL)
		{

			if (head->number == b->number)
			{
				count++;
				break;
			}
			b = b->next;

		}
		a = a->next;
	}
	return count;
}