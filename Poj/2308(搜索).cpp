//#include <bits/stdc++.h>
#include<cstdio>
#include<cstring>
#include<climits>
#include<iostream>
#include<queue>
#include<algorithm>
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
	int x, y, p, dir, tot;
	data(){}
	data(int x, int y, int p, int dir, int tot): x(x), y(y), p(p), dir(dir), tot(tot) {}
};
queue<data> Q;
typedef pair<int, int> pii;
const int N = 15;
char s[N][N];
int n, m, a[N][N], cnt[5];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
bool f, vis[N][N];
bool check() {
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j) {
			if (i == j)	continue;
			if (cnt[i] == cnt[j] && cnt[i] == 2) {
				for(int x = 0; x < n - 1; ++x)
					for (int y = 0; y < m - 1; ++y) {
						if (a[x][y] == i && a[x + 1][y + 1] == i && a[x][y + 1] == j && a[x + 1][y] == j)	return 1;
					}
			}
		}
	return 0;
}
bool dfs(int num) {
	if (!num)	return f = 1;
	if (check())	return 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			if (~a[i][j]) {
				memset(vis, 0, sizeof(vis));
				vector<pii> g;
				int now = a[i][j];
				Q.push(data(i, j, -1, -1, 0));
				vis[i][j] = 1;
				while (Q.size()) {
					data t = Q.front();
					Q.pop();
					for (int k = 0; k < 4; ++k) {
						int x = t.x + dx[k];
						int y = t.y + dy[k];
						if (x >= 0 && x < n && y >= 0 && y < m) {
							if (!vis[x][y] && (a[x][y] == -1 || a[x][y] == now)) {
								if (k == t.dir && t.tot <= 3)	vis[x][y] = 1, Q.push(data(x, y, a[x][y], k, t.tot));
								else if (k != t.dir && t.tot <= 2)	vis[x][y] = 1, Q.push(data(x, y, a[x][y], k, t.tot + 1));
								else continue;
								if (~a[x][y])	g.pb(mp(x, y));
							}
						}
					}
				}
				a[i][j] = -1;//delete
				cnt[now] -= 2;
				for (int k = 0; k < g.size(); ++k) {
					int x = g[k].F, y = g[k].S;
					a[x][y] = -1;
					dfs(num - 2);
					if (f)	return 1;
					a[x][y] = now;
				}
				a[i][j] = now;
				cnt[now] += 2;
			}
		}
	return 0;
}
int main() {
	while (scanf("%d%d", &n, &m) && n) {
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; ++i)	scanf("%s", s[i]);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				if (s[i][j] == '*')	a[i][j] = -1;
				else a[i][j] = s[i][j] - 'A', ++cnt[a[i][j]];
			}
		int tot = 0;
		f = 1;
		for (int i = 0; i < 4; ++i) {
			tot += cnt[i];
			if (cnt[i] & 1)	{
				f = 0;
				break;
			}
		}
		if (!f)	puts("no");
		else {
			f = 0;
			bool t = dfs(tot);
			printf("%s\n", t ? "yes" : "no");
		}
	}
	return 0;
}
