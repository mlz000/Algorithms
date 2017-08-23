#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100010;
int n, q, a[N], L[N], R[N], cnt[1500][N], num[1500][N];
LL c[N], sum[N];
inline int read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
void add(int i, int x) {
	for (;i <= n; i += i & -i)	c[i] += x;
}
void change(int i, int x) {
	add(i, x - a[i]);
	a[i] = x;
}
LL ask(int i) {
	LL t = 0;
	for (; i; i -= i & -i)	t += c[i];
	return t;
}
int main() {
	read(n);
	int bl = (int)sqrt(n + 0.5);
	int S = n / bl + ((n % bl) ? 1 : 0);
	for (int i = 1; i <= n; ++i)	read(a[i]);
	for (int i = 1; i <= n; ++i)	add(i, a[i]);
	for (int i = 0; i < n; ++i) {
		read(L[i]), read(R[i]);
		++cnt[i / bl][L[i]];
		--cnt[i / bl][R[i] + 1];
	}
	for (int i = 0; i < S; ++i) 
		for (int j = 1; j <= n; ++j) {
			num[i][j] = cnt[i][j] + num[i][j - 1];
			sum[i] += 1ull * num[i][j] * a[j];
		}
	read(q);
	while (q--) {
		int op, l, r;
		read(op), read(l), read(r);
		if (op == 1) {
			for (int i = 0; i < S; ++i)	sum[i] += 1ull * num[i][l] * (r - a[l]);
			change(l, r);
		}
		else {
			--l, --r;
			LL ans = 0;
			int x = l / bl, y = r / bl;
			if (x == y)	for (int i = l; i <= r; ++i)	ans += ask(R[i]) - ask(L[i] - 1);
			else{
				x = (l % bl ? x + 1 : x), y = (r + 1) % bl ? y - 1 : y;
				for (int i = x; i <= y; ++i)	ans += sum[i];
				while (l % bl)	ans += ask(R[l]) - ask(L[l++] - 1);
				while ((r + 1) % bl)	ans += ask(R[r]) - ask(L[r--] - 1);
			}
			printf("%llu\n", ans);
		}
	}
	return 0;
}
