#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define F first
#define S second
inline void read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
const int N = 50005, M = 100005;
int n, m;
int tot, cnt, now, head[N], to[M << 1], nxt[M << 1];
LL d[N], w[M << 1], c[M << 1];
bool vis[N];
void add(int u, int v, LL ww) {
	to[tot] = v, w[tot] = ww, nxt[tot] = head[u], head[u] = tot++;
}
void dfs(int u) {
	vis[u] = 1;
	for (int i = head[u], v; ~i; i = nxt[i]) {
		v = to[i];
		if (!vis[v]) d[v] = d[u] ^ w[i], dfs(v);
		else {
			LL t = d[u] ^ d[v] ^ w[i];
			if (t)	c[++cnt] = t;
		}
	}
}
void gauss() {
	now = 0;
	for (int i = 60; i >= 0; --i) {
		int j = now + 1;
		while (!(c[j] >> i & 1ll) && j <= cnt)	++j;
		if (j == cnt + 1)	continue;
		++now;
		swap(c[now], c[j]);
		for (int k = 1; k <= cnt; ++k)
			if (k != now && (c[k] >> i & 1ll))
				c[k] ^= c[now];
	}
}
int main() {
	memset(head, -1, sizeof(head));
	read(n), read(m);
	for (int i = 1, x, y; i <= m; ++i) {
		long long z;
		read(x), read(y);
		scanf("%lld", &z);
		add(x, y, z);
		add(y, x, z);
	}
	dfs(1);
	gauss();
	LL ans = d[n];
	for (int i = 1; i <= now; ++i)
		ans = max(ans, ans ^ c[i]);
	printf("%lld\n", ans);
	return 0;
}
