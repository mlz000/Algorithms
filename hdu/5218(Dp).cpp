#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <climits>
#include <stack>
#include <queue>
using namespace std;
typedef long long LL;
#pragma comment(linker, "/STACK:102400000,102400000") 
#define pb push_back
#define mp make_pair
#define F first
#define S second
const int N = 205;
int a[N], pos[N], f[N][N];
vector<int> g[N];
int main() {
	int n, m, T;
	scanf("%d", &T);
	while (T--) {
		memset(f, 0, sizeof(f));
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i)	g[i].clear();
		for (int i = 1; i <= m; ++i)	scanf("%d", &a[i]);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				int t = (a[j] - 1) % i + 1;
				g[i].pb(t);
			}
			sort(g[i].begin(), g[i].end());
			unique(g[i].begin(), g[i].end());
		}
		f[1][1] = 1;
		for (int i = 2; i <= n; ++i)
			for (int j = 1; j <= i; ++j) 
				for (int k = 0; k < g[i].size(); ++k) {
					int t = g[i][k];
					if (t == j)	continue;
					if (t < j)	f[i][j] |= f[i - 1][j - t];
					else f[i][j] |= f[i - 1][i - t + j];
				}
		vector<int> ans;
		for (int i = 1; i <= n; ++i)
			if (f[n][i])	ans.pb(i);
		printf("%d\n", ans.size());
		for (int i = 0; i < ans.size() - 1; ++i) printf("%d ", ans[i]);
		printf("%d\n", ans[ans.size() - 1]);
	}
	return 0;
}
