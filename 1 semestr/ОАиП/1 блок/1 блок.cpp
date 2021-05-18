// 1 блок.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//1 лабораторная



//2 задание

/*Дана целочисленная квадратная матрица.
Если минимальное значение находится на главной диагонали, то вывести его значение и индексы.*/

/*#include <iostream>

using namespace std;
int elem(int, int);
int main()
{
	int kol = 5;
	int** arr = new int* [kol];
	for (int i = 0; i < kol; i++)
	{
		arr[i] = new int[kol];
	}
	for ( int i = 0; i < kol; i++)			//ввод значений матрицы
	{
		for (int j = 0; j < kol; j++)
		{
			arr[i][j] = rand() % 50;
		}
	}

	for ( int i = 0; i < kol; i++)			//вывод значений
	{
		for (int j = 0; j < kol; j++)
		{
			cout << arr[i][j] << '\t';
		}
		cout << endl;
	}

	int min = arr[0][0];
	int i, j,imin,jmin;
	for ( i = 0; i < kol; i++)			//minimum
		{
			for ( j = 0; j < kol; j++)
			{
				if (arr[i][j] < min) {
					min = arr[i][j];
					imin = i;
					jmin = j;
				}
			}

		}

		cout << "value: " << min << endl;
		cout << "[i] " << imin << endl;
		cout << "[j]" << jmin << endl;


		elem(imin, jmin);
	for (int i = 0; i < kol; i++)				//удаление динамической памяти
	{
		delete[] arr[i];
	}
	delete[] arr;
}
int elem(int jmin, int imin)				//собственная функция (семантика)
{
	if (imin == jmin)
	{
		cout << "result:" << imin << jmin << endl;
	}
	else {
		cout << "The value does not lie on the main diagonal";
	}
	return imin, jmin;
}*/

/*Дан массив A вещественного типа, содержащий 20 положительных и отрицательных элементов.
Сформировать массив B из положительных элементов массива A, имеющих четный индекс
Найти сумму квадратов элементов нового массива.*/

/*#include <iostream>
using namespace std;
double square(double*, const int);
int main()
{
	const int kol = 20;
	double* arrA = new double[kol];
	for (int i = 0; i < kol; i++)
	{
		arrA[i] = rand() % 30 - 7.6;
	}
	for (int i = 0; i < kol; i++)
	{
		cout << " " << arrA[i];
	}
	cout << endl;
	double* arrB = new double[kol];

	for (int i = 0; i < kol; i++)
	{
		if ((arrA[i] > 0) && ((i + 1) % 2 == 0)) {

			arrB[i] = arrA[i];
			cout << " " << arrB[i];
		}
	}

	square(arrB, kol);

	delete[] arrA;
	delete[] arrB;
}
double square(double* arrB, const int kol)
{
	double sum = 0;

	for (int i = 0; i < kol; i++) {
		sum += *(arrB + i) * *(arrB + i);
	}
	cout << endl;
	cout << "Summa= " << sum;
	return sum;

}*/

//2 лабораторная

//Задание 1
/*
		5x – 1 + x3,
		x2 + 1 / x
*/
/*
#include <iostream>
using namespace std;

double f1(double);
double f2(double);
double dichotomy(double (*)(double), double, double);
int main() {
	setlocale(0, "");
	int number;
	cout << "Какое уравнение нужно решить?\n1)5x-1+x^3\n2)x^2+1/x\n";
	cin >> number;
	switch (number) {
	case 1: cout << "Решение: " << dichotomy(f1, -2, 2) << endl; break;
	case 2: cout << "Решение: " << dichotomy(f2, 0, 1.5) << endl; break;
	}
	system("pause");
}
double f1(double x) {
	return 5 * x - 1 + x*x*x;
}
double f2(double x) {
	return x * x + 1/x ;
}
double dichotomy(double(*f)(double), double a, double b) {
	double x;
	while (abs(a - b) > 0.001) {
		x = (b + a) / 2;
		if (f(x) * f(a) <= 0) {
			b = x;
		}
		else {
			a = x;
		}
	}
	return x;
}*/


/*using namespace std;
//int foo(int k, ...);
const int n,n1,n2;
int main() {
	int arr;
	cout << "Enter tne size of array:" << endl;
	cin >> n1;

	for (int i = 0; i < n1; i++)			//ввод значений матрицы
	{
		for (int j = 0; j < n1; j++)
		{
			arr[i][j] = rand() % 50;
		}
	}

	for (int i = 0; i < n1; i++)			//вывод значений
	{
		for (int j = 0; j < n1; j++)
		{
			cout << arr[i][j] << '\t';
		}
		cout << endl;
	}int sum = 0;
	int arrb[];
	int k = 0;
	for (int i = 0; i < kol; i++)			//вывод значений
	{
		for (int j = 0; j < kol; j++)
		{
			if (i > j) {
			arr[i][j]=arrb[k];
			k++;
				 }
			
		}
		cout << endl;
		cout<<arrb<< "\t";
	}
	
	
	for (int i = 0; i < kol; i++)			//вывод значений
	{
		for (int j = 0; j < kol; j++)
		{
			sum+=arrb[i];
		}
	}
	cout << sum;
for (int i = 0; i < kol; i++)				//удаление динамической памяти
{
	delete[] arr[i];
}
delete[] arr;
}*/


//3 лаба 
//Компоненты файла f – целые числа.Получить файл g, образованный из f исключением
//повторных вхождений одного и того же числа.
/*
#include <iostream>
#include <stdio.h>
using namespace std;
void main() {
	setlocale(0, "");
	FILE* A;
	char s[10], s2[10];
	errno_t err = fopen_s(&A, "in.txt", "r");
	if (err != 0) {
		perror("Ошибка открытия файла!");
		return;
	}
	fgets(s, 51, A);
	int len = strlen(s), repete = 0, in = 0;
	fclose(A);
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (s[i] == s[j])
				repete++;
		}
		if (repete <= 1) {
			s2[in] = s[i];
			in++;
		}
		repete = 0;
	}
	s2[in] = '\0';
	err = fopen_s(&A, "out.txt", "w");
	if (err != 0) {
		perror("Ошибка открытия файла!");
		return;
	}
	fputs(s2, A);
	fclose(A);
	system("pause");
}
*/
//Компоненты файла fileA – целые числа, значения которых повторяются.Получить файл fileB,
// из fileA числами, которые встречаются в fileA более двух раз.

/*#include <iostream>
#include <stdio.h>
using namespace std;
void main() {
	setlocale(0, "");
	FILE* A;
	char s[10], s2[10];
	errno_t err = fopen_s(&A, "in.txt", "r");
	if (err != 0) {
		perror("Ошибка открытия файла!");
		return;
	}
	fgets(s, 51, A);
	int len = strlen(s), repete = 0, in = 0;
	fclose(A);
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (s[i] == s[j])
				repete++;
		}
		if (repete > 2) {
			s2[in] = s[i];
			in++;
		}
		else s2[i] = '\0';

		repete = 0;
	}
	
	err = fopen_s(&A, "out.txt", "w");
	if (err != 0) {
		perror("Ошибка открытия файла!");
		return;
	}
	fputs(s2, A);
	fclose(A);
	system("pause");
}*/
/*Написать функцию, которая в предложении подсчитывает количество
символов в слове максимальной длины (слова разделяются пробелами).
Опробовать работу функции на нескольких предложениях.*/


#include <iostream>
#include <stdarg.h>
#include <string>
using namespace std;
int maxs(const char*, ...);
int main() {
	setlocale(0, "");
	cout << maxs("у", "Алисы", "Точкар", "сегодня", "праздник",
		NULL) << endl;
	cout << maxs("16", "марта", "день", "Рождение", 
		NULL) << endl;
	cout << maxs("С", "днем", "Рождения", "Кроха", NULL) << endl;
	system("pause");
}
int maxs(const char* s1, ...) {
	va_list par;
	char* cp;
	int len = strlen(s1);
	va_start(par, s1);
	int max = strlen(s1);
	while (cp = va_arg(par, char*)) {
		len = strlen(cp);
		if (max < len) {
			max = len;
		}
	}
	va_end(par);
	return max;
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
