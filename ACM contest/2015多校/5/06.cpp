#include <cstdio>//Å·À­»ØÂ·
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef long long LL;
#define pb push_back
#pragma comment(linker, "/STACK:1024000000,1024000000") 
inline void read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
const int N = 1e5 + 5, M = 4e5 + 5;
vector<int> odd, a[N];
int id[M << 1], ans[M], head[N], to[M << 1], nxt[M << 1];
int tot, d[N];
bool vis[M << 1];
void add(int u, int v, int p) {
	to[tot] = v, nxt[tot] = head[u], id[tot] = p, head[u] = tot++;
}
void dfs(int x) {
	for (int i = head[x]; ~i; i = nxt[i]) {
		head[x] = i;
		if (!vis[i]) {
			vis[i] = vis[i ^ 1] = 1;
			if (id[i] > 0)	ans[id[i]] = 1;
			else ans[-id[i]] = 0;
			dfs(to[i]);
		}
		i = head[x];
	}
}
int main() {
	int T, n, m;
	read(T);
	while (T--) {
		read(n), read(m);
		odd.clear();
		memset(head, -1, sizeof(head));
		memset(vis, 0, sizeof(vis));
		tot = 0;
		for (int i = 1; i <= n; ++i)	d[i] = 0;
		for (int i = 1, x, y; i <= m; ++i) {
			read(x), read(y);
			++d[x], ++d[y];
			add(x, y, i);
			add(y, x, -i);
		}
		for (int i = 1; i <= n; ++i) {
			if (d[i] & 1)	odd.pb(i);
		}
		int t = m;
		if (odd.size()) {
			++t;
			for (int i = 0; i < odd.size(); i += 2, ++t) {
				add(odd[i], odd[i + 1], t);
				add(odd[i + 1], odd[i], -t);
			}
		}
		for (int i = 1; i <= n; ++i)	dfs(i);
		for (int i = 1; i <= m; ++i)	printf("%d\n", ans[i]); 
	}
	return 0;
}
