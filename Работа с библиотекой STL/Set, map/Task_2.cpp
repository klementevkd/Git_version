#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

set <int> set_n(int n) {//функция которая делит числа на разряды
	set <int> S;
	while (n != 0) {
		S.insert(n % 10);
		n /= 10;
	}
	return S;
}

int main() {
	setlocale(LC_ALL, "Rus");
	set <int> s1, s0, s, res;
	int n, a;
	cout << "n=";
	cin >> n;

	cout << "Ввидите числа" << endl;
	for (int i = 0; i < n; i++) {//создаеться последовательность
		cout << "a[" << i << "]=";
		cin >> a;
		s = set_n(a);//последовыательности присваиваються значения из функции 
		if (a > 99 && a <= 999)
			s0.insert(s.begin(), s.end());//вставляет элемент 
		if (a > 9 && a <= 99)
			s1.insert(s.begin(), s.end());//вставляет элемент
	
	}

	set_difference(s1.begin(), s1.end(), s0.begin(), s0.end(), inserter(res, res.begin()));//функция ищет разность чисел в последовательостях и записывает ее в res
	cout << "цифры, которые встречаются в двузначных числах, но не встречаются в трехзначных:" << endl;
	for (set<int>::iterator it = res.begin(); it != res.end(); it++)
		cout << *it << " ";
	system("pause");
	return 0;
}