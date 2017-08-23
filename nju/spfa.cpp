#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int N = 22, M = 105;
char s1[N], s2[N];
int n, m, w[M], u[M][2], v[M][2], d[1 << N], inf = (int)1e9;
bool vis[1 << N];
void init() {
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= m; ++i) {
		scanf("%d%s%s", &w[i], s1, s2);
		u[i][1] = u[i][0] = v[i][1] = 0;
		v[i][0] = (1 << n) - 1;
		for (int j = 0; j < n; ++j) {
			if (s1[j] == '+')	u[i][1] |= (1 << j);
			if (s1[j] == '-')	u[i][0] |= (1 << j);
			if (s2[j] == '+')	v[i][1] |= (1 << j);
			if (s2[j] == '-')	v[i][0] ^= (1 << j);
		}
	}
}
void spfa() {
	for (int i = 0; i < (1 << n) + 5; ++i)	d[i] = inf;
	d[(1 << n) - 1] = 0;
	queue<int> q;
	q.push((1 << n) - 1);
	vis[(1 << n) - 1] = 1;
	while (q.size()) {
		int st = q.front();
		q.pop();
		vis[st] = 0;
		for (int i = 1; i <= m; ++i) {
			if ((st | u[i][1]) == st && (st & u[i][0]) == 0) {
				int ed = st;
				ed |= v[i][1];
				ed &= v[i][0];
				if (d[st] + w[i] < d[ed]) {
					d[ed] = d[st] + w[i];
					if (!vis[ed]) {
						vis[ed] = 1;
						q.push(ed);
					}
				}
			}
		}
	}
	if (d[0] == inf)	printf("Bugs cannot be fixed.\n\n");
	else printf("Fastest sequence takes %d seconds.\n\n", d[0]);	
}
int main() {
	int tt = 0;
	while (scanf("%d%d", &n, &m) != EOF) {
		if (!n && !m)	break;
		printf("Product %d\n",++tt);
		init();
		spfa();
	}
	return 0;
}
