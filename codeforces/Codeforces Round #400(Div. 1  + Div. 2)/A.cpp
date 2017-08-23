#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int main() {
	cin >> s1 >> s2;
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		string a, b;
		cin >> a >> b;
		cout << s1 << " " << s2 << endl;
		if (a == s1)	s1 = b;
		else s2 = b;
	}
	cout << s1 << " " << s2 << endl;
	return 0;
}
