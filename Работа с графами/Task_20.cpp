// Дан ориентированный граф. Вывести все истоки графа.
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
	string yhy = "", deal = ""; //объявление строк
	while (getline(in, yhy)){ // пока есть несчитанные строки
		vec.push_back(vector<int>()); // записываем вектор в вектор
		do{
			pos_n = yhy.find(" ", pos_p);// ищем пробел
			deal = yhy.substr(pos_p, pos_n - pos_p); // выделяем число
			vec[i].push_back(atoi(deal.c_str()));// добавляем его в вектор
			pos_p = pos_n + 1;// обновляем позиции
		} while (pos_n != -1); // пока можно считать цифры из строки
		i++;// обновляем строку вектора
	}
	return vec; // возвращаем  двумерный вектор
}

int main(){
	setlocale(LC_ALL, "RUS"); // подключение русской раскладки 
	vector<vector<int>> vec; // создаем двумерный вектор
	vec = input();// записываем в него список смежности
	int* nodes = new int[vec.size()];// создаем массив вершин
	for (int i = 0; i < vec.size(); i++){ // изначально они все равны 0
		nodes[i] = 0;
	}
	int node = 0; // берем нулевую вершину
	while (node != vec.size()){ // пока не обойдем весь список
		for (int j = 0; j < vec.size(); j++){ // от 0 и до конца вектора
			if (j == node) // если встретили итерацию равную вершине 
				continue; // продолжаем
			for (int k = 0; k < vec[j].size(); k++){ // От 0 и до размеров vec[j]
				if (vec[j][k] == node && !(vec[j][k] == 0 && vec[j].size() == 1)){ // если встретили вершину в выходах других вершин
					nodes[node] = 1; // значит помечаем что в эту вершину есть вход, следовательно она не исток
					break; // Прерываем цикл
				}
			}
		}
		node++; // берем следующую вершину
	}
	for (int i = 0; i < vec.size(); i++){ // от 0 и до конца списка
		if (nodes[i] != 1) // если есть вершина в которую не входят другие значит она исток
			cout << "Узел [" << i << "] является истоком" << endl; // Выводим
	}
	return 0;// возвращение 0
}
