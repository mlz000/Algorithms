#include <bits/stdc++.h>
using namespace std;
map<int, pair<int, string> > mp;
char s[15];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d%s", &x, s);
		mp[i] = make_pair(x, s);
	}
	int now = 0;
	for (int i = 0, x, y; i < m; ++i) {
		scanf("%d%d", &x, &y);
		if (x + mp[now].first == 1)	(now += y) %= n;
		else (now += n - y) %= n;
	}
	cout << mp[now].second << endl;
	return 0;
}
