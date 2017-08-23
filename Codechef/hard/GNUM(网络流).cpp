#include <bits/stdc++.h>
using namespace std;
const int N = 405, M = 1e6 + 5;
int tot, c1, c2, a[N], b[N], num1[M], num2[M], cnt1[M], cnt2[M], to[M], cap[M], nxt[M], head[M], pre[M], sum[M], dis[M], cur[M];
map<int, int> A, B;
void add(int u, int v, int w) {
	to[tot] = v, cap[tot] = w, nxt[tot] = head[u], head[u] = tot++;
	to[tot] = u, cap[tot] = 0, nxt[tot] = head[v], head[v] = tot++;
}
void init() {
	A.clear(), B.clear();
	c1 = c2 = tot = 0;
	memset(cnt1, 0, sizeof(cnt1));
	memset(cnt2, 0, sizeof(cnt2));
	memset(pre, -1, sizeof(pre));
	memset(head, -1, sizeof(head));
	memset(cap, 0, sizeof(cap));
	memset(sum, 0, sizeof(sum));
	memset(dis, 0, sizeof(dis));
}
int isap(int st, int ed) {
	int n = ed + 1;
	sum[0] = n;
	for (int i = st; i <= ed; ++i)	cur[i] = head[i];
	int u = pre[st] = st;
	int flow = 0, aug = -1;
	bool ok;
	while (dis[st] < n) {
		ok = 0;
		for (int &i = cur[u]; ~i; i = nxt[i]) {
			int v = to[i];
			if (cap[i] && dis[u] == dis[v] + 1) {
				ok = 1;
				pre[v] = u;
				u = v;
				aug = (aug == -1) ? cap[i] : min(cap[i], aug);
				if (v == ed) {
					flow += aug;
					for (u = pre[v]; v != st; v = u, u = pre[u]) {
						cap[cur[u]] -= aug;
						cap[cur[u] ^ 1] += aug;
					}
					aug = -1;
				}
				break;
			}
		}
		if (ok)	continue;
		int Min = n;
		for (int i = head[u]; ~i; i = nxt[i]) {
			int v = to[i];
			if (cap[i] && dis[v] < Min) {
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
inline int geta(int x) {
	if (x == 1)	return 0;
	int t = A[x];
	if (!t)	A[x] = t = ++c1, num1[c1] = x;
	return t;
}
inline int getb(int x) {
	if (x == 1)	return 0;
	int t = B[x];
	if (!t)	B[x] = t = ++c2, num2[c2] = x;
	return t;
}
int main() {
	int n, T;
	scanf("%d", &T);
	while (T--) {
		init();
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)	scanf("%d", &a[i]);
		for (int i = 1; i <= n; ++i)	scanf("%d", &b[i]);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j) {
				if (b[j] > a[i])	++cnt1[geta(__gcd(a[i], b[j]))];
				if (b[j] < a[i])	++cnt2[getb(__gcd(a[i], b[j]))];
			}
		int st = 0, ed = c1 + c2 + 1;
		for (int i = 1; i <= c1; ++i)	add(st, i, cnt1[i]);
		for (int i = 1; i <= c2; ++i)	add(i + c1, ed, cnt2[i]);
		for (int i = 1; i <= c1; ++i)
			for (int j = 1; j <= c2; ++j)
				if (__gcd(num1[i], num2[j]) != 1)	add(i, j + c1, 1000000);
		int ans = isap(st, ed);
		printf("%d\n", ans);
	}
	return 0;
}
