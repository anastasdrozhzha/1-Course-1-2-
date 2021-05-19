// 15 laba.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Hash_Twin_Chain.h"
#include <iostream>
using namespace std;
char ttt[] = " ";
struct AAA
{
	int key;
	char* mas;
	AAA(int k, char* z)
	{
		key = k;
		mas = z;
	}
	AAA()
	{
		key = 0;
		mas = ttt;
	}
};
//-------------------------------
int hf(void* d)
{
	AAA* f = (AAA*)d;
	return f->key;
}
//-------------------------------
void AAA_print(listx::Element* e)
{
	std::cout << ((AAA*)e->data)->key << '-' << ((AAA*)e->data)->mas << " / ";
}
//-------------------------------
int main()
{
	setlocale(LC_ALL, "rus");
	int current_size = 7;
	cout << "Введите размер хеш-таблицы" << endl;
	cin >> current_size;
	hashTC::Object H = hashTC::create(current_size, hf);
	H.size = current_size;
	int choice;
	int k;
	for (;;)
	{
		cout << "1 - вывод хеш-таблицы" << endl;
		cout << "2 - добавление элемента" << endl;
		cout << "3 - удаление элемента" << endl;
		cout << "4 - поиск элемента" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 2: {	  AAA* a = new AAA;
			char* str = new char[20];
			cout << "введите номер группы" << endl;
			cin >> k;
			a->key = k;
			cout << "введите количество студентов" << endl;
			cin >> str;
			a->mas = str;
			H.insert(a);
		}
			  break;
		case 1: H.Scan();
			break;
		case 3: {	  AAA* b = new AAA;
			cout << "введите номер группы" << endl;
			cin >> k;
			b->key = k;
			H.deleteByData(b);
		}
			  break;
		case 4: AAA * c = new AAA;
			cout << "введите номер группы" << endl;
			cin >> k;
			c->key = k;
			if (H.search(c) == NULL)
				cout << "Элемент не найден" << endl;
			else
			{
				cout << "Количество студентов в этой группе равно: " << endl;
				AAA_print(H.search(c));
				cout << endl;
			}
			break;
		}
	}
	return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
