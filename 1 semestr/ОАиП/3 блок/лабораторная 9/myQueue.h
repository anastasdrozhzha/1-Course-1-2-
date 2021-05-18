#pragma once
struct Queue
{
	int number;
	Queue* next;
};

void enter_new(Queue**, Queue**, int);
void show(Queue**);
int del(Queue**, Queue**);
void max_min(Queue**);

