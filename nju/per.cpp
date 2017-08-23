#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int n, m, x, cnt, ans[1000005][15],a[15],v[15];
void dfs(int d) {
	if (d == n) {
		cnt++;
		for (int i = 0; i < n; ++i) ans[cnt][i] = a[i];
		return;
	}
	for (int i = 1; i <= n; ++i) {
		if (v[i]) continue;
		v[i] = 1;
		a[d] = i;
		dfs(d + 1);
		v[i] = 0;
	}
}
int main() {
	while (scanf("%d%d",&n,&m) != EOF) {
		memset(v, 0, sizeof(v));
		dfs(0);
		while (m--) {
			scanf("%d", &x);
			printf("{%d", ans[x][0]);
			for (int i = 1; i < n; ++i)
				printf(",%d", ans[x][i]);
			printf("}\n");
		}
	}
	return 0;
}

