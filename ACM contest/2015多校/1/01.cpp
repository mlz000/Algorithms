#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
const int N = 1e5 + 5, M = 1e9 + 7;
bool check[N];
int pos[N], tot, p[N], a[N], l[N], r[N];
vector<int> g[N];
int main() {
	int n;
	for (int i = 1; i <= 10000; ++i)
		for (int j = i; j <= 10000; j += i)	
			g[j].pb(i);
	while (scanf("%d", &n) != EOF) {
		memset(pos, 0, sizeof(pos));
		for (int i = 1; i <= n; ++i)	scanf("%d", &a[i]);
		for (int i = 1; i <= n; ++i)	l[i] = 1, r[i] = n;
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < g[a[i]].size(); ++j) {
				int t = g[a[i]][j];
				l[i] = max(l[i], pos[t] + 1);
			}
			pos[a[i]] = i;
		}
		memset(pos, 0, sizeof(pos));
		for (int i = n; i >= 1; --i) {
			for (int j = 0; j < g[a[i]].size(); ++j) {
				int t = g[a[i]][j];
				if (!pos[t])	continue;
				r[i] = min(r[i], pos[t] - 1);
			}
			pos[a[i]] = i;
		}
		LL ans = 0;
		for (int i = 1; i <= n; ++i) {
			(ans += ((i - l[i] + 1) * (r[i] - i + 1) % M)) %= M;
		}
		cout << ans << endl;
	}
	return 0;
}
