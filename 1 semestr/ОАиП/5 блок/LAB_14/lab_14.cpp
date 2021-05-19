#include "Hash.h"
#include <iostream>
#include "windows.h"
using namespace std;
int  modulColision = 0, MultColision = 0;
struct AAA
{
	int key;
	char* mas;
	AAA(int k, char* z)
	{
		key = k;
		mas = z;
	} AAA(){}
};
//-------------------------------
int key(void* d)
{
	AAA* f = (AAA*)d;   
	return f->key;
}
//-------------------------------
void AAA_print(void* d)
{
	cout << " ���� " << ((AAA*)d)->key << " - " << ((AAA*)d)->mas << endl;
}
//-------------------------------
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int siz, choice, k;
	cout << "������� ������ ���-�������" << endl; 	cin >> siz;
	Object H = create(siz, key);
	for (;;)
	{
		cout << "1 - ����� ���-�������" << endl;
		cout << "2 - ���������� ��������" << endl;
		cout << "3 - �������� ��������" << endl;
		cout << "4 - ����� ��������" << endl;
		cout << "5 - ����� ����� �������" << endl;
		cout << "6 - ����c �������� �������" << endl;
		cout << "0 - �����" << endl;
		cout << "�������� �����" << endl;  
		cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 1: H.scan(AAA_print);  break;
		case 2: { 
			AAA* a = new AAA;
			char* str = new char[20];
			cout << "������� ����" << endl;	cin >> k;
			a->key = k;
			cout << "������� ������" << endl; cin >> str;
			a->mas = str;

			if (H.N == H.size)
				cout << "������� ���������" << endl;
			else
				H.insert(a, &modulColision, &MultColision);
		} break;
		case 3: {  cout << "������� ���� ��� ��������" << endl;
			cin >> k;
			H.deleteByKey(k);
		}  break;
		case 4: {  cout << "������� ���� ��� ������" << endl;
			cin >> k;
			if (H.search(k) == NULL)
				cout << "������� �� ������" << endl;
			else
				AAA_print(H.search(k));
		}  break;
		case 5:
		{
			cout << endl << "����� �������� ����� ��������� ����������� : " << modulColision << endl;
			cout << endl << "����� �������� ����� ����������������� ����������� : " << MultColision << endl;
		}
		break;
		case 6:
		{
			modulColision = 0;
			MultColision = 0;
		}
		break;
		}
	}
	return 0;
}
