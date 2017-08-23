#include <bits/stdc++.h>
using namespace std;
const int N = 1005, M = 10005, inf = INT_MAX;
int n, m, a[N][M];
int getint() {
	char c;
	while (c = getchar(), c < '0' || c > '9');
	int t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	return t;
}
void pivot(const int &p, const int &e) {
	a[p][e] = -1;
	int pre = 0;
	static int next[M];
	for (int i = 1; i <= m; ++i)
		if (a[p][i] != 0)	next[pre] = i, pre = i;
	next[pre] = -1;
	for (int i = 0; i <= n; ++i)
		if (i != p && a[i][e] != 0) {
			int zoom = a[i][e];
			a[i][e] = 0;
			for (int j = 0; ~j; j = next[j])	a[i][j] += a[p][j] * zoom;
		}
}
int solve() {
	while (1) {
		int e = 0;
		for (int i = 1; i <= m; ++i) 
			if (a[0][i] > 0) {
				e = i;
				break;
			}
		if (!e)	return a[0][0];
		int v = inf, p;
		for (int i = 1; i <= n; ++i) 
			if (a[i][e] < 0 && a[i][0] < v) v = a[i][0], p = i;//选b/系数最小的，系数均为1
		pivot(p, e);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)	a[i][0] = getint();
	for (int i = 1; i <= m; ++i) {
		int l = getint(), r = getint(), d = getint();
		for (int j = l; j <= r; ++j)	a[j][i] = -1;//A矩阵
		a[0][i] = d;//C矩阵
	}
	printf("%d\n", solve());
	return 0;
}
