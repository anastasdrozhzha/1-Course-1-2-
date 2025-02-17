﻿// proectStack.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include "Header.h"
#include <windows.h>

using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Stack* head = NULL;
	int choice;

	do
	{
		menu();
		cout << "\nВведите номер действия: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			int number;
			cout << "Введите число: ";
			cin >> number;
			push(number, &head);
			break;
		case 2:
			cout << "Текущий стек:";
			cout << endl;
			show(head);
			break;
		case 3:
			cout << "Удаленное число: " << pop(head);
			break;
		case 4:
			clear(head);

		case 5:
			cout << "--Запись в файл--";
			cout << endl;
			write(head);
			break;
		case 6:
			cout << "--Чтение из файла--";
			cout << endl;
			read(head);
			break;
		case 7:
			cout << "Количество повторяющихся элементов " << task(head);
			break;
		}
	} while (choice != 0);
	cout << "~~Выход~~"; return;

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
