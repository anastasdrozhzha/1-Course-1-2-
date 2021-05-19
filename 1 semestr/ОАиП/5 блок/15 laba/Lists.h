#pragma once
#define LISTNIL (Element*)-1
#include <iostream>
namespace listx
{
	struct Element
	{
		Element* prev;
		Element* next;
		void* data;
		Element(Element* pre, void* dat, Element* nex)
		{
			prev = pre;
			data = dat;
			next = nex;
		}
		Element* getNext()
		{
			return next;
		};
		Element* getPrev()
		{
			return prev;
		};
	};
	static Element* NIL = NULL;
	struct Object
	{
		Element* head;
		Object()
		{
			head = NIL;
		};
		Element* getFirst()
		{
			return head;
		};
		Element* getLast();
		Element* search(void* data);
		bool insert(void* data);
		bool deleteByElement(Element* e);
		bool deleteByData(void* data);
		void scan();
	};
	Object create();
}
#undef LISTNIL 
