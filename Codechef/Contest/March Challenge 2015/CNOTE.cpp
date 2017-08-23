#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int p[N], c[N];
inline void read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
int main() {
	int T;
	read(T);
	while (T--) {
		int x, y, k, n;
		read(x), read(y), read(k), read(n);
		bool f = 0;
		for (int i = 1, p, c; i <= n; ++i) {
			read(p), read(c);
			if (p >= x - y && c <= k)	f = 1;
		}
		printf("%s\n", f ? "LuckyChef" : "UnluckyChef");
	}
	return 0;
}
