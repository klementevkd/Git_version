#include <iostream>
#include <set>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream input;
	input.open("input.txt");
	string s;
	set <string> strs;
	set <string> ans;
	while (!input.eof()) {
		input >> s;

		if (s[s.size() - 1] != '!' && s[s.size() - 1] != '?' && s[s.size() - 1] != '.') {
			s[0] = tolower(s[0]);
			strs.insert(s);
		}
		else {
			strs.insert(s.substr(0, s.size() - 1));
			if (s[s.size() - 1] == '.') {
				for (set<string>::iterator it = strs.begin(); it != strs.end(); it++) {
					string temp = *it;
					ans.insert(temp);
				}
			}
			strs.clear();
		}
	}
	for (set<string>::iterator it = ans.begin(); it != ans.end(); it++) {
		cout << *it << " ";
	}

}