// 16 лаба.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
/*#include <iostream>
#include <ctime>
#include <time.h>
using namespace std;
int Insert(int* A, int n);
int Hoar(int* A, int n);
int Puzir(int* A, int n);
void Heapify(int A[], int pos, int n)
{
	int t, tm;
	while (2 * pos + 1 < n)
	{
		t = 2 * pos + 1;
		if (2 * pos + 2 < n && A[2 * pos + 2] >= A[t])
			t = 2 * pos + 2;
		if (A[pos] < A[t])
		{
			tm = A[pos]; A[pos] = A[t];
			A[t] = tm; pos = t;
		}
		else break;
	}

}

int main()
{
	int start_time;
	unsigned long long int end_time;
	int n, j = 0, i;
	cout << "Input size of array n = ";
	cin >> n;
	int* A = new int[n];
	srand((unsigned)time(NULL));
	for (i = 0; i < n; i++)
	{
		A[i] = rand() % 101;
	}
	for (i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	int choice;
	cout << "What kind of sorting do you want to use? (1 - insert, 2 - Hoar's sorting, 3 -  piramidal):";
	cin >> choice;
	switch (choice)
	{
	case 1:
		Insert(A, n);
		break;
	case 2:
		start_time = clock();
		Hoar(A, n);
		end_time = clock();
		cout << "Time of sorting: " << end_time - start_time << " msec\n";
		break;
	case 3:
		Puzir(A, n);
		break;
	default:
		exit(1);
		break;
	}
	system("pause");
	return 1;
}
int Insert(int* A, int n)
{
	int t, i, j;
	int start_time = clock();
	for (i = 1; i < n; i++)
	{
		t = A[i];
		for (j = i - 1; j >= 0 && A[j] > t; j--)
			A[j + 1] = A[j];
		A[j + 1] = t;
	}
	unsigned long long int end_time = clock();
	cout << "Time of sorting: " << end_time - start_time << " msec\n";
	return 1;
}
int Hoar(int* A, int n)
{
	int i = 0, j = n - 1, t, p;
	p = A[n >> 1];
	do
	{
		while (A[i] < p) i++;
		while (A[j] > p) j--;
		if (i <= j)
		{
			t = A[i];
			A[i] = A[j];
			A[j] = t;
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0) Hoar(A, j);
	if (n > i) Hoar(A + i, n - i);
	return 1;
}
int Puzir(int* A, int n)
{
	int tm;
	int start_time = clock();
	for (int i = n - 1; i >= 0; i--)
		Heapify(A, i, n);
	while (n > 0)
	{
		tm = A[0]; A[0] = A[n - 1];
		A[n - 1] = tm; n--;
		Heapify(A, 0, n);
	}
	unsigned long long int end_time = clock();
	cout << "Time of sorting: " << end_time - start_time << " msec\n";
	return 1;
*/

#include <ctime>
#include "stdio.h"
#include <iostream>
#define N 10000

using namespace std;

void bubbleSort(int a[], int n)
	{
		int i, j, t;
		for (i = 1; i < n; i++)
			for (j = n - 1; j >= i; j--)
				if (a[j - 1] < a[j])
				{
					t = a[j - 1];
					a[j - 1] = a[j];
					a[j] = t;
				}
	}
void hoarasort(int *a, int first, int last)
{
 
int i = first, j = last;
double tmp, x = a[(first + last) / 2];
 
do {
   while (a[i] > x)
     i++;
   while (a[j] < x)
     j--;
 
   if (i <= j) 
   {
     if (i < j)
     {
       tmp=a[i];
       a[i]=a[j];
       a[j]=tmp;
     }
     i++;
     j--;
   }
} while (i <= j);
 
if (i < last)
   hoarasort(a, i, last);
if (first < j)
   hoarasort(a, first,j);
}
int main()
{
	int A[N],B[N], B2[N], max = A[0], size = 0, maxindex, clock_t;
	 
	for (int i = 0; i < N; i++)
	{
		A[i] = rand() % 200;
	}
	for ( int i = 0; i < N; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < N; i++)
	{
		if (A[i] > max) {
			max = A[i];
			maxindex = i;
		}
	}

	cout <<"Maksimum element index:" << maxindex  << endl;
	for (int j = maxindex; j < N; j++)
	{
		if (!(j%2)) {
			{
				B[size] = A[j];
				B2 [size] = A[j];
				cout << B[size] << " ";
				size++; 
			}
		
		}

	}
	
//сортировка пузырьком
	
/*	 bubbleSort(B, size);
	cout << "Sort: ";
	for (int i = 0; i < size; i++)
		cout << B[i] << " ";
	cout << endl;
	int t1 = clock();
	bubbleSort(B, size);
	int t2 = clock();
	cout << "Take " << t2 - t1 << " sec" << endl << endl;*/

//сортировка Хоара
	
	cout << "QuickSort";
	hoarasort(B2, 0, size - 1);

	for (int i = 0; i < size; i++)
	{
		cout <<B2[i] << " ";
	}
	cout << endl;
	int t1 = clock();
	bubbleSort(B, size);
	int t2 = clock();
	cout << "Take " << t2 - t1 << " sec" << endl << endl;
	return 0;
	

}
/*void scanf_array(int* arr, int size)
{
	int i;
	for (i = 0; i < size; ++i)
		scanf_s("%d", &arr[i]);
}

int get_max_index_of_array(int* arr, int size)
{
	int max_index = 0;
	int i;

	for (i = 0; i < size; ++i)
		if (arr[i] > arr[max_index])
			max_index = i;

	return max_index;
}

void sort(int* arr, int size)
{
}

void print_array(int* arr, int size)
{
	int i;
	for (i = 0; i < size; ++i)
		printf("%d ", arr[i]);
}

int _tmain()
{
	int A[N];
	int B[N];
	int size = 0;
	int max_index_of_array;
	int i;

	scanf_array(A, N);

	max_index_of_array = get_max_index_of_array(A, N);

	i = max_index_of_array + 1 + max_index_of_array % 2;

	for (; i < N; i += 2)
		B[size++] = A[i];

	sort(B, size);

	print_array(B, size);

	return 0;
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
