#include <bits/stdc++.h>
using namespace std;
const int M = 60010, inf = 1e9;
int n, st, ed, tot, w[M << 1], sum[M << 1], head[M << 1], cur[M << 1], pre[M << 1], dis[M << 1];
struct data{
	int v, f, next;
}e[M << 4];
void add(int u, int v, int f) {
	e[tot].v = v, e[tot].f = f, e[tot].next = head[u], head[u] = tot++;
	e[tot].v = u, e[tot].f = 0, e[tot].next = head[v], head[v] = tot++;
}
int isap() {
	sum[0] = n;
	for (int i = st; i <= ed; ++i)	cur[i] = head[i];
	int aug = -1;
	int u = pre[st] = st;
	bool flag;
	int flow = 0;
	while (dis[st] < n) {
		flag = 0;
		for (int &i = cur[u]; ~i; i = e[i].next) {
			int v = e[i].v;
			if (e[i].f && dis[u] == dis[v] + 1) {
				flag = 1;
				pre[v] = u;
				u = v;
				aug = (aug == -1) ? e[i].f : min(aug, e[i].f);
				if (v == ed) {
					flow += aug;
					for (u = pre[v]; v != st; v = u, u = pre[u]) {
						e[cur[u]].f -= aug;
						e[cur[u] ^ 1].f += aug;
					}
					aug = -1;
				}
				break;
			}
		}
		if (flag)	continue;
		int Min = n;
		for (int i = head[u]; ~i; i = e[i].next) {
			int v = e[i].v;
			if (e[i].f && dis[v] < Min) {
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
int main() {
	int m, cnt = 0;
	scanf("%d%d", &n, &m);
	memset(head, -1, sizeof(head));
	memset(pre, -1, sizeof(pre));
	st = 0, ed = n + m + 1;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &w[i]);
		add(i + m, ed, w[i]);
	}
	for (int i = 1, x, y, z; i <= m; ++i) {
		scanf("%d%d%d", &x, &y, &z);
		add(st, i, z);
		add(i, x + m, inf), add(i, y + m, inf);
		cnt += z;
	}
	n = n + m + 2;
	cnt -= isap();
	printf("%d\n", cnt);
	return 0;
}
