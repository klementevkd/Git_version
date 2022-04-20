#include <iostream>
#include <algorithm>
#include <iterator>
#include <deque>


using namespace std;

template <typename T>
void print(const T& coll)
{
    copy(coll.cbegin(), coll.cend(),
        ostream_iterator<typename T::value_type>(cout, " "));
    cout << endl;
}

int main()
{
    deque<int> coll{ 1, 1, 2, 2, 3, 3, 3, 4, 5, 5 };
    print(coll);

    size_t sz = coll.size();
    coll.erase(unique(coll.begin(), coll.end()), coll.end());
    print(coll);
    cout << "Number of deleted pairs: " << sz - coll.size() << endl;

    return 0;
}