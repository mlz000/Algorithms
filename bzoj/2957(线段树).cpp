#include <bits/stdc++.h>
using namespace std;
#define ls (rt << 1)
#define rs (rt << 1 | 1)
const int N = 100005;
int cnt[N << 2];
double mx[N << 2];
inline int read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
int calc(int rt, int l, int r, double x) {
	if (l == r)	return mx[rt] > x;
	int mid = l + r >> 1;
	if (mx[ls] <= x)	return calc(rs, mid + 1, r, x);
	else return cnt[rt] - cnt[ls] + calc(ls, l, mid, x);
}
void change(int rt, int l, int r, int p, double x) {
	if (l == r)	{
		mx[rt] = x;
		cnt[rt] = 1;
		return;
	}
	int mid = l + r >> 1;
	if (p <= mid)	change(ls, l, mid, p, x);
	else change(rs, mid + 1, r, p, x);
	mx[rt] = max(mx[ls], mx[rs]);
	cnt[rt] = cnt[ls] + calc(rs, mid + 1, r, mx[ls]);
}
int main() {
	int n, m, x, y;
	read(n), read(m);
	while (m--) {
		read(x), read(y);
		change(1, 1, n, x, (double) y / x);
		printf("%d\n", cnt[1]);
	}
	return 0;
}
