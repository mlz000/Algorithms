#include <bits/stdc++.h>
using namespace std;
inline void read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
int n, m, cost, need, len;
int a[55], b[1005], sum[1005];
bool check(int x, int y) {
	if (len - cost < need)	return 0;
	bool f = 0;
	for (int i = x; i <= m; ++i) {
		if (a[i] >= b[y]) {
			a[i] -= b[y];
			if (a[i] < b[1])	cost += a[i];
			if (y == 1)	f = 1;
			else if (b[y - 1] == b[y])	f = check(i, y - 1);
			else f = check(1, y - 1);
			cost -= a[i];
			a[i] += b[y];
			if (f)	return 1;
		}
	}
	return 0;
}
int main() {
	read(m);
	for (int i = 1; i <= m; ++i)	read(a[i]);
	sort(a + 1, a + m + 1);
	read(n);
	for (int i = 1; i <= n; ++i)	read(b[i]);
	sort(b + 1, b + n + 1);
	while (b[n] > a[m])	--n;
	int tot = 0;
	for (int i = 1; i <= m; ++i)	
		if (a[i] > b[1])	a[++tot] = a[i], len += a[tot];
	for (int i = 1; i <= n; ++i)	sum[i] = sum[i - 1] + b[i];
	m = tot;
	int l = 1, r = n;
	int now = 0;
	while (l <= r) {
		int mid = l + r >> 1;
		cost = 0;
		need = sum[mid];
		if (check(1, mid))	now = mid, l = mid + 1;
		else r = mid - 1;
	}
	printf("%d\n", now);
	return 0;
}
