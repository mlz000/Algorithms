#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
string f[N], s[N];
int p[N];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)	cin >> f[i] >> s[i];
	for (int i = 1, x; i <=n; ++i) {
		scanf("%d", &x);
		p[i] = x;
	}
	string last = "0";
	for (int i = 1; i <= n; ++i) {
		string a = min(f[p[i]], s[p[i]]);
		string b = max(f[p[i]], s[p[i]]);
		if (a > last || b > last) {
			if (a > last)	last = a;
			else last = b;
		}
		else {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}
