#include <iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main() {
	setlocale(LC_ALL, "russian");
	int n;//����������� �������
	cout << "n = "; //����� �� ����� ������� n=
	cin >> n;//���� ��������� n
	vector<int> vec;
	int x;
	for (int i = 0; i < n; i++) {//�������� �������
		cout << "a[" << i << "] = ";
		cin >> x;
		vec.push_back(x);
	}

	int maxElement = *max_element(vec.begin(), vec.end());
	auto it = vec.cbegin(); // ����������� �������� ��������� �� ������ �������
	auto itt = find(vec.begin(), vec.end(), maxElement) - vec.begin();
	vec.insert(it, maxElement);
	vec.erase(vec.begin() + itt +1);
	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
		cout << *iter << " ";// ����� ��-��� � ������
	cout << endl;
	return 0;
}