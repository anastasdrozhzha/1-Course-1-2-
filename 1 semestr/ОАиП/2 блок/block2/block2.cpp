// block2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

/*#include <iostream>
#include <fstream>
#include <windows.h>
#include <stdio.h>
#include <cstdio>

using namespace std;

void v11_1();
void v11_2();

void outFile(ofstream& f, char* buffer, char* str);
void inFile(ifstream& f, char* buffer, char* str);

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice;
	cout << "Введите номер задания: " << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		v11_1();
		break;
	}
	case 2:
	{
		v11_2();
		break;
	}

	}
}

void v11_1()
{
	char buffer[50];
	int minVowel = 0, numberOfSent = 0, countVowel = 0, necessSent = 0;
	ifstream fin("ff1.txt");
	ofstream fout("FILE2.txt");
	if (!fin.is_open())
		cout << "Файл не может быть открыт!\n";
	else
	{
		while (!fin.eof())
		{
			fin.getline(buffer, 50);
			int sizeOfStr = strlen(buffer);
			bool isSpace = false;
			bool strCopied = false;
			for (int i = 0; i < sizeOfStr; i++)
			{
				if (buffer[i] == ' ' && isSpace)
				{
					fout << buffer;
					fout << endl;
					strCopied = !strCopied;
					break;
				}

				if (buffer[i] == ' ' && !isSpace)
				{
					isSpace = !isSpace;
				}
			}
			if (strCopied)
			{
				for (int k = 0; k < sizeOfStr + 1; k++)
				{
					if (buffer[k] == 'A' || buffer[k] == 'a' || buffer[k] == 'E' || buffer[k] == 'e' || buffer[k] == 'I' || buffer[k] == 'i' || buffer[k] == 'O' || buffer[k] == 'o' || buffer[k] == 'U' || buffer[k] == 'u' || buffer[k] == 'Y' || buffer[k] == 'y')
					{
						countVowel++;
					}
					if (buffer[k] == ' ' || buffer[k] == '\0')
					{
						numberOfSent++;
						if (countVowel > minVowel)
						{
							minVowel = countVowel;
							necessSent = numberOfSent;
						}
						countVowel = 0;
					}
				}
			}
		}
	}
	cout << "Большее количество гласных (" << minVowel << ") в (во) " << necessSent << " слове." << endl;
	if (fin.eof())
	{
		cout << "~~Достигнут конец файла~~" << endl;
	}
	fin.close();
	fout.close();
}

void v11_2()
{
	char buffer[50];
	char str[200];
	int i = 0;
	int roundBrackets = 0, fiqureBrakets = 0, squareBrakets = 0, angledBrackets = 0;
	ifstream fin;
	ofstream fout;
	cout << "Введите путь к файлу для записи: " << endl;
	cin >> str;
	cout << "Введите строку для записи: " << endl;
	cin >> buffer;
	outFile(fout, buffer, str);
	inFile(fin, buffer, str);
	while (buffer[i] != EOF)
	{
		if (buffer[i] == '(' || buffer[i] == ')')
		{
			roundBrackets++;
		}
		if (buffer[i] == '[' || buffer[i] == ']')
		{
			squareBrakets++;
		}
		if (buffer[i] == '{' || buffer[i] == '}')
		{
			fiqureBrakets++;
		}
		if (buffer[i] == '<' || buffer[i] == '>')
		{
			angledBrackets++;
		}
		i++;
	}
	cout << "Круглых скобок: " << roundBrackets << endl;
	cout << "Квадратных скобок: " << squareBrakets << endl;
	cout << "Фигурных скобок: " << fiqureBrakets << endl;
	cout << "Угловых скобок: " << angledBrackets << endl;
	fin.close();
	fout.close();
}



void outFile(ofstream& f, char* buff, char* str)
{
	f.open(str);
	if (f.fail())
	{
		cout << "Ошибка открытия файла" << endl;
	}
	else {
		f << buff;
		f.close();
	}
}

void inFile(ifstream& f, char* buff, char* str)
{
	f.open(str);
	if (f.fail())
	{
		cout << "Ошибка открытия файл" << endl;
	}
	else {
		f >> buff;
		f.close();
	}
}*/

//Вокзал.Номер поезда, пункт назначения, дни следования, время прибытия, время отправления.Выбор по пункту назначения.
/*#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;
#define size 3

void enterNew();
void del();
void find(char* findname);
void out();
void record();
void read();
void menu();

struct Trains
{
	char number[20];
	char destination[20];
	char days[40];
	char arrTime[10];
	char depTime[10];
};

struct Trains list[size];
struct Trains bad;

int choice, currentSize = 0;

ifstream fin("trains.txt");
ofstream fout("trains.txt");

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char findDest[20];
	cout << "РАСПИСАНИЕ ПОЕЗДОВ ИЗ МИНСКА!" << endl;
	menu();
	cout << "Выберите пункт: ";
	cin >> choice;
	do
	{
		switch (choice)
		{
		case 1: enterNew(); break;
		case 2: record(); break;
		case 3: out(); break;
		case 4: read(); break;
		case 5: del(); break;
		case 6: cout << "Введите пункт назначения" << endl; cin >> findDest; find(findDest); break;
		}
	} while (choice != 7);
	cout << "~~Выход~~"; return;
}
void menu()
{
	cout << "\n1.Ввод новой записи\n";
	cout << "2.Запись информации в файл\n";
	cout << "3.Вывод данных структуры\n";
	cout << "4.Чтение данных из файла\n";
	cout << "5.Удаление структуры данных\n";
	cout << "6.Поиск информации\n";
	cout << "7.Выход\n";
}
void enterNew()
{
	cout << endl << "~~Ввод информации~~" << endl << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
	if (currentSize < size)
	{
		cout << "Строка номер: " << currentSize + 1 << endl;
		cout << "Номер поезда: "; cin >> list[currentSize].number; cout << endl;
		cout << "Пункт назначения: "; cin >> list[currentSize].destination; cout << endl;
		cout << "Дни следования: "; cin >> list[currentSize].days; cout << endl;
		cout << "Время прибытия: "; cin >> list[currentSize].arrTime; cout << endl;
		cout << "Время отправления: "; cin >> list[currentSize].depTime; cout << endl;
		currentSize++;
	}
	else
	{
		cout << "Введено максимальное количество строк" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
	}
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
	cout << "~~Запись добавлена~~" << endl << endl;
	menu();
	cout << "Что дальше? (выберите пункт)" << endl;
	cin >> choice;
}

void record()
{
	cout << endl << "~~Запись данных в файл~~" << endl << endl;
	int i = 0;
	if (!fout.is_open())
		cout << "Файл не может быть открыт!\n";
	else
	{
		while (i < currentSize)
		{
			fout << "Строка номер: " << i + 1 << endl;
			fout << "Номер поезда: " << list[i].number << endl;
			fout << "Пункт назначения: " << list[i].destination << endl;
			fout << "Дни следования: " << list[i].days << endl;
			fout << "Время прибытия: " << list[i].arrTime << endl;
			fout << "Время отправления: " << list[i].depTime << endl;
			i++;
			fout << endl;
		}
		cout << "~~Запись прошла успешно~~" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
	}
	menu();
	cout << "Что дальше? (выберите пункт)" << endl;
	cin >> choice;
}

void out()
{
	int strout, number = 1;
	cout << endl << "~~Вывод структуры~~" << endl << endl;
	cout << "1.Вывод одной строки" << endl;
	cout << "2.Вывод всех строк" << endl;
	cin >> strout;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
	if (strout == 1)
	{
		cout << "Введите номер строки" << endl;
		cin >> number;
		cout << "Строка номер: " << number << endl;
		cout << "Номер поезда: " << list[number - 1].number << endl;
		cout << "Пункт назначения: " << list[number - 1].destination << endl;
		cout << "Дни следования: " << list[number - 1].days << endl;
		cout << "Время прибытия: " << list[number - 1].arrTime << endl;
		cout << "Время отправления: " << list[number - 1].depTime << endl;
	}
	if (strout == 2)
	{
		while (number < currentSize + 1)
		{
			cout << "Строка номер: " << number << endl;
			cout << "Номер поезда: " << list[number - 1].number << endl;
			cout << "Пункт назначения: " << list[number - 1].destination << endl;
			cout << "Дни следования: " << list[number - 1].days << endl;
			cout << "Время прибытия: " << list[number - 1].arrTime << endl;
			cout << "Время отправления: " << list[number - 1].depTime << endl;
			number++;
			cout << endl;
		}
	}
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
	menu();
	cout << "Что дальше? (выберите вариант)" << endl;
	cin >> choice;
}

void read()
{
	cout << endl << "~~Чтение из файла~~" << endl << endl;
	char bufFile[50];
	while (!fin.eof())
	{
		fin.getline(bufFile, 50);
		cout << bufFile << endl;
	}
	fin.seekg(0);
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
	menu();
	cout << "Что дальше? (выберите вариант)" << endl;
	cin >> choice;
}

void del()
{
	int d;
	cout << endl << "~~Введите номер строки, которую хотите удалить (для удаления всех строк введите -1)~~" << endl << endl;
	cin >> d;
	if (d != -1)
	{
		for (int dstr = (d - 1); dstr < currentSize; dstr++)
		{
			list[dstr] = list[dstr + 1];
		}
		currentSize--;
	}
	if (d == -1)
	{
		for (int i = 0; i < size; i++)
		{
			list[i] = bad;
		}
	}
	cout << "~~Удаление выполнено~~" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
	menu();
	cout << "Что дальше? (выберите вариант)" << endl;
	cin >> choice;
}

void find(char* findname)
{
	bool noFind = false;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(findname, list[i].destination) == 0)
		{
			cout << "\nНомер поезда\t" << list[i].number << endl;
			cout << "Пункт назначения\t" << list[i].destination << endl;
			cout << "Дни следования:\t" << list[i].days << endl;
			cout << "Время прибытия:\t " << list[i].arrTime << endl;
			cout << "Время отправления:\t " << list[i].depTime << endl;
			noFind = !noFind;
			break;
		}
	}
	if (!noFind)
	{
		cout << "~~Совпадений не найдено~~" << endl;
	}
	cout << "~~Поиск завершён~~" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
	menu();
	cout << "Что дальше? (выберите вариант)" << endl;
	cin >> choice;
}
*/

/*#include <iostream>

using namespace std;
void enter(int*);
void out(int, int*);
void del(int, int*);
void find(int*);


struct byte {
	int months : 12;
	int days : 7;
};
struct  student{
	char name[20];
	char spec[30];
	char facult[30];
	int grup;
	int sred;
	byte date;
};
struct student stud[10];
struct student stud0;
int main()
{
	setlocale(LC_ALL, "rus");
	int choise;
	do {

		cout << "\n1.Ввод информации о студенте." << endl;
		cout << "2.Вывод информации о студенте." << endl;
		cout << "3.Хорошист/отличник/троечник" << endl;
		cout << "4.Удаление записи." << endl;
		cout << "5.Закончить программу." << endl;

		cout << "Выберите номер операции: ";

		cin >> choise;
		switch (choise) {
		case 1:
			cout << "Сколько записей хотите сделать?";
			int q;
			cin >> q;
			enter(&q);
			break;
		case 2:
			cout << "О какой записи вывести информацию? Если о всех, введите 444: ";
			int k;
			cin >> k;
			out(k, &q);
			break;
		case 3:
			cout << "Определим по среднему баллу, является ли студент хорошистом, отличником или средним студентом";
			find(&q);
			break;

		case 4:
			cout << "Какую запись удалить? если все, введите 444: ";
			int s;
			cin >> s;
			del(s, &q);
			break;
		case 5:
			exit(0);  break;
		default:
			cout << "Некорректный ввод!" << endl;
		}
	} while (choise != 6);
}
void enter(int* q) {
	for (int i = 0; i < *q; i++) {
		cout << "Фамилия студента: ";
		cin >> stud[i].name;
		cout << "Название специальности: ";
		cin >> stud[i].spec;
		cout << "Название факультета: ";
		cin >> stud[i].facult;
		cout << "Номер группы ";
		cin >> stud[i].grup;
		cout << "Введите срений балл студента: ";
		cin >> stud[i].sred;
		cout << "Введите месяц поступления: ";
		int a;
		cin >> a;
		stud[i].date.months = a;
		cout << "Введите день поступления: ";
		int b;
		cin >> b;
		stud[i].date.days = b;
	}
}
void out(int k, int* q) {
	cout << "Выведем информацию: ";
	if (k == 444) {
		int p = 0;
		while (p < *q) {
			cout << "Фамилия: " << stud[p].name << endl;
			cout << "Название специальности: " << stud[p].spec << endl;
			cout << "Название факультета: " << stud[p].facult << endl;
			cout << "Номер группы: " << stud[p].grup << endl;
			cout << "Средний балл студента: " << stud[p].sred << endl;
			cout << "День поступления: " << stud[p].date.days << endl;
			cout << "Месяц поступления: " << stud[p].date.months << endl;
			p++;
		}
	}
	else {
			cout << "Фамилия: " << stud[k-1].name << endl;
			cout << "Название специальности: " << stud[k-1].spec << endl;
			cout << "Название факультета: " << stud[k-1].facult << endl;
			cout << "Номер группы: " << stud[k-1].grup << endl;
			cout << "Средний балл студента: " << stud[k-1].sred << endl;
			cout << "День поступления: " << stud[k-1].date.days << endl;
			cout << "Месяц поступления: " << stud[k-1].date.months << endl;
	}
}
void find(int* q) {

	for (int i = 0; i < *q; i++) {

		if ((stud[i].sred) < 4)cout << "Студенту " << stud[i].name << " стоит повысить свой сред. балл(троечник)";
		if ((stud[i].sred) > 4 && (stud[i].sred) < 7) cout << "Студент " << stud[i].name << " хорошист!";
	
		else cout << "Студент " << stud[i].name << " отличник!";
	}
}
void del(int s, int* q) {
	if (s == 444) {
		int del = 0;
		while (del < *q) {
			stud[del] = stud0;

		}
		*q = 0;
		cout << "Все записи удалены!" << endl;
	}
	else {
		for (int i = s - 1; i < *q; i++)
		{
			stud[i] = stud[i + 1];
		}
		*q = *q - 1;
		cout << "Запись удалена!" << endl;
	}
}*/
//Государство.Наименование, столица, численность населения, площадь, фамилия президента.Выбор государства по названию.
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;
void enter(int*);
void out(int, int*);
void find(int*);
ifstream fin("trains.txt");
ofstream fout("trains.txt");

struct Country {
	char country[15];
	
	union {
		char capital[20];
		int number;
		int square;
		char name[20];
	};
};
struct Country stol[15];

int main()
{
	setlocale(LC_ALL, "rus");
	int choice;

	do {
		cout << "\n1.ввод информации.";
		cout << "\n2.вывод информации.";
		cout << "\n3.поиск информации (по названию).";
		cout << "\n4.выход из программы.";
		cout << "\nвведите номер операции: ";
		cin >> choice;
		switch (choice)
		{

	
		case 1:
			cout << "Сколько записей хотите сделать?";
			int q;
			cin >> q;
			enter(&q);
			break;
		case 2: 
			cout << "О какой стране хотите вывести информацию? (если о всех, введите 444):  ";
			int k;
			cin >> k;
			out(k, &q);
			break;


		case 3:
			find(&q);
			break;

		case 4:
			exit(0);  break;
		
		default:
			cout << "Некорректный ввод!" << endl;
		}


	} while (choice != 5);
}

void enter(int* q) {
	
	
	for (int i = 0; i < *q; i++) {
		cout << "Страна " << (i + 1);
		cin.ignore();
		cin >> stol[i].country;
		cout << "Страна ";
		cout << stol[i].country << endl;
		
		cout << "Столица " << (i + 1) << " этой страны ";
		cin.ignore();
		cin >> stol[i].capital;
		cout << "Столица ";
		cout << stol[i].capital<< endl;

		cout << " Численность состовляет" << (i + 1) << " человек ";
		cin.ignore();
		cin >> stol[i].number;
		cout << " Численность состовляет" << (i + 1) << " человек " ;
		cout << stol[i].number << endl;

		cout << "Площадь состовляет " << (i + 1) << " км^2 " ;
		cin.ignore();
		cin >> stol[i].square;
		cout << "Площадь состовляет " << (i + 1) << " км^2 ";
		cout << stol[i].square << endl;

		cout << "Президент " << (i + 1) ;
		cin.ignore();
		cin >> stol[i].name;
		cout << "Президент " << (i + 1);
		cout << stol[i].name << endl;
	

	}
}


void out(int k, int* q) {
	if (k == 444) {
		for (int i = 0; i < *q; i++) {
			cout << (i +1) << ".Страна: " << stol[i].country << endl;
			cout << (i +1) << ".Столица: " << stol[i].capital << endl;
			cout << (i +1) << ".Численность: " << stol[i].number << endl;
			cout << (i +1) << ".Площадь: " << stol[i].square << endl;
			cout << (i +1) << ".Президент: " << stol[i].name << endl;

		}
	}
	else {

		cout << (k) << ".Страна: " << stol[k - 1].country << endl;
		cout << (k) << ".Столица: " << stol[k - 1].capital << endl;
		cout << (k) << ".Численность: " << stol[k - 1].number << endl;
		cout << (k) << ".Площадь: " << stol[k - 1].square << endl;
		cout << (k) << ".Президент: " << stol[k - 1].name << endl;

	}
}

void find(int* q) {
	char n[20];
	cout << "\nВведите страну: ";
	cin >> n;
	for (int i = 0; i < *q; i++) {
		int count = 0;
		for (int j = 0; j < strlen(n); j++) {
			if (stol[i].country[j] == n[j]) {
				count++;
				if (count == strlen(n)) cout << "\nВы выбрали  " << stol[i].country;
			}
		}

	}
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
