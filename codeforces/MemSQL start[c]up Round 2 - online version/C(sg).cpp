#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
const int N = 105;
int n, m, sg[N][3][3];
pii a[N];
int gao(int len, int x, int y) {
	if (~sg[len][x][y])	return sg[len][x][y];
	int &t = sg[len][x][y];
	if (x > y)	swap(x, y);
	if (!len)	return y ? 0 : 1;
	if (len == 1) {
		if (x == 1 && y == 2)	return t = 0;
		return t = 1;
	}
	bool f[105] = {};
	for (int i = 0; i < len; ++i) {
		int j = len - i - 1;
		if (!i) {
			if (!x)	f[gao(j, 1, y)] = f[gao(j, 2, y)] = 1;
			else f[gao(j, x, y)] = 1;
		}
		else if (!j) {
			if (!y)	f[gao(i, x, 1)] = f[gao(i, x, 2)] = 1;
			else f[gao(i, x, y)] = 1;
		}
		else {
			f[gao(i, x, 1) ^ gao(j, 1, y)] = 1;
			f[gao(i, x, 2) ^ gao(j, 2, y)] = 1;
		}
	}
	for (int i = 0; i < n; ++i)	
		if (!f[i])	return t = i;
	return t = 0;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1, x, y; i <= m; ++i) {
		scanf("%d%d", &x, &y);
		a[i] = mp(x, y);
	}
	a[0] = mp(0, 0), a[++m] = mp(n + 1, 0);
	sort(a, a + m + 1);
	memset(sg, -1, sizeof(sg));
	int ans = 0;
	for (int i = 1; i <= m; ++i)	ans ^= gao(a[i].F - a[i - 1].F - 1, a[i - 1].S, a[i].S);
	if (!ans)	puts("LOSE");
	else puts("WIN");
	return 0;
}
