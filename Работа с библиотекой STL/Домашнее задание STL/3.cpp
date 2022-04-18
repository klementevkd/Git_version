#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <list>
#include <set>

using namespace std;

int main() {
    vector <int> a = { 2, 7, 5, 8, 3, 1, 6, 4, 11, 9 };
    
    for (vector<int>::iterator iter = a.begin(); iter != a.end(); iter++)
        cout << *iter << ' ';
    cout << endl;
    make_heap(a.begin(), a.end()); // формирование кучи
    cout << "after: ";
    for (vector<int>::iterator iter = a.begin(); iter != a.end(); iter++)
        cout << *iter << ' ';
    cout << endl;
}}