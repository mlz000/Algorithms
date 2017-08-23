#include <bits/stdc++.h>//…®√Ëœﬂ+Sg
using namespace std;
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
inline void read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
const int N = 1e5 + 5, inf = 1e7;
struct Circle {
	int x, y, r, id;
	Circle(){}
	Circle(int x, int y, int r, int id) : x(x), y(y), r(r), id(id) {}
	bool operator < (const Circle &b) const {
		return x < b.x || x == b.x && y < b.y;
	}
}a[N], b[N];
inline LL sqr(int x) {
	return (LL)x * x;
}
inline LL dis(Circle a, Circle b) {
	return sqr(a.x - b.x) + sqr(a.y - b.y);
}
bool cmp(const Circle &p, const Circle &q) {
	return p.r < q.r;
}
set<Circle> S;
bool root[N];
vector<int> g[N], era;
int dp[N];
void dfs(int u) {
	dp[u] = 0;
	for (int i = 0, v; i < g[u].size(); ++i) {
		v = g[u][i];
		dfs(v);
		dp[u] ^= (dp[v] + 1);
	}
}
int main() {
	int n, T;
	read(T);
	while (T--) {
		S.clear();
		memset(root, 1, sizeof(root));
		read(n);
		for (int i = 1; i <= n; ++i)	g[i].clear();
		for (int i = 1; i <= n; ++i) {
			read(a[i].x), read(a[i].y), read(a[i].r);
			a[i].id = i;
			b[i] = a[i];
		}
		sort(a + 1, a + n + 1, cmp);
		for (int i = 1; i <= n; ++i) {
			set<Circle>:: iterator l = S.lower_bound(Circle(a[i].x - a[i].r, -inf, a[i].r, a[i].id));
			set<Circle>:: iterator r = S.upper_bound(Circle(a[i].x + a[i].r, inf, a[i].r, a[i].id));
			era.clear();
			for (set<Circle>:: iterator it = l; it != r && it != S.end(); ++it) {
				if (sqr(a[i].x - (*it).x) + sqr(a[i].y - (*it).y) <= sqr(a[i].r)) {
					root[(*it).id] = 0;
					g[a[i].id].pb((*it).id);
					era.pb((*it).id);
				}
			}
			for (int j = 0; j < era.size(); ++j)	S.erase(b[era[j]]);
			S.insert(a[i]);
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i)
			if (root[i]) {
				dfs(i);
				ans ^= (dp[i] + 1);
			}
		printf("%s\n", ans ? "Alice" : "Bob");
	}
	return 0;
}
