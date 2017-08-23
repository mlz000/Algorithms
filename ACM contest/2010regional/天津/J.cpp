#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 100005, M = 65;
#define X first
#define Y second
pair<int, int> a[M];
int l[N], match[M];
bool vis[N];
bool dfs(int u) {
	for (int i = a[u].X; i <= a[u].Y; ++i)
		if (!vis[i]) {
			vis[i] = 1;
			if (!l[i] || dfs(l[i])) {
				l[i] = u;
				match[u] = 1;
				return 1;
			}
		}
	return 0;
}
int main() {
	int n, T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)	scanf("%d%d", &a[i].X, &a[i].Y);
		memset(l, 0, sizeof(l));
		memset(match, 0, sizeof(match));
		int ans = 0;
		for (int i = n; i >= 1; --i) {
			memset(vis, 0, sizeof(vis));
			if (dfs(i))	++ans;
		}
		printf("%d\n", ans);
		for (int i = 1; i <= n; ++i) {
			if (match[i]) {
				--ans;
				printf("%d", i);
				if (ans)	printf(" ");
				else printf("\n");
			}
		}
	}
	return 0;
}
