//7 задание
# include <iostream>
# include <fstream>
# include <cstdio>
# include <string>
# include <vector>
# include <algorithm>


using namespace std;

ifstream in("input.txt");//Открыть для ввода
ofstream out("output.txt");//Открыть для вывода

//структура для записи информации о сотруднике 
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
			if (i % 2 != 0) {
				t *= (-1);
			}
			tempVec.push_back(t);
		}
		matrix.push_back(tempVec);
	}
	return matrix;
}

vector<int> shellSort(vector<int> a) {//функция шелла с шагом d=3^i-1
	int step;//объявлеие переменных
	int temp = 1;
	while (pow(3, temp) - 1 < a.size() - 1) {//условие 
		temp++;//temp плюс 1
	}
	step = pow(3, temp) - 1;//step увеличиаветься в 3 в степени temp
	while (step > 0) {//cколько раз прйдет раз цыкл
		for (int i = 0; i < a.size() - step; i++) {
			int j = i;
			while ((j >= 0) && (a[j] > a[j + step])) {
				swap(a[j], a[j + step]);//меняет местами
				j -= step;
			}
		}
		temp--;
		step = pow(3, temp) - 1;
		if (temp == 0) {
			step++;
		}
	}
	return a;
}









int main() {
	setlocale(LC_ALL, "RUS");//использование русской клавиатуры
	vector <vector<int>> matrix = create();
	for (int i = 0; i < matrix.size(); i++) {
		matrix[i] = shellSort(matrix[i]);
	}
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix.size(); j++) {
			if (i % 2 != 0) {
				matrix[i][j] *= (-1);
			}
			cout << matrix[i][j] << ' ';
		}
		cout << "\n";
	}
	system("pause");//системная пауза 
	return 0;
}