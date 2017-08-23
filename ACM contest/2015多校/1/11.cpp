#include <bits/stdc++.h>
using namespace std;
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
inline void read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
const int N = 105;
struct data {
	int x, y, z, d;
}a[N], b[N];
int n, m, p, q;
inline LL f(LL x) {
	return x * x;
}
bool gao(int x, int y, int z) {
	bool t = 0;
	for (int i = 1; i <= n; ++i)
		if ((LL)a[i].x * x + (LL)a[i].y * y + (LL)a[i].z * z + a[i].d > 0)	t ^= 1;
	for (int i = 1; i <= m; ++i)
		if (f(b[i].d) > f(b[i].x - x) + f(b[i].y - y) + f(b[i].z - z))	t ^= 1;
	return t;
}
int main() {
	int T;
	read(T);
	for (int tt = 1; tt <= T; ++tt) {
		if (tt > 1)	puts("");
		int ok = 1, mark = -1;
		read(n), read(m), read(p), read(q);
		for (int i = 1; i <= n; ++i)	read(a[i].x), read(a[i].y), read(a[i].z), read(a[i].d);
		for (int i = 1; i <= m; ++i)	read(b[i].x), read(b[i].y), read(b[i].z), read(b[i].d);
		for (int i = 1, x, y, z; i <= p; ++i) {
			read(x), read(y), read(z);
			if (!ok)	continue;
			bool t = gao(x, y, z);
			if (mark == -1)	mark = t;
			else if (mark != t)	ok = 0;
		}
		if (!ok)	puts("Impossible");
		for (int i = 1, x, y, z; i <= q; ++i) {
			read(x), read(y), read(z);
			if (!ok)	continue;
			bool t = gao(x, y, z);
			if (mark == -1)	puts("Both");
			else puts(mark == t ? "Y" : "R");
		}
	}
	return 0;
}
