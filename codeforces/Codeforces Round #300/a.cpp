#include <bits/stdc++.h>
using namespace std;
string t = "CODEFORCES";
string s;
int main() {
	cin >> s;
	int l = s.length();
	for (int i = 0; i < l; ++i)
		for (int j = 0; j < l; ++j)
			if (s.substr(0, i) + s.substr(j + 1) == t) {
				cout << "YES" << endl;
				return 0;
			}
	cout << "NO" << endl;
	return 0;
}
