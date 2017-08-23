#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F first 
#define S second
#define mp make_pair
#define pb push_back
const int N = 55, M = 1005;
int n, tot, cnt, x[205], y[205], du[N], g[N][M], nxt[M], l[M], belong[M], mark[M], vis[M];
queue <int> q;
vector<int> E[M];
int find(int x) {
	return belong[x] == x ? x : belong[x] = find(belong[x]);
}
void Union(int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx != fy)	belong[fx] = fy;
}
int lca(int x, int y) {
	++tot;
	while (1) {
		if (x != -1) {
			x = find(x);
			if (vis[x] == tot)	return x;
			vis[x] = tot;
			if (l[x] != -1)	x = nxt[l[x]];
			else x = -1;
		}
		swap(x, y);
	}
}
void group(int x, int p) {
	while(x != p) {
		int y = l[x], z = nxt[y];
		if (find(z) != p)	nxt[z] = y;
		if (mark[y] == 2) {
			mark[y] = 1;
			q.push(y);
		}
		if (mark[z] == 2)	{
			mark[z] = 1;
			q.push(z);
		}
		Union(x, y);
		Union(y, z);	
		x = z;
	}
}
void dfs(int st) {
	while(q.size())	q.pop();
	for (int i = 1; i <= n; ++i)	nxt[i] = vis[i] = -1, mark[i] = 0, belong[i] = i;
	q.push(st);
	mark[st] = 1;//S型点
	while(q.size() && l[st] == -1) {
		int x = q.front();
		q.pop();		
		for (int i = 0, y; i < (int)E[x].size(); ++i) {
			y = E[x][i];
			if (l[x] != y && find(x) != find(y) && mark[y] != 2) {
				if (mark[y] == 1) {		//奇环缩点
					int p = lca(x, y);
					if (find(x) != p)	nxt[x] = y;
					if (find(y) != p)	nxt[y] = x;
					group(x, p);
					group(y, p);
				}
				else if (l[y] == -1) {	//y可增广
					nxt[y] = x;
					for (int u = y; u != -1;) {
						int v = nxt[u];
						int t = l[v];
						l[v] = u;
						l[u] = v;
						u = t;
					}
					break;//succeed
				}
				else {
					nxt[y] = x;
					mark[l[y]] = 1;	//l[y]为S型
					mark[y] = 2;	//y为T型
					q.push(l[y]);
				}
			}
		}
	}
}	
int main() {
	int T, m;
	scanf("%d", &T);
	for (int tt = 1; tt <= T; ++tt) {
		cnt = tot = 0;
		printf("Case %d: ", tt);
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= 1000; ++i)	E[i].clear();
		for (int i = 1; i <= m; ++i)	scanf("%d%d", &x[i], &y[i]);
		for (int i = 1; i <= n; ++i)	scanf("%d", &du[i]);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= du[i]; ++j)
				g[i][j] = ++cnt;
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= du[x[i]]; ++j)	E[g[x[i]][j]].pb(cnt + 1), E[cnt + 1].pb(g[x[i]][j]);
			for (int j = 1; j <= du[y[i]]; ++j)	E[g[y[i]][j]].pb(cnt + 2), E[cnt + 2].pb(g[y[i]][j]);
			E[cnt + 1].pb(cnt + 2), E[cnt + 2].pb(cnt + 1);
			cnt += 2;
		}
		n = cnt;
		int ans = 0;
		for (int i = 1; i <= cnt; ++i)	l[i] = -1;
		for (int i = 1; i <= cnt; ++i)
			if (l[i] == -1)	dfs(i);
		for (int i = 1; i <= cnt; ++i)
			if (~l[i])	++ans;
		printf("%s\n", cnt == ans ? "YES" : "NO");
	}
	return 0;
}
