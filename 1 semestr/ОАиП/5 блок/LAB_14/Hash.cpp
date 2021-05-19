#include "Hash.h"
#include <iostream>
#include <math.h>
int ModulHashFunction(int key, int size, int p)   
{
	return key % size;
}

int MultHashFunction(int key, int size, int p)    
{
	float g = ((sqrt(5) - 1) / 2);
	return round(size*(fmod(key*g, 1)));
}
//-------------------------------
int Next_hash(int hash, int size, int p) 
{
	return (hash + p) % size;
}
//-------------------------------
Object create(int size, int(*getkey)(void*))
{
	return *(new Object(size, getkey));
}
//-------------------------------
Object::Object(int size, int(*getkey)(void*))
{
	N = 0;
	this->size = size;
	this->getKey = getkey;
	this->data = new void* [size];
	for (int i = 0; i < size; ++i)
		data[i] = NULL;
}
//-------------------------------
bool Object::insert(void* d, int* modC, int* multC)
{
	int choice;
	bool b = false;
	std::cout << "Выберите" << std::endl;
	std::cout << "Модульное хеширование - 1" << std::endl;
	std::cout << "Мультипликативное хеширование - 2" << std::endl;
	std::cin >> choice;
	switch (choice)
	{
	case 1:
	{
		if (N != size)
			for (int i = 0, t = getKey(d), j = ModulHashFunction(t, size, 0); i != size && !b;  j = Next_hash(j, size, ++i))
		{
		
			if(j != ModulHashFunction(t, size, 0))
				(*modC)++;
			if (data[j] == NULL || data[j] == DEL)
			{
				data[j] = d;
				N++;
				b = true;
			}
			
		}
		break;
	}
	case 2:
	{
		if (N != size)
			for (int i = 0, t = getKey(d), j = MultHashFunction(t, size, 0); i != size && !b; j = Next_hash(j, size, ++i))
			{
				if (j != MultHashFunction(t, size, 0))
					(*multC)++;
				if (data[j] == NULL || data[j] == DEL)
				{
					data[j] = d;
					N++;
					b = true;
				}
				
			}
		break;
	}
	}
	return b;
}
//-------------------------------
int Object::searchInd(int key)
{
	int choice;
	int t = -1;
	bool b = false;
	std::cout << "Выберите" << std::endl;
	std::cout << "Удаление элемента, добавленный через модульное хеширование - 1" << std::endl;
	std::cout << "Удаление элемента, добавленный через мультипликативное хеширование - 2" << std::endl;
	std::cin >> choice;
	switch (choice)
	{
	case 1:
		if (N != 0)
			for (int i = 0, j = ModulHashFunction(key, size, 0); data[j] != NULL && i != size && !b; j = Next_hash(key, size, ++i))
				if (data[j] != DEL)
					if (getKey(data[j]) == key)
					{
						t = j; b = true;
					}
		break;
	case 2:
		if (N != 0)
			for (int i = 0, j = MultHashFunction(key, size, 0); data[j] != NULL && i != size && !b; j = Next_hash(key, size, ++i))
				if (data[j] != DEL)
					if (getKey(data[j]) == key)
					{
						t = j; b = true;
					}
		break;
	}
	return t;
}
//-------------------------------
void* Object::search(int key)
{
	int t = searchInd(key);
	return(t >= 0) ? (data[t]) : (NULL);
}
//-------------------------------
void* Object::deleteByKey(int key)
{
	int i = searchInd(key);
	void* t = data[i];
	if (t != NULL)
	{
		data[i] = DEL;
		N--;
	}
	return t;
}
//-------------------------------
bool Object::deleteByValue(void* d)
{
	return(deleteByKey(getKey(d)) != NULL);
}
//-------------------------------
void Object::scan(void(*f)(void*))
{
	for (int i = 0; i < this->size; i++)
	{
		std::cout << " Элемент " << i;
		if ((this->data)[i] == NULL)
			std::cout << "  пусто" << std::endl;
		else
			if ((this->data)[i] == DEL)
				std::cout << "  удален" << std::endl;
			else
				f((this->data)[i]);
	}
}
