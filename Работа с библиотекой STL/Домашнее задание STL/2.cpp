#include <iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main() {
	setlocale(LC_ALL, "russian");
	int n;//размерность вектора
	cout << "n = "; //вывод на экран надписи n=
	cin >> n;//ввод перменной n
	vector<int> vec;
	int x;
	for (int i = 0; i < n; i++) {//создание вектора
		cout << "a[" << i << "] = ";
		cin >> x;
		vec.push_back(x);
	}

	int maxElement = *max_element(vec.begin(), vec.end());
	auto it = vec.cbegin(); // константный итератор указывает на первый элемент
	auto itt = find(vec.begin(), vec.end(), maxElement) - vec.begin();
	vec.insert(it, maxElement);
	vec.erase(vec.begin() + itt +1);
	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
		cout << *iter << " ";// вывод эл-тов в строку
	cout << endl;
	return 0;
}