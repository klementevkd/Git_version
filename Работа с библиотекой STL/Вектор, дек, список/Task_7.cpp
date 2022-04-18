#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;


bool odd(int x) {//четные
	return x % 2 == 0;
}

int X; //предикат может содержать только один параметр

bool kratn(int x) {//не кратный X
	return x % X != 0;
}

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
	vector<int> temp(vec); //копия вектора
	vector<int> kol(vec); //копия вектора

	cout << "Удаление четных элементов:\n";
	vector<int>::iterator it = remove_if(vec.begin(), vec.end(), odd);
	vec.erase(it, vec.end());

	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
		cout << *iter << " ";// вывод эл-тов в строку
	cout << endl;

	cout << "Замена максимальных\n";
	int Max = *max_element(temp.begin(), temp.end());
	int Min = *min_element(vec.begin(), vec.end());
	replace(temp.begin(), temp.end(), Max, Min);

		for (vector<int>::iterator iter = temp.begin(); iter != temp.end(); iter++)
		cout << *iter << " ";// вывод эл-тов в строку
	cout << endl;


	cout << "X = "; cin >> X;
	cout << "Количевство кратных элементов = ";
	replace_if(kol.begin(), kol.end(), kratn, 0);
	cout << kol.size() - count(kol.begin(), kol.end(), 0);
	cout << endl;


	system("pause");
	return 0;
}