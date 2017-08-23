#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 505;
bool g[N][N], v[N];
int n, m, l[N];
bool can (int u) {
    for (int i = 1; i <= n; ++i){
        if (!v[i] && g[u][i]) {
            v[i] = 1;
            if(!l[i] || can(l[i])) {
                l[i] = u;
                return 1;
            }
        }
    }
    return 0;
}
int main() {
	while (~scanf("%d%d", &n, &m)) {
		memset(g, 0, sizeof(g));
		while (m--) {
			int a, b;
			scanf("%d%d", &a, &b);
			g[a][b] = 1;
		}
		int ans = 0;
		memset(l, 0, sizeof(l));
		for (int i = 1; i <= n; ++i) {
			memset(v, 0, sizeof(v));
			if (can(i))	++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}

