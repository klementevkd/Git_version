//15 задание 
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

ifstream in("input.txt");//Открыть для ввода
ofstream out("output.txt");//Открыть для вывода

int **massiv(int n) { //массив
	int **a = new int *[n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	for (int i = 0; i < n; i++) //заполняем массив
		for (int j = 0; j < n; j++) {
			in >> a[i][j];
		}
	return a;//возврат элемента a
}

void vsort(int **a, int n) { //сортировка вставками
	int j; int l;//объвление переменных 
	for (int k = 1; k < 2 * n - 2; k++) {
		vector<int> b; //создание вспомогательного вектора
		for (int i = 0; i < n; i++) //заполнение вспомогательного вектора
			if (k - i < n && k - i >= 0)
				b.push_back(a[i][k - i]);
		for (int i = 1; i < b.size(); i++) { //сортировка вектора
			j = i;
			while (j > 0 && b[j] < b[j - 1]) {
				swap(b[j], b[j - 1]);// меняем местами
				j--;//уменшьшаем на 1
			}
		}
		l = 0;//присвоивание значение l
		for (int i = 0; i < n; i++)
			if (k - i < n && k - i >= 0) {
				a[i][k - i] = b[l];
				l++;//прибовляем 1
			}
		b.clear(); //очистка вспомогательного вектора
	}
}

int main() {
	setlocale(LC_ALL, "RUS"); //использование русской клавиатуры
	int n; in >> n; int k = 0;
	int **a = massiv(n); //создаём массив
	vsort(a, n);//вызов функции
	for (int i = 0; i < n; i++) { //вывод массива
		for (int j = 0; j < n; j++)
			cout << a[i][j] << ' ';
		cout << '\n';
	}
	in.close();
	out.close();
	system("pause");//системная пауза
}