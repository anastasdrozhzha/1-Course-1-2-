// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

using namespace std;

struct Tree
{
    int key;
    int data;
    Tree* left;
    Tree* right;
};

Tree* createTree(Tree*);
Tree* createList(int, int);
Tree* insertList(Tree*);
Tree* searchKey(Tree*, int);
Tree* deleteKey(Tree*, int);
void showTree(Tree*, int);
void delTree(Tree*);
int var_13(Tree*, int*, int);

void menu();

void main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Tree* root = NULL, * add;
    int enteredKey, level;
    int counter[15], i = 0, range;
    float summ, amount;
    float* psumm = &summ, * pamount = &amount;
    int listSumm, listAmount;
    int* plistSumm = &listSumm, * plistAmount = &listAmount;
    int choice;
    do
    {
        menu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            root = createTree(root);
            if (root == NULL)
            {
                cout << endl << "Дерево уже создано" << endl;
            }
            break;
        case 2:
            if (root == NULL)
            {
                cout << endl << "Дерева не существует" << endl;
            }
            else
            {
                insertList(root);
            }
            break;
        case 3:
            if (root == NULL)
            {
                cout << endl << "Дерева не существует" << endl;
            }
            else
            {
                cout << endl << "Введите ключ элемента, который необходимо найти: " << endl;
                cin >> enteredKey;
                add = searchKey(root, enteredKey);
                if (add == NULL)
                {
                    cout << endl << "Элемент с введеным ключом не найден" << endl;
                }
                else
                {
                    cout << endl << "Число, найденное по ключу : " << add->data << endl;
                }
            }
            break;

        case 4:
            if (root == NULL)
            {
                cout << endl << "Дерева не существует" << endl;
            }
            else
            {
                cout << endl << "Введите ключ элемента, который необходимо удалить" << endl;
                cin >> enteredKey;
                if (!deleteKey(root, enteredKey));
                {
                    cout << endl << "Элемент с веденным ключом не найден!" << endl;
                }
            }
            break;
        case 5:
            level = 0;
            add = root;
            if (root == NULL)
            {
                cout << endl << "Дерева не существует" << endl;
            }
            else
            {
                showTree(add, level);
            }
            break;
        case 6:
            if (root == NULL)
            {
                cout << endl << "Дерева не существует" << endl;
            }
            else
            {
                add = root;
                delTree(add);
                root = NULL;
                cout << endl << "Удаление завершено" << endl;
            }
            break;
        case 7:
            add = root;
            i = 0;
            for (int j = 0; j <= 14; j++)
            {
                counter[j] = 0;
            }
            range = var_13(add, counter, i);
            cout << endl;
            for (int j = 0; j < range; j++)
            {
                cout << "Сумма элементов " << j + 1 << " уровня: " << counter[j] << endl;
            }
            break;
        default:
            return;
        }
    } while (choice != 8);
}

void menu()
{
    cout << endl << "1.Создание дерева" << endl;
    cout << "2.Добавление элемента к дереву" << endl;
    cout << "3.Поиск по ключу" << endl;
    cout << "4.Удаление элемента" << endl;
    cout << "5.Вывод дерева" << endl;
    cout << "6.Отчистка дерева" << endl;
    cout << "7.Задание 13" << endl;
    cout << "8.Выход" << endl;
    cout << "Выберите пункт: " << endl;
}

Tree* createTree(Tree* root)
{
    int key, data;
    if (root == NULL)
    {
        cout << "Введите ключ корня дерева: " << endl;
        cin >> key;
        cout << "Введите данные корня дерева: " << endl;
        cin >> data;
        root = createList(key, data);
        return root;
    }
    else
    {
        return NULL;
    }
}

Tree* createList(int key, int data)
{
    Tree* temp = new Tree;
    temp->key = key;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Tree* insertList(Tree* root)
{
    int key, data;
    bool find = false;
    cout << endl << "Ввод элементов в дерево (введите ключ '-1' для остановки ввода) " << endl;
    while (1)
    {
        Tree* temp = root, * prev = temp;
        cout << endl << "Введите ключ:" << endl;
        cin >> key;
        if (key < 0)
        {
            cout << endl << "Остановка ввода" << endl;
            break;
        }
        else
        {
            while (temp != NULL && !find)
            {
                prev = temp;
                if (key == temp->key)
                {
                    find = true;
                    cout << endl << "Совпадение ключей (ошибка)" << endl;
                    return NULL;
                }
                else
                {
                    if (key < temp->key)
                    {
                        temp = temp->left;
                    }
                    else
                    {
                        temp = temp->right;
                    }
                }
            }
            if (!find)
            {
                cout << endl << "Введите данные" << endl;
                cin >> data;
                temp = createList(key, data);
                if (key < prev->key)
                {
                    prev->left = temp;
                }
                else
                {
                    prev->right = temp;
                }
            }
        }
    }
}

Tree* searchKey(Tree* root, int key)
{
    Tree* temp = root;
    while (temp != NULL && key != temp->key)
    {
        if (key < temp->key)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    if (temp == NULL)
    {
        return NULL;
    }
    if (key == temp->key)
    {
        return temp;
    }
}

Tree* deleteKey(Tree* root, int key)
{
    Tree* del, * prevDel, * repl, * prevRepl;
    del = root;
    prevDel = NULL;
    while (del != NULL && key != del->key)
    {
        prevDel = del;
        if (key < del->key)
        {
            del = del->left;
        }
        else
        {
            del = del->right;
        }
    }
    if (del == NULL)
    {
        return NULL;
    }
    if (del->right == NULL)
    {
        repl = del->left;
    }
    else
    {
        if (del->left == NULL)
        {
            repl = del->right;
        }
        else
        {
            prevRepl = del;
            repl = del->left;
            while (repl->right != NULL)
            {
                prevRepl = repl;
                repl = repl->right;
            }
            if (prevRepl == del)
            {
                repl->right = del->right;
            }
            else
            {
                repl->right = del->right;
                prevRepl->right = repl->left;
                repl->left = prevRepl;
            }
        }
    }
    if (del = root)
    {
        root = repl;
    }
    else
    {
        if (del->key < prevDel->key)
        {
            prevDel->left = repl;
        }
        else
        {
            prevDel->right = repl;
        }
    }
    cout << endl << "Удален элемент с ключом " << del->key << " и значением " << del->data << endl;
    delete del;
}

void showTree(Tree* temp, int level)
{
    if (temp != NULL)
    {
        showTree(temp->right, level + 1);   //вывод правого поддерева
        for (int i = 0; i < level; i++)
        {
            cout << "     ";
        }
        cout << temp->key << "-";
        cout << temp->data;
        showTree(temp->left, level + 1);    //вывод левого поддерева
    }
    else
    {
        cout << endl;
    }
}

void delTree(Tree* root) //Очистка дерева
{
    if (root != NULL)
    {
        delTree(root->left);
        delTree(root->right);
        delete root;
    }
}

int var_13(Tree* temp, int* counter, int i)
{
    if (temp != NULL)
    {
        if (i == 0)
        {
            counter[i] = temp->data;
            var_13(temp->right, counter, i + 1);
            var_13(temp->left, counter, i + 1);
        }
        else
        {
            counter[i] += temp->data;
            var_13(temp->right, counter, i + 1);
            var_13(temp->left, counter, i + 1);
        }
    }
    else
    {
        return i;
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
