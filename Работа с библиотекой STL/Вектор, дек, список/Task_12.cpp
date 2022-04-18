#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int X; //предикат может содержать только один параметр
bool odd(int x) {//не кратный X
	return x % X <1;
}
int main() {
	setlocale(LC_ALL, "Rus");
	int n,x, y;
	cout << "n= "; cin >> n;

	 
	 vector <int> vec;
	 for (int i = 0; i < n; i++)
	 {
		 cin >> x;
		 vec.push_back(x);
	 }
	 cout << "X = "; cin >> X;
	 auto it = remove_if(vec.begin(), vec.end(), odd);
	 vec.erase(it,vec.end());
	 sort(vec.begin(), vec.end());
	 for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
		 cout << *iter << " ";
	 cout << endl;
	
	 int a, b;
	 cout << "a="; cin >> a;
	 cout << "b="; cin >> b;
	 vector <int> v;
	 for (int i = 0; i < n; i++)
	 {
		 cin >> x;
		 v.push_back(x);
	 }
	 cout << "Y = "; cin >> y;
	 for (int i = 0; i < v.size(); i++) {
		 if (v[i] >= a && v[i] <= b)
			 v[i] = y;
	 }
	 sort(v.begin(), v.end());
	 for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)

		 cout << *iter << ' ';
	 cout << endl;
	 
	 vector <int> result((int)v.size() + (int)vec.size());
	 merge(vec.begin(), vec.end(), v.begin(), v.end(), result.begin()); //объединение последовательностей
	 for (vector<int>::iterator iter = result.begin(); iter != result.end(); iter++)
		 cout << *iter << " ";
	 cout << endl;
	system("pause");
	return 0;
}