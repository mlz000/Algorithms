#include <bits/stdc++.h>
using namespace std;
const int N = 35;
int sum[N][N];
int gao(int x1, int y1, int x2, int y2) {
	return sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
}
class DropCoins {
	public:
	int getMinimum(vector <string> board, int K) {
		int n = board.size(), m = board[0].size();
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (board[i][j] == 'o')	sum[i + 1][j + 1] = 1;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		int ans = INT_MAX;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				for (int ii = i; ii <= n; ++ii)
					for (int jj = j; jj <= m; ++jj) {
						if (gao(i, j, ii, jj) == K) {
							ans = min(ans, min(2 * (i - 1) + n - ii, 2 * (n - ii) + i - 1) + 
									min(2 * (j - 1) + m - jj, 2 * (m - jj) + j - 1));
						}
					}
		return ans == INT_MAX ? -1 : ans;
	}
};
