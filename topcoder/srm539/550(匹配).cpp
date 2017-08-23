#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
const int N = 55;
int d[N][N], f[N][N], l[N];
bool vis[N];
bool find(int u, int n) {
	for (int i = 1; i <= n; ++i) {
		if (f[u][i] && !vis[i]) {
			vis[i] = 1;
			if (!l[i] || find(l[i], n)) {
				l[i] = u;
				return 1;
			}
		}
	}
	return 0;
}
class SafeReturn {
	public:
        int minRisk(int T, vector <string> streets) {
        	int n = streets.size();
			memset(d, 63, sizeof(d));
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					if (streets[i][j] != '-')	d[i][j] = streets[i][j] - '0';
			for (int i = 0; i < n; ++i)	d[i][i] = 0;
			for (int k = 0; k < n; ++k)
				for (int i = 0; i < n; ++i)
					for (int j = 0; j < n; ++j)
						d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			for (int i = 1; i <= T; ++i)
				for (int j = 1; j <= T; ++j)
					if (i != j && d[0][j] + d[j][i] == d[0][i])	f[i][j] = 1;
			int ans = T;
			for (int i = 1; i <= T; ++i) {
				memset(vis, 0, sizeof(vis));
				if (find(i, T))	--ans;
			}
			return ans;
		}
};
