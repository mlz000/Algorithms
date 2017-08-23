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
struct data {
	int x, y, dir, step;
	data(){}
	data(int x, int y, int dir, int step): x(x), y(y), dir(dir), step(step) {}
};
queue<data> Q;
const int N = 60;
bool vis[N][N][4];
int n, m, a[N][N];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
map<string, int> g;
int main() {
	g["north"] = 0, g["east"] = 1, g["south"] = 2, g["west"] = 3;
	while (scanf("%d%d", &n, &m) && n) {
		memset(vis, 0, sizeof(vis));
		memset(a, 1, sizeof(a));
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j) {
				scanf("%d", &a[i][j]);
				if (a[i][j])	a[i][j - 1] = a[i - 1][j] = a[i - 1][j - 1] = 1;
				if (i == n || j == m)	a[i][j] = 1;
			}
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		char s[10];
		scanf("%s", s);
		while (Q.size())	Q.pop();
		Q.push(data(x1, y1, g[s], 0));
		vis[x1][y1][g[s]] = 1;
		bool f = 0;
		while(Q.size()) {
			data t = Q.front();
			Q.pop();
			if (t.x == x2 && t.y == y2) {
				printf("%d\n", t.step);
				f = 1;
				break;
			}
			for (int i = 1; i <= 3; ++i) {
				int x = t.x + dx[t.dir] * i;
				int y = t.y + dy[t.dir] * i;
				int dir = t.dir;
				int step = t.step + 1;
				if (a[x][y])	break;
				if (!vis[x][y][dir])	vis[x][y][dir] = 1, Q.push(data(x, y, dir, step));
			}
			for (int i = 1; i <= 2; ++i) {
				int x = t.x, y = t.y, step = t.step + 1, dir = (t.dir + i * 2 - 1) % 4;
				if (!vis[x][y][dir])	vis[x][y][dir] = 1, Q.push(data(x, y, dir, step));
			}
		}
		if (!f)	puts("-1");
	}
	return 0;
}
