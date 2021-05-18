#pragma once
struct Stack
{
	int number;
	Stack* next;
};

void show(Stack*);
int pop(Stack*);
void push(int, Stack**);
void write(Stack*);
void read(Stack*);
void clear(Stack*);
int task(Stack*);
void menu();