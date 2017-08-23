#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 205;
int n, m, tot, head[N], dis[N], pre[N], sum[N], cur[N];
struct data {
	int v, cap, next;
}e[N << 1];
void add(int x, int y, int z) {
	e[tot].cap = z, e[tot].v = y, e[tot].next = head[x], head[x] = tot++;
	e[tot].cap = 0, e[tot].v = x, e[tot].next = head[y], head[y] = tot++;
}
int isap(int st, int ed) {
	memset(dis, 0, sizeof(dis));
	memset(sum, 0, sizeof(sum));
	memset(pre, -1, sizeof(pre));
	for (int i = 1; i <= n; ++i)	cur[i] = head[i];
	int ans = 0;
	int u = pre[st] = st;
	int aug = -1;
	bool flag;
	sum[0] = n;
	while(dis[st] < n) {
		flag = 0;
		for (int &i = cur[u]; ~i; i = e[i].next) {
			int v = e[i].v;
			if (e[i].cap && dis[v] + 1 == dis[u]) {
				flag = 1;
				pre[v] = u;
				u = v;
				aug = (aug == -1) ? e[i].cap : min(aug, e[i].cap);
				if (v == ed) {
					ans += aug;
                     for (u = pre[v]; v != st; v = u, u = pre[u]) {
                         e[cur[u]].cap -= aug;
                         e[cur[u]^1].cap += aug;
                     }
                     aug=-1;
				}
				break;
			}
		}
		if (flag)	continue;
		int Min = n;
		for (int i = head[u]; ~i; i = e[i].next) {
			int v = e[i].v;
			if (e[i].cap && Min > dis[v]) {
				cur[u] = i;
				Min = dis[v];
			}
		}
		if (--sum[dis[u]] == 0)	break;
		dis[u] = Min + 1;
		++sum[dis[u]];
		u = pre[u];
	}
	return ans;
}
int main() {
	while (~scanf("%d%d", &m, &n)) {
		memset(head, -1, sizeof(head));
		tot = 0;
		for (int i = 1, x, y, z; i <= m; ++i) {
			scanf("%d%d%d", &x, &y, &z);
			add(x, y, z);
		}
		printf("%d\n", isap(1, n));
	}
	return 0;
}
