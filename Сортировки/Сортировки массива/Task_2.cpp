//3 номер задания
# include <iostream>
# include <fstream>
# include <cstdio>
# include <string>
# include <vector>
# include <algorithm>


using namespace std;

ifstream in("input.txt");//Открыть для ввода
ofstream out("output.txt");//Открыть для вывода

vector<vector<int>> create()// Ф-я для считывания матрицы
{
	int n;
	string count;
	in >> count;
	n = stoi(count);
	vector<vector<int>> matrix;
	for (int i = 0; i < n; i++) {
		vector<int> tempVec;
		for (int j = 0; j < n; j++) {
			string temp;
			in >> temp;
			int t = stoi(temp);
			tempVec.push_back(t);
		}
		matrix.push_back(tempVec);
	}
	return matrix;
}

//функция сортировки (поразрядная сортировка)
vector <int> LSDsort(vector <int> a) {
	int ms = 10;
	int maxras = 0, k = 1;//разряд максимального числа, разряд, который мы сравниваем на i-том шаге
	int n = a.size(); // количество сотрудников
	//нахождение максимального числа
	for (int i = 0; i < n; i++) {
		maxras = max(maxras, a[i]);
	}
	maxras = log10(maxras) + 1; // считаем количество разрядов
	// сортируем столько раз, сколько разрядов в самом большом числе
	for (int q = 1; q <= maxras; q++) {
		int temp = 0;//присвоение зачения 
		vector <int> mas(ms);//массив для хранения количества чисел, с одинаковыми цифрами в разрядах
		vector <vector <int> > dop_mas(n); // двумерный массив, в котором будут записаны частично отсортированные сотрудники
		for (int i = 0; i < n; i++) {
			dop_mas[i].resize(ms);
		}

		for (int i = 0; i < n; i++) {
			//определяем остаток текущего разряда
			int x = a[i] / k % 10;
			//записываем в позицию mas[x] сотрудника, отстаток i-ого разряда которого равен x
			dop_mas[mas[x]][x] = a[i];
			//увеличиваем позицию на единицу
			mas[x] += 1;
		}
		for (int i = 0; i < ms; i++) {
			for (int j = 0; j < mas[i]; j++) {
				//ставим элементы на свои места
				a[temp] = dop_mas[j][i];
				temp += 1;
			}
		}
		k *= 10;
	}
	return a;
}

vector<vector<int>> transp(vector<vector<int>> matrix) {//функция для транспонирования матрицы
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix.size(); j++) {
			if ((matrix[i][j] != matrix[j][i]) && j >= i) {
				matrix[i][j] = matrix[i][j] && matrix[j][i];//меняет местами
				matrix[j][i] = matrix[i][j] && matrix[j][i];//меняет местами
				matrix[i][j] = matrix[i][j] && matrix[j][i];//меняет местами
			}
		}

	}
	return matrix;
}


int main() {
	setlocale(LC_ALL, "RUS");//использование русской клавиатуры
	vector<vector <int>> numbers = create();
	int i = 0;
	numbers = transp(numbers);
	for (int i = 0; i < numbers.size(); i++)
	{
		numbers[i] = LSDsort(numbers[i]);
	}


	numbers = transp(numbers);
	for (int i = 0; i < numbers.size(); i++) {//вывод массива
		for (int j = 0; j < numbers.size(); j++) {
			cout << numbers[i][j] << ' ';
		}
		cout << "\n";
	}
	system("pause");//системная пауза 

}