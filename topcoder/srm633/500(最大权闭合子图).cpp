#include <bits/stdc++.h>//最大权闭合子图
using namespace std;
#define sz(x)	x.size() 
#define pb push_back
const int N = 60, inf = 1e6;
vector<int> g1[N], g2[N];
int tot, to[N * N << 1], cap[N * N << 1], nxt[N * N << 1], cur[N * N << 1], head[N], sum[N], pre[N], dis[N];
bool vis[N];
void add(int u, int v, int w) {
	to[tot] = v, cap[tot] = w, nxt[tot] = head[u], head[u] = tot++;
	to[tot] = u, cap[tot] = 0, nxt[tot] = head[v], head[v] = tot++;
}
void init(vector<int> score) {
	tot = 0;
	memset(pre, -1, sizeof(pre));
	memset(head, -1, sizeof(head));
	memset(cap, 0, sizeof(cap));
	memset(sum, 0, sizeof(sum));
	memset(dis, 0, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	int n = sz(score);
	for (int i = 0; i < n; ++i) {
		if (score[i] >= 0 )	add(0, i + 1, score[i]);
		else add(i + 1, n + 1, -score[i]);
	}
}
void dfs(vector<int> *g, int u, int fa) {
	if (fa != -1)	add(u + 1, fa + 1, inf);
	for (int i = 0; i < sz(g[u]); ++i) {
		int v = g[u][i];
		if (v == fa)	continue;
		dfs(g, v, u);
	}
}
int isap(int st, int ed) {
	int n = ed + 1;
	sum[0] = n;
	for (int i = st; i <= ed; ++i)	cur[i] = head[i];
	int u = pre[st] = st;
	int flow = 0, aug = -1;
	bool ok;
	while (dis[st] < n) {
		ok = 0;
		for (int &i = cur[u]; ~i; i = nxt[i]) {
			int v = to[i];
			if (cap[i] && dis[u] == dis[v] + 1) {
				ok = 1;
				pre[v] = u;
				u = v;
				aug = (aug == -1) ? cap[i] : min(cap[i], aug);
				if (v == ed) {
					flow += aug;
					for (u = pre[v]; v != st; v = u, u = pre[u]) {
						cap[cur[u]] -= aug;
						cap[cur[u] ^ 1] += aug;
					}
					aug = -1;
				}
				break;
			}
		}
		if (ok)	continue;
		int Min = n;
		for (int i = head[u]; ~i; i = nxt[i]) {
			int v = to[i];
			if (cap[i] && dis[v] < Min) {
				cur[u] = i;
				Min = dis[v];
			}
		}
		if (--sum[dis[u]] == 0)	break;
		dis[u] = Min + 1;
		++sum[dis[u]];
		u = pre[u];
	}
	return flow;
}
class DoubleTree {
    public:
	int maximalScore(vector <int> a, vector <int> b, vector <int> c, vector <int> d, vector <int> score) {
		int n = sz(a);
		for (int i = 0; i < n; ++i)	g1[a[i]].pb(b[i]), g1[b[i]].pb(a[i]), g2[c[i]].pb(d[i]), g2[d[i]].pb(c[i]);
		int ans = 0, s = 0;
		for (int i = 0; i <= n; ++i)	
			if (score[i] > 0)	s += score[i];
		for (int i = 0; i <= n; ++i) {
			init(score);
			dfs(g1, i, -1), dfs(g2, i, -1);
			ans = max(ans, s - isap(0, n + 2));
		}
		return ans;
	}
};
