#include <bits/stdc++.h>
using namespace std;
#define sz(x)	x.size() 
#define F first
#define S second
#define pb push_back
#define mp make_pair
typedef pair<long long, int>pli;
const int N = 1005;
const long long inf = 1e18;
vector<pli> g[N], rg[N];
bool vis[N];
long long f[N], dp[N][N];
class MaliciousPath {
    public:
	long long minPath(int n, int K, vector <int> from, vector <int> to, vector <int> cost) {
		int m = sz(from);
		for (int i = 0; i < m; ++i) {
			g[from[i]].pb(mp(cost[i], to[i]));
			rg[to[i]].pb(mp(cost[i], from[i]));
		}
		for (int k = 0; k <= K; ++k) {
			for (int i = 0; i < n; ++i) {
				dp[k][i] = inf;
				f[i] = 0;
				if (k) {
					for (int j = 0, v; j < sz(g[i]); ++j) {
						v = g[i][j].S;
						f[i] = max(f[i], dp[k - 1][v] +  g[i][j].F);
					}
				}
			}
			for (int i = 0; i < n; ++i)	vis[i] = 0;
			dp[k][n - 1] = 0;
			priority_queue<pli> q;
			q.push(mp(0, n - 1));
			while (q.size()) {
				int u = q.top().S;
				q.pop();
				if (vis[u])	continue;
				vis[u] = 1;
				for (int i = 0, v; i < rg[u].size(); ++i) {
					v = rg[u][i].S;
					long long t = dp[k][u] + rg[u][i].F;
					t = max(t, f[v]);
					if (t < dp[k][v]) {
						dp[k][v] = t;
						q.push(mp(-t, v));
					}
				}
			}
		}
		if (dp[K][0] == inf)	dp[K][0] = -1;
		return dp[K][0];
	}
};
