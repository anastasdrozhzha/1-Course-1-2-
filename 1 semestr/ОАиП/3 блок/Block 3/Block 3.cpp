// Block 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <fstream>
#include <Windows.h> 
using namespace std;
struct list
{
    int number;
    list* next;
};

void insert(list*&, float); //функция добавления элемента, передается адрес списка и символ, который добавляется 
float del(list*&, float);   //функция удаления, передается адрес списка и символ, который удаляется 
int IsEmpty(list*);         //функция, которая проверяет, пуст ли список
void printList(list*);      //функция вывода
void menu(void);     //функция, показывающая меню
void sum7(list*); //функция подсчета суммы отрицательных двузначных чисел
void toFile(list*& p);   //Запись в файл
void fromFile(list*& p);  //Вывод из файла

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    list* first = NULL;
    int choice;
    float value;
    menu();    // вывести меню 
    cout << " Введите номер операции ";
    cin >> choice;
    while (choice != 6)
    {
        switch (choice)
        {
        case 1:  	cout << "Введите число "; // добавить число в список
            cin >> value;
            insert(first, value);
            printList(first);
            break;
        case 2:   if (!IsEmpty(first)) // удалить число из списка
        {
            cout << "Введите удаляемое число ";
            cin >> value;
            if (del(first, value))
            {
                cout << "Удалено число " << value << endl;
                printList(first);
            }
            else
                cout << "Число не найдено" << endl;
        }
              else
            cout << "Список пуст" << endl;
            break;
        case 3:   sum7(first);	// вычисление суммы	
            break;
        default:  cout << "Неправильный выбор" << endl;
            menu();
            break;

        case 4:    toFile(first);
            break;

        case 5:    fromFile(first);
            break;
        }

        cout << "Выбери, что необходимо сделать дальше:  ";
        cin >> choice;
    }
    cout << "Конец" << endl;
    return 0;
}

void menu(void)  //Вывод меню 
{
    cout << "Сделайте выбор:" << endl;
    cout << " 1 - Ввод числа" << endl;
    cout << " 2 - Удаление числа" << endl;
    cout << " 3 - Вычисление суммы отрицательных двузначных чисел " << endl;
    cout << " 4 - Запись списка в файл" << endl;
    cout << " 5 - Чтение списка из файла" << endl;
    cout << " 6 - Выход" << endl;
}

void insert(list*& p, float value) //Добавление числа value в список 
{
    list* newP = new list;
    if (newP != NULL)     //есть ли место?  
    {
        newP->number = value;
        newP->next = p;
        p = newP;
    }
    else
        cout << "Операция добавления не выполнена" << endl;
}

float del(list*& p, float value)  // Удаление числа 
{
    list* previous, * current, * temp;
    if (value == p->number)
    {
        temp = p;
        p = p->next;    // отсоединить узел 
        delete temp;      //освободить отсоединенный узел 
        return value;
    }
    else
    {
        previous = p;
        current = p->next;
        while (current != NULL && current->number != value)
        {
            previous = current;
            current = current->next; // перейти к следующему 
        }
        if (current != NULL)
        {
            temp = current;
            previous->next = current->next;
            delete(temp);
            return value;
        }
    }
    return 0;
}

int IsEmpty(list* p) //Список  пустой? (1-да, 0-нет) 
{
    return p == NULL;
}

void printList(list* p)  //Вывод списка 
{
    if (p == NULL)
        cout << "Список пуст" << endl;
    else
    {
        cout << "Список:" << endl;
        while (p != NULL)
        {
            cout << "~~~ " << p->number;
            p = p->next;
        }
        cout << "~~~NULL" << endl;
    }
}

void sum7(list* p)  // Подсчет суммы отрицательных двузначных  
{
    float sm = 0;
    if (p == NULL)
        cout << "Таких элементов нет" << endl;
    else
    {
        while (p != NULL)
        {
            if (p->number < -9)
                sm = sm + (p->number);
            p = p->next;
        }
        cout << "Сумма = " << sm << endl;
    }
}

void toFile(list*& p)
{
    list* temp = p;
    list buf;
    ofstream frm("File1.txt");
    if (frm.fail())
    {
        cout << "\n Ошибка открытия файла";
        exit(1);
    }
    while (temp)
    {
        buf = *temp;
        frm.write((char*)&buf, sizeof(list));
        temp = temp->next;
    }
    frm.close();
    cout << "Список записан в файл File1.txt\n";
}

void fromFile(list*& p)          //Считывание из файла
{
    list buf, * first = nullptr;
    ifstream frm("File1.txt");
    if (frm.fail())
    {
        cout << "\n Ошибка открытия файла";
        exit(1);
    }
    frm.read((char*)&buf, sizeof(list));
    while (!frm.eof())
    {
        insert(first, buf.number);
        cout << "~~~" << buf.number;
        frm.read((char*)&buf, sizeof(list));
    }
    cout << "~~~NULL" << endl;
    frm.close();
    p = first;
    cout << "\nСписок считан из файла File1.txt\n";
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
