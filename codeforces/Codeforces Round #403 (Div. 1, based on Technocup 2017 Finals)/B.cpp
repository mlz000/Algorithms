#include <bits/stdc++.h>
using namespace std;
#define pb push_back
map<string, bool> used, nok;
vector<string> ans;
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		string a, b;
		cin >> a >> b;
		a = a.substr(0, 3);
		b = a.substr(0, 2) + b.substr(0, 1);
		if (!used[b]) {
			used[b] = 1;
			ans.pb(b);
		}
		else {
			if (used[a] || nok[a]) {
				puts("NO");
				return 0;
			}
			else {
				used[a] = 1;
				ans.pb(a);
			}
		}
		nok[a] = 1;
	}
	puts("YES");
	for (auto s : ans)	cout << s << endl;
	return 0;
}

