#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e6 + 5;
#define pb push_back
#define mp make_pair
#define F first
#define S second
inline void read(int &t) {
    int f = 1;char c;
    while (c = getchar(), c < '0' || c > '9') if (c == '-') f = -1;
    t = c - '0';
    while (c = getchar(), c >= '0' && c <= '9') t = t * 10 + c - '0';
    t *= f;
}
typedef pair<int, int>pii;
vector<pii> g[N];
int n, m, p[N], c[N], v[N];
bool f[N];
LL ans;
inline void work() {
	ans = 0;
	for (int i = 1; i <= n / 2; ++i)
		for (int j = 0; j < g[p[i]].size(); ++j) 
			if (f[g[p[i]][j].F])	ans += g[p[i]][j].S;	
}
bool check(int u) {
	queue<int> q;
	q.push(u);
	v[u] = 1;
	while (q.size()) {
		int t = q.front();
		q.pop();
		for (int i = 0; i < g[t].size(); ++i) {
			if (v[g[t][i].F] == -1) {
				v[g[t][i].F] = !v[t];
				q.push(g[t][i].F);
			}
			else if (v[g[t][i].F] == v[t])	return 0;
		}
	}
}
bool judge() {//¶þ·ÖÍ¼
	bool ok = 1;
	memset(v, -1, sizeof(v));
	for (int i = 1; i <= n; ++i) {
		if (v[i] == -1 && !check(i)) {
			ok = 0;
			break;
		}
	}
	if (!ok)	return ok;
	for (int i = 1; i <= n; ++i)
		if (g[i].size() != n / 2)	return 0;
	return 1;
}
int main() {
	read(n), read(m);
	srand(time(0));
	for (int i = 1; i <= n; ++i)	p[i] = i - 1;
	random_shuffle(p + 1, p + n + 1);
	for (int i = 1, x, y, z; i <= m; ++i) {
		read(x), read(y), read(z);
		g[x].pb(mp(y, z)), g[y].pb(mp(x, z));
	}
	if (judge()) {
		for (int i = 1; i <= n; ++i)
			if (v[i] == 1)	printf("%d ", i);
	}
	else {
		for (int j = 1; j <= n / 2; ++j)	f[p[j]] = 0;
		for (int j = n / 2 + 1; j <= n; ++j)	f[p[j]] = 1;
		work();
		memcpy(c, p, sizeof(c));
		for (double T = 5000; T >= 0.1; T *= 0.95) {
			int x = rand() % (n / 2) + 1, y = rand() % (n / 2) + n / 2 + 1;
			LL t = 0;
			for (int j = 0; j < g[p[x]].size(); ++j)
				if (f[g[p[x]][j].F])	t -= g[p[x]][j].S;
			for (int j = 0; j < g[p[y]].size(); ++j)
				if (!f[g[p[y]][j].F] && g[p[y]][j].F != p[x])	t -= g[p[y]][j].S;
			for (int j = 0; j < g[p[x]].size(); ++j)
				if (!f[g[p[x]][j].F])	t += g[p[x]][j].S;
			for (int j = 0; j < g[p[y]].size(); ++j)
				if (f[g[p[y]][j].F] && g[p[y]][j].F != p[x])	t += g[p[y]][j].S;
			if (t <= 0) {
				ans += t;
				swap(p[x], p[y]);
			}
		}
		memcpy(c, p, sizeof(p));
		for (int i = 1; i <= n / 2; ++i)	printf("%d ", c[i]);
	}
	return 0;
}  
