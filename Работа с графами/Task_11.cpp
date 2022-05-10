// Дан ориентированный граф. Вывести все вершины, недостижимые из данной.
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

vector<vector<int>> input(){ // функция ввода списка смежности из файла
	ifstream in("input1.txt");// открываем файловый поток
	vector<vector<int>> vec;// создаем двумерный вектор
	int pos_n = 0, pos_p = 0, i = 0; // объявляем переменные
	string yhy = "", deal = ""; // объявление строк
	while (getline(in, yhy)){ // пока есть несчитанные строки
		vec.push_back(vector<int>()); // засовываем вектор в вектор
		do{
			pos_n = yhy.find(" ", pos_p);// Ищем пробел
			deal = yhy.substr(pos_p, pos_n - pos_p);// Выделяем число
			vec[i].push_back(atoi(deal.c_str()));// Добавляем его в вектор
			pos_p = pos_n + 1;// Обновляем позиции
		} while (pos_n != -1); // Пока можно считать цифры из строки
		i++; // Обновляем строку вектора
	}
	return vec; // Возвращаем двумерный вектор
}

int main(){
	setlocale(LC_ALL, "RUS");// подключение русской раскладки
	vector<vector<int>> vec;// cоздаем двумерный вектор
	vec = input();// записываем в него список смежности
	int peak = 0;  // объявление переменных
	cout << "Вершина: "; 
	cin >> peak;// ввод вершины
	int* nodes = new int[vec.size()];// создаем массив вершин
	for (int i = 0; i < vec.size(); i++){// изначально они все равны 0
		nodes[i] = 0;
	}
	queue<int> quan; // создаем очередь
	quan.push(peak); // записываем туда данную вершину 
	while (!quan.empty()){ // пока очередь не пуста
		int node = quan.front(); // извлекаем вершину
		quan.pop();
		nodes[node] = 2; // отмечаем вершину как посещенную
		for (int i = 0; i < vec[node].size(); i++){ // считываем все исходящие ребра из этой вершины
			if (vec[node][i] == 0 && vec[node].size() == 1) // если перед нами пустая строка
				break; // то выходим из цикла
			if (nodes[vec[node][i]] == 0) // если эта вершина не встречена и не обнаружена
				quan.push(vec[node][i]); // записываем  ее в очередь
			nodes[vec[node][i]] = 1; // отмечаем вершину как обнаруженную
		}
	}
	cout << "С [" << peak << "] вершины нельзя попасть: "; // вывод
	for (int i = 0; i < vec.size(); i++){
		if (nodes[i] == 0) // если вершина не обнаружена и не посещена, значит мы не добрались до нее в обходе
			cout << i << " "; // выводим ее
	}
	return 0; // возращаем 0
}
