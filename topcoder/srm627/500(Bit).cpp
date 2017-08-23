#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) ((int)x.size())
#define mp make_pair
#define F first
#define S second
const int N = 1005;
vector<int> g[N], V;
int ans = ~0u >> 1, k, c[N];
bool vis[N];
void add(int p, int x) {
	for (; p <= 1000; p += p & -p)	c[p] += x;
}
int gao(int p) {
	int t = 0;
	for (;p ; p -= p & -p)	t += c[p];
	return t;
}
void dfs(int u, int num, int x) {
	if (x == k) {
		ans = min(ans, num);
		return;
	}
	vis[u] = 1;
	for (int i = 0, v; i < sz(g[u]); ++i) {
		v = g[u][i];
		if (vis[v])	continue;
		int t = x - gao(V[v]);
		add(V[v], 1);
		dfs(v, t + num, x + 1);
		add(V[v], -1);
	}
	vis[u] = 0;
}
class GraphInversions {
	public:
	int getMinimumInversions(vector <int> A, vector <int> B, vector <int> VV, int K) {
		int n = sz(A);
		k = K;
		V = VV;
		for (int i = 0; i < n; ++i) {
			g[A[i]].pb(B[i]);
			g[B[i]].pb(A[i]);
		}
		for (int i = 0; i < n; ++i) {
			add(V[i], 1);
			dfs(i, 0, 1);
			add(V[i], -1);
		}
		if (ans == ~0u >> 1)	ans = -1;
		return ans;
	}
};
