#include <iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

int main() {
	setlocale(LC_ALL, "russian");
	int n;                                        //размерность вектора
	cout << "n=";                                 //вывод на экран надписи n=
	cin >> n;                                     //ввод перменной n
	vector<int> vec;
	int a, b,x;
	for (int i = 0; i < n; i++) {                 //создание вектора
		cout << "a[" << i << "] = ";
		cin >> x;
		vec.push_back(x);
	}
	cin >> a;                                     //ввод переменной а
	cin >> b;                                     //ввод переменной б
	int sum =accumulate(vec.begin(), vec.end(), 0, [a, b](int& s, int& x) {return s += (x<a || x>b ? x : 0); });
	cout << sum;                                  //вывод суммы
	return 0;
	system("pause");
}