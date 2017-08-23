#include <bits/stdc++.h>
using namespace std;
const int N = 55;
char s[N][N];
class DucksAlignment {
	public:
	int minimumTime(vector <string> grid) {
		int n = grid.size(), m = grid[0].size();
		int ans = INT_MAX;
		int cnt = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (grid[i][j] == 'o')	++cnt;
		for (int i = 0; i < n; ++i) {
			int now = 0;
			for (int j = 0; j < n; ++j)
				for (int k = 0; k < m; ++k)	s[j][k] = grid[j][k];
			for (int j = 0; j < n; ++j)
				for (int k = 0; k < m; ++k) {
					if (s[j][k] == 'o') {
						now += abs(j - i);
						swap(s[j][k], s[i][k]);
						break;
					}
				}
			for (int j = 0; j <= m - cnt; ++j) {
				int t = 0, tot = 0, p = j;
				for (int k = 0; k < m; ++k) {
					if (tot == cnt)	break;
					if (s[i][k] == 'o')	t += abs(k - p), ++p, ++tot;
				}
				ans = min(ans, now + t);
			}
		}
		for (int i = 0; i < m; ++i) {
			int now = 0;
			for (int j = 0; j < n; ++j)
				for (int k = 0; k < m; ++k)	s[j][k] = grid[j][k];
			for (int j = 0; j < n; ++j)
				for (int k = 0; k < m; ++k) {
					if (s[j][k] == 'o') {
						now += abs(k - i);
						swap(s[j][k], s[j][i]);
						break;
					}
				}
			for (int j = 0; j <= n - cnt; ++j) {
				int t = 0, tot = 0, p = j;
				for (int k = 0; k < n; ++k) {
					if (tot == cnt)	break;
					if (s[k][i] == 'o')	t += abs(k - p), ++p, ++tot;
				}
				ans = min(ans, now + t);
			}
		}
		return ans;
	}
};
