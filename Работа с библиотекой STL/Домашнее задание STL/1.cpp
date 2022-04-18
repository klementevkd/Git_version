#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <list>
#include <set>

int main() {
    int n;
    cout << "n = "; cin >> n;
    vector <int> a = { 2, 7, 5, 8, 3, 1, 6, 4, 11, 9 };
    
    for (vector<int>::iterator iter = a.begin(); iter != a.end(); iter++)
        cout << *iter << ' ';
    cout << endl;
    nth_element(a.begin(), a.begin() + n, a.end()); // формирование последовательности таким образом, чтобы до n-го элемента были те, что меньше его, а после - больше
    cout << "after: ";
    for (vector<int>::iterator iter = a.begin(); iter != a.end(); iter++)
        cout << *iter << ' ';
    cout << endl;
}}