#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string> 

using namespace std;



map<string, int> search(vector<string> vec, int n)
{
	map<string, int> m;
	for (int i = 0; i < n; i++)
		if (!isdigit(vec[i][0]))
			m[vec[i]]++;

	return m;
}

int main()

{

	setlocale(LC_ALL, "russian");

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	vector<string> vec(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}


	map<string, int> s = search(vec, n);

	for (auto i = s.begin(); i != s.end(); i++)
		cout << i->first <<" "<< i->second << endl;

	system("pause");
	return 0;
}