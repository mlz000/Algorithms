#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
const int N = 205, M = 505, K = 205; 	
vector<int> g[M * K], now;
int n, m, k, cnt, ans[M], l[N];
bool mp[N][N];
bool vis[N];
void dfs(int x) {
	vis[x] = 1;
	now.pb(x);
	for (int i = 1; i <= n; ++i) 
		if (mp[x][i] && !vis[i]) 
			dfs(i);
}
bool can(int u) {
	for (int i = 0, v; i < g[u].size(); ++i) {
		v = g[u][i];
		if (!vis[v]) {
			vis[v] = 1;
			if (l[v] == -1 || can(l[v])) {
				l[v] = u;
				return 1;
			}
		}
	}
	return 0;
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &n, &m, &k);
		cnt = 0;
		memset(mp, 0, sizeof(mp));
		memset(l, -1, sizeof(l));
		memset(ans, 0, sizeof(ans));
		while (m--) {
			int op, x, y;
			scanf("%d", &op);
			if (op == 1) {
				scanf("%d", &x);                           
		        memset(vis, 0, sizeof(vis));
				now.clear();
				dfs(x);
				for (int i = cnt * k + 1; i <= (cnt + 1) * k; ++i)
					for (int j = 0; j < now.size(); ++j)
						g[i].pb(now[j]);
				++cnt;
			}
			else if (op == 2) {
				scanf("%d%d", &x, &y);
				mp[x][y] = mp[y][x] = 1;
			}
			else {
				int num;
				scanf("%d", &num);
				while (num--) {
					scanf("%d%d", &x, &y);
					mp[x][y] = mp[y][x] = 0;
				}
			}
		}
		int sum = 0;
		for (int i = cnt - 1; i >= 0; --i)
			for (int j = i * k + 1; j <= (i + 1) * k; ++j) {
				memset(vis, 0, sizeof(vis));
				if (can(j)) {
					++sum;
					++ans[i];
				}
			}
		printf("%d\n", sum);
		for (int i = 0; i < cnt - 1; ++i)	printf("%d ", ans[i]);
		printf("%d\n", ans[cnt - 1]);
		for (int i = 0; i <= cnt * k; ++i)	g[i].clear();
	}
	return 0;
}
