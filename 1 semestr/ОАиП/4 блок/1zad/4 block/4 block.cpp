// 4 block.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

/*#include <iostream>
#include <fstream>
using namespace std;
const unsigned int NAME_SIZE = 30;
const unsigned int CITY_SIZE = 20;

struct Address
{
	char name[NAME_SIZE];
	char city[CITY_SIZE];
	Address* next;
	Address* prev;
};
//-----------------------------------------------------------
int menu(void)
{
	char s[80];  int c;
	cout << endl;
	cout << "1. Ввод имени" << endl;
	cout << "2. Удаление имени" << endl;
	cout << "3. Вывод на экран" << endl;
	cout << "4. Поиск" << endl;
	cout << "5. Добавить элемент в начало списка" << endl;
	cout << "6. Чтение из файла" << endl;
	cout << "7. Запись в файл" << endl;
	cout << "8. Выход" << endl;
	cout << endl;
	do
	{
		cout << "Ваш выбор: ";
		cin.sync();
		gets_s(s);
		cout << endl;
		c = atoi(s);
	} while (c < 0 || c > 8);
	return c;
}
//-----------------------------------------------------------
void insert(Address* e, Address** phead, Address** plast)
{
	Address* p = *plast;
	if (*plast == NULL)
	{
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		return;
	}
	else
	{
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
	}
}
//-----------------------------------------------------------
Address* setElement()
{
	Address* temp = new  Address();
	if (!temp)
	{
		cerr << "Ошибка выделения памяти памяти";
		return NULL;
	}

		cout << "Введите имя: ";
		cin.getline(temp->name, NAME_SIZE - 1, '\n');
		cin.ignore(cin.rdbuf()->in_avail());
		cin.clear();
		cout << "Введите город: ";
		cin.getline(temp->city, CITY_SIZE - 1, '\n');
		cin.ignore(cin.rdbuf()->in_avail());
		cin.clear();
		temp->next = NULL;
		temp->prev = NULL;
		return temp;
	
}
//-----------------------------------------------------------
void outputList(Address** phead, Address** plast)      //Вывод списка на экран
{
	Address* t = *phead;
	while (t)
	{
		cout << "ИМЯ: " << t->name << endl << "ГОРОД: " << t->city << endl;
		t = t->next;
	}
	cout << "" << endl;
}
//-----------------------------------------------------------
void find(char name[NAME_SIZE], Address** phead)    // Поиск имени в списке
{
	Address* t = *phead;
	while (t)
	{
		if (!strcmp(name, t->name)) break;
		t = t->next;
	}
	if (!t)
		cerr << "Имя не найдено" << endl;
	else
		cout << t->name << ' ' << t->city << endl;
}
//-----------------------------------------------------------
void delet(char name[NAME_SIZE], Address** phead, Address** plast)  // Удаление имени 
{
	struct Address* t = *phead;
	while (t)
	{
		if (!strcmp(name, t->name))  break;
		t = t->next;
	}
	if (!t)
		cerr << "Имя не найдено" << endl;
	else
	{
		if (*phead == t)
		{
			*phead = t->next;
			if (*phead)
				(*phead)->prev = NULL;
			else
				*plast = NULL;
		}
		else
		{
			t->prev->next = t->next;
			if (t != *plast)
				t->next->prev = t->prev;
			else
				*plast = t->prev;
		}
		delete t;
		cout << "Элемент удален" << endl;
	}
}


void writeToFile(Address** phead)       //Запись в файл
{
	struct Address* t = *phead;
	FILE* fp;
	errno_t err = fopen_s(&fp, "mlist", "wb");
	if (err)
	{
		cerr << "Файл не открывается" << endl;
		exit(1);
	}
	cout << "Сохранение в файл" << endl;
	while (t)
	{
		fwrite(t, sizeof(struct Address), 1, fp);
		t = t->next;
	}
	fclose(fp);
}
//-----------------------------------------------------------
void readFromFile(Address** phead, Address** plast)          //Считывание из файла
{
	Address* t;
	FILE* fp;
	errno_t err = fopen_s(&fp, "mlist", "rb");
	if (err)
	{
		cerr << "Файл не открывается" << endl;
		exit(1);
	}
	while (*phead) // Очистка списка(удаление элементов)
	{
		*plast = (*phead)->next;
		delete* phead;
		*phead = *plast;
	}
	*phead = *plast = NULL; // Первый и последний элемент списка - NULL
	cout << "Загрузка из файла" << endl;
	while (!feof(fp))
	{
		t = new Address();
		if (!t)
		{
			cerr << "Ошибка выделения памяти" << endl;
			return;
		}
		if (1 != fread(t, sizeof(struct Address), 1, fp)) break;
		insert(t, phead, plast);
	}
	fclose(fp);
}

void addLBegin(Address **phead, Address **plast) { // Функция добавления элемента в начало списка
	if (*plast == NULL) { // Если список пустой, добавить туда элемент
		insert(setElement(), phead, plast);
	}
	else { // В случае, если он не пустой
		Address *e = setElement(); 
		e->next = *phead;  
		(*phead)->prev = e;
		*phead = e;  
	}
}


//-----------------------------------------------------------
int main(void)
{
	setlocale(0, "");
	Address* head = NULL;
	Address* last = NULL;
	setlocale(LC_CTYPE, "Rus");
	int choice = 0;
	while (choice != 8)
	{
		choice = menu();
		switch (choice)
		{
		case 1:  insert(setElement(), &head, &last);
			break;
		case 2: {	  char dname[NAME_SIZE];
			cout << "Введите имя: ";
			cin.getline(dname, NAME_SIZE - 1, '\n');
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			delet(dname, &head, &last);
		}
			  break;
		case 3:  outputList(&head, &last);
			break;
		case 4: {	  char fname[NAME_SIZE];
			cout << "Введите имя: ";
			cin.getline(fname, NAME_SIZE - 1, '\n');
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			find(fname, &head);
		}
			  break;
		case 5:
			addLBegin(&head, &last); // My program
			break;
		case 6:  readFromFile(&head, &last);
			break;
		case 7: writeToFile(&head);
			break;
		default: exit(1);
		}
	}
	return 0;
}
*/
/*
#include <iostream>
using namespace std;
int f(int n) {
	static int k = 0;
	static int divisor = 2;
	if (n / 2 < divisor) {
		return k;
	}
	else if (n % divisor == 0) {
		k++;
		divisor++;
		f(n);
	}
	else {
		divisor++;
		f(n);
	}
}

int main() {
	int n;
	cout << "Input the number:\n";
	cin >> n;
	cout << "Result:\n";
	cout << f(n) << "\n";
	system("pause");
	return 0;
}*/

/*#include <iostream>
#include <cstdlib>

using namespace std;
unsigned int s(int x)
{
	if (x > 100)
	{
		return x+10 ;
	}
	else
	{
		return s(s(x+4));

	}
}

int main()
{
	int x;
	cout << " Input value of x:" << endl;
	cin >> x;
	cout <<"Result: "<< s(x) << endl;
	system("PAUSE");
}*/
/*#include <iostream>
#include<conio.h>  
using namespace std;
struct Node
{
	int data;             //Информационное поле
	Node* left, * right;   //Указатели на левую и правую ветви дерева
};
Node* tree = nullptr;

void insert(int a, Node** t)  //Добавление элемента a 
{
	if ((*t) == NULL)              //если дерева нет, то создается элемент
	{
		(*t) = new Node;
		(*t)->data = a;
		(*t)->left = (*t)->right = NULL;
		return;
	}
	if (a > (*t)->data)  //дерево есть, если а больше текущего
		insert(a, &(*t)->right);  //то элемент помещается вправо
	else
		insert(a, &(*t)->left);   //иначе - влево
}

void print(Node* t, int u)    //Вывод на экран
{
	if (t == NULL)  return;
	else
	{
		print(t->left, ++u);     //левое поддерево
		for (int i = 0; i < u; ++i)
			cout << "|";
		cout << t->data << endl;
		u--;
	}
	print(t->right, ++u);          // правое поддерево
}

void main()
{
	setlocale(LC_CTYPE, "Russian");
	int count, temp;
	cout << "Введите количество элементов  "; cin >> count;
	for (int i = 0; i < count; ++i)
	{
		cout << "Введите число  ";	cin >> temp;
		insert(temp, &tree);
	}
	cout << "ваше дерево\n";
	print(tree, 0);
	_getch();
}*/

#include <iostream>
#include<conio.h>  
using namespace std;
struct Node
{
	int data;             //Информационное поле
	Node* left, * right;   //Указатели на левую и правую ветви дерева
};
Node* tree = nullptr;
int  tree_count(std::ostream& _out, const node* tr, int level, int i = 0);
int  tree_height(const node* tr);

void insert(int a, Node** t)  //Добавление элемента a 
{
	if ((*t) == NULL)              //если дерева нет, то создается элемент
	{
		(*t) = new Node;
		(*t)->data = a;
		(*t)->left = (*t)->right = NULL;
		return;
	}
	if (a > (*t)->data)  //дерево есть, если а больше текущего
		insert(a, &(*t)->right);  //то элемент помещается вправо
	else
		insert(a, &(*t)->left);   //иначе - влево
}

void print(Node* t, int u)    //Вывод на экран
{
	if (t == NULL)  return;
	else
	{
		print(t->left, ++u);     //левое поддерево
		for (int i = 0; i < u; ++i)
			cout << "|";
		cout << t->data << endl;
		u--;
	}
	print(t->right, ++u);          // правое поддерево
}

void main()
{
	setlocale(LC_CTYPE, "Russian");
	int count, temp;
	cout << "Введите количество элементов  "; cin >> count;
	for (int i = 0; i < count; ++i)
	{
		cout << "Введите число  ";	cin >> temp;
		insert(temp, &tree);
	}
	cout << "ваше дерево\n";
	print(tree, 0);
	_getch();
	const int N = tree_height(tr);
	for (int l = 0; l < N; ++l) {
		std::cout << l << "). ";
		int m = tree_count(std::cout, tr, l);
		std::cout << std::endl << "count elements: " << m << std::endl << std::endl;
	}
}
//подсчёт кол-во элементов на определённом уровне
int tree_count(std::ostream& _out, const node* tr, int level, int i) {
	int n = 0;
	if (tr != NULL) {
		if (i == level) {
			++n;
			_out << tr->val << ' ';
		}

		if (tr->left != NULL)
			n += tree_count(_out, tr->left, level, i + 1);
		if (tr->right != NULL)
			n += tree_count(_out, tr->right, level, i + 1);
	}
	return n;
}
int tree_height(const node* tr) {
	int l, r;
	if (tr != NULL) {
		l = (tr->left != NULL) ? tree_height(tr->left) : 0;
		r = (tr->right != NULL) ? tree_height(tr->right) : 0;
		return ((l > r) ? l : r) + 1;
	}
	return 0;
}

/*
#include <iostream>

struct node {
	node* left;
	node* right;
	int   val;
};
void tree_add(node*& tr, int val);
void tree_clear(node* tr);
int  tree_height(const node* tr);
int  tree_count(std::ostream& _out, const node* tr, int level, int i = 0);

int main(void) {
	node* tr = NULL;
	/*
	   5, 7, 9, 6, 3, 2, 4

				 5
			   /   \
			  3     7
			 / \   / \
			2  4 6   9
	*/
	/*int a[] = { 5, 7, 9, 6, 3, 2, 4 };
	int n = sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < n; ++i)
		tree_add(tr, a[i]);

	const int N = tree_height(tr);
	for (int l = 0; l < N; ++l) {
		std::cout << l << "). ";
		int m = tree_count(std::cout, tr, l);
		std::cout << std::endl << "count elements: " << m << std::endl << std::endl;
	}
	tree_clear(tr);
	return 0;
}

//подсчёт кол-во элементов на определённом уровне
int tree_count(std::ostream& _out, const node* tr, int level, int i) {
	int n = 0;
	if (tr != NULL) {
		if (i == level) {
			++n;
			_out << tr->val << ' ';
		}

		if (tr->left != NULL)
			n += tree_count(_out, tr->left, level, i + 1);
		if (tr->right != NULL)
			n += tree_count(_out, tr->right, level, i + 1);
	}
	return n;
}

//высота дерева
int tree_height(const node* tr) {
	int l, r;
	if (tr != NULL) {
		l = (tr->left != NULL) ? tree_height(tr->left) : 0;
		r = (tr->right != NULL) ? tree_height(tr->right) : 0;
		return ((l > r) ? l : r) + 1;
	}
	return 0;
}

//добавление
void tree_add(node*& tr, int val) {
	if (tr == NULL) {
		tr = new node();
		tr->val = val;
		tr->left = tr->right = NULL;
	}
	else if (val < tr->val)
		tree_add(tr->left, val);
	else if (val > tr->val)
		tree_add(tr->right, val);
}

//удаление
void tree_clear(node* tr) {
	if (tr != NULL) {
		if (tr->left != NULL)
			tree_clear(tr->left);
		if (tr->right != NULL)
			tree_clear(tr->right);
		delete tr;
	}
}
*/

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
