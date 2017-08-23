#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
const int N = 55;
int g[N][N], l[N], vis[N];
bool can(int u, int m) {
	for (int i = 0; i < m; ++i) {
		if (g[u][i] && !vis[i]) {
			vis[i] = 1;
			if (l[i] == -1 || can(l[i], m)) {
				l[i] = u;
				return 1;
			}
		}
	}
	return 0;
}
struct PointyWizardHats {
    int getNumHats(vector <int> th, vector <int> tr, vector <int> bh, vector <int> br) {
        int n = th.size(), m = bh.size();
		memset(l, -1, sizeof(l));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				if (th[i] * br[j] > tr[i] * bh[j] && tr[i] < br[j])	g[i][j] = 1;
			}
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			memset(vis, 0, sizeof(vis));
			if (can(i, m))	++ans;
		}
		return ans;
    }
};
