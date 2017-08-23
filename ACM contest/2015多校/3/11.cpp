#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#pragma comment(linker, "/STACK:1024000000,1024000000") 
typedef long long LL;
inline void read(LL &t) {
    int f = 1;char c;
    while (c = getchar(), c < '0' || c > '9') if (c == '-') f = -1;
    t = c - '0';
    while (c = getchar(), c >= '0' && c <= '9') t = t * 10 + c - '0';
    t *= f;
}
const int N = 105;
vector<int> g[N];
int du[N], sum[N];
void dfs(int u, int fa) {
	if (g[u].size() == 0) {
		sum[u] = 0;
		return;
	}
	for (int i = 0, v; i < g[u].size(); ++i) {
		v = g[u][i];
		if (v == fa)	continue;
		dfs(v, u);
		sum[u] += sum[v] + 1;
	}
}
int main() {
	int n, k;
	while (scanf("%d%d", &n, &k) != EOF) {
		memset(du, 0, sizeof(du));
		memset(sum, 0, sizeof(sum));
		for (int i = 1; i <= n; ++i)	g[i].clear();
		for (int i = 1, a, b; i < n; ++i) {
			scanf("%d%d", &a, &b);
			g[a].pb(b);
			du[b]++;
		}
		int p = 0;
		for (int i = 1; i <= n; ++i)
			if (!du[i])	{
				p = i;
				break;
			}
		dfs(p, 0);
		int ans = 0;
		for (int i = 1; i <= n; ++i)
			if (sum[i] == k)	++ans;
		cout << ans << endl;
	}
	return 0;
}
