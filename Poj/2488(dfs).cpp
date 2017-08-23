//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <climits>
#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define F first
#define S second
inline void read(LL &t) {
    int f = 1;char c;
    while (c = getchar(), c < '0' || c > '9') if (c == '-') f = -1;
    t = c - '0';
    while (c = getchar(), c >= '0' && c <= '9') t = t * 10 + c - '0';
    t *= f;
}
const int N = 30;
pair<int, int> p[N];
int n, m, T;
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
bool f, vis[N][N];
void dfs(int x, int y, int now) {
	if (f)	return ;
	p[now] = mp(x, y);	
	if (now == n * m) {
		f = 1;
		return ;
	}
	for (int i = 0; i < 8; ++i) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && !vis[tx][ty]) {
			vis[tx][ty] = 1;
			dfs(tx, ty, now + 1);
			vis[tx][ty] = 0;
		}
	}
}
int main() {
	scanf("%d", &T);
	for (int tt = 1; tt <= T; ++tt) {
		printf("Scenario #%d:\n", tt);
		scanf("%d%d", &m, &n);
		memset(vis, 0, sizeof(vis));
		memset(p, 0, sizeof(p));
		vis[1][1] = 1;
		f = 0;
		dfs(1, 1, 1);
		if (f) {
			for (int i = 1; i <= n * m; ++i)	printf("%c%d", p[i].F + 'A' - 1, p[i].S);
			puts("");
		}
		else puts("impossible");
		if (tt != T)	puts("");
	}
	return 0;
}
