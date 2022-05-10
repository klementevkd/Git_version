// Дан неориентированный граф. Удалить ребро, соединяющее вершины А и B.
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue> 
using namespace std;

vector<vector<int>> input(){ // функция ввода списка смежности из файла
	ifstream in("input.txt"); // открываем файловый поток 
	vector<vector<int>> vec; // создаем двумерный вектор
	int pos_n = 0, pos_p = 0, i = 0; // объявляем переменные
	string yhy = "", deal = ""; // объявление строк
	while (getline(in, yhy)){ // пока есть несчитанные строки
		vec.push_back(vector<int>()); // засовываем вектор в вектор
		do{
			pos_n = yhy.find(" ", pos_p); // ищем пробел
			deal = yhy.substr(pos_p, pos_n - pos_p); // выделяем число
			vec[i].push_back(atoi(deal.c_str())); // добавляем его в вектор
			pos_p = pos_n + 1; // обновляем позиции
		} while (pos_n != -1); // пока можно считать цифры из строки
		i++; // обновляем строку вектора
	}
	return vec; // возвращаем готовый двумерный вектор
}

int main(){
	setlocale(LC_ALL, "RUS"); // поключение русской раскладки
	vector<vector<int>> vec; // создаем двумерный вектор
	vec = input(); // записываем в него список смежности
	int peakA = 0, peakB = 0; // переменные вершин
	vector<int> buf; // объявление вектора
	cout << "Вершина А: "; 
	cin >> peakA; // ввод вершины А
	cout << "Вершина В: ";
	cin >> peakB; // ввод вершин В
	for (int i = 0; i < vec[peakA].size(); i++){ // в цикле от 0 до количества выходных вершин
		if (!(vec[peakA][i] == peakB)) // все вершины не равные peakB
			buf.push_back(vec[peakA][i]); // записываем в буфферный вектор
	}
	vec[peakA] = buf; // записываем буфферный вектор на позицию peakA
	buf.clear(); // очищаем его

	for (int i = 0; i < vec[peakB].size(); i++){ // в цикле от 0 до количества выходных вершин
		if (!(vec[peakB][i] == peakA)) // все вершины не равные peakA
			buf.push_back(vec[peakB][i]); // записываем в буфферный вектор
	}
	vec[peakB] = buf; // записываем буфферный вектор на позицию peakB
	buf.clear(); // очищаем его

	int* nodes = new int[vec.size()]; // создаем массив вершин
	for (int i = 0; i < vec.size(); i++){ // изначально они все равны 0 (т.е не посещены и не обнаружены)
		nodes[i] = 0;
	}
	queue<int> quan; // создаем очередь
	quan.push(0); // записываем туда нулевую вершину
	while (!quan.empty()){ // пока очередь не пуста
		int node = quan.front(); // извлекаем вершину
		quan.pop();
		nodes[node] = 2; // отмечаем вершину как посещенную
		for (int i = 0; i < vec[node].size(); i++){ // считываем все исходящие ребра из этой вершины
			if (nodes[vec[node][i]] == 0) // если эта вершина не встречана и не обнаружена
				quan.push(vec[node][i]); // записываем ее в очередь
			nodes[vec[node][i]] = 1; // отмечаем вершину как обнаруженную
		}
		cout << "вершина: " << node << endl; // вывод вершины
	}
	return 0; // возвращение 0
}