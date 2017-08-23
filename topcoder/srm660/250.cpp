#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, m;
int g[N][N];
struct data {
	int i, j, x;
}b[N * N];
bool cmp(const data &p, const data &q) {
	return p.x > q.x;
}
class Coversta {
	public:
	int place(vector <string> a, vector <int> x, vector <int> y) {
	     n = a.size(), m = a[0].size();
		 int nn = x.size();
		 int now = 0;
		 for (int i = 0; i < n; ++i)
			 for (int j = 0; j < m; ++j) {
				 for (int k = 0; k < nn; ++k) {
				 	int tx = i + x[k], ty = j + y[k];
					if (tx >= 0 && tx < n && ty >= 0 && ty < m) {
						g[i][j] += a[tx][ty] - '0';
					}
				 }
				 b[++now].x = g[i][j];
				 b[now].i = i, b[now].j = j;
			 }
		 sort(b + 1, b + now + 1, cmp);
		 int ans = 0;
		 for (int i = 1; i <= 1000; ++i)
			 for (int j = 1; j <= 1000; ++j) {
			 	if (i == j)	continue;
				int t = g[b[i].i][b[i].j] + g[b[j].i][b[j].j];
				for (int k = 0; k < nn; ++k) {
					int tx = b[i].i + x[k], ty = b[i].j + y[k];
					if (tx >= 0 && tx < n && ty >= 0 && ty < m) {
						for (int kk = 0; kk < nn; ++kk) {
							int px = b[j].i + x[kk], py = b[j].j + y[kk];
							if (px >= 0 && px < n && py >= 0 && py < m) {
								if (px == tx && py == ty) {
									t -= a[tx][ty] - '0';
								}
							}
						}
					}
				}
				ans = max(ans, t);
			 }
		 return ans;
	}
};
