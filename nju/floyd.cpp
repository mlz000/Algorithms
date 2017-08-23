#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 105, inf = (int)1e8;
int d[N][N];
int main() {
	int c, s, q;
	int tt = 0;
	while (scanf("%d%d%d", &c, &s, &q) != EOF) {
		if (!c && !s && !q)	break;
		if(tt++)	puts("");
		printf("Case #%d\n", tt);
		for (int i = 1; i <= c; ++i) {
			for (int j = 1; j <= c; ++j)	d[i][j] = inf;
			d[i][i] = 0;
		}
		for (int i = 1, x, y, z; i <= s; ++i) {
			scanf("%d%d%d", &x, &y, &z);
			d[x][y] = d[y][x] = z;
		}
		for (int k = 1; k <= c; ++k)
			for (int i = 1; i <= c; ++i)
				for (int j = 1; j <= c; ++j) {
					if (d[i][k] != inf && d[k][j] != inf) {
						int t = max(d[i][k], d[k][j]);
						if (d[i][j] == inf || t < d[i][j])	d[i][j] = t;
					}
				}
		while (q--) {
			int x, y;
			scanf("%d%d", &x, &y);
			if (d[x][y] == inf)	puts("no path");
			else printf("%d\n", d[x][y]);
		}
	}
	return 0;
}
