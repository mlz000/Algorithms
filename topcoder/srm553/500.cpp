#include <bits/stdc++.h>//dp
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
const int N = 55, M = 1e9 + 7;
int n, m;
int dp[N][N][3][2][2];
bool bw[N][N], wb[N][N];
int f(int x, int y, int dir, int ok1, int ok2) {
	if (x == n) {
		if (y == m && dir == 2)	return 0;
		return ok1 + ok2;
	}
	int &t = dp[x][y][dir][ok1][ok2];
	if (~t)	return t;
	t = 0;
	for (int num = 0; num <= m; ++num) {
		if (dir == 0 && num < y || dir == 1 && num > y)	continue;
		int ndir = dir;
		if (dir == 2 && num < y)	ndir = 1;
		if (dir == 2 && num > y)	ndir = 0;
		if (x == 0)	ndir = 2;
		if (y == m && num == 0)	continue;
		int t1 = ok1, t2 = ok2;
		if (!bw[x][num])	t1 = 0;
		if (!wb[x][num])	t2 = 0;
		(t += f(x + 1, num, ndir, t1, t2)) %= M;
	}
	return t;
}
struct TwoConvexShapes {
    int countWays(vector <string> grid) {
 		n = grid.size(), m = grid[0].size();
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j <= m; ++j) {
				bw[i][j] = 1;
				for (int k = 0; k < j; ++k)
					if (grid[i][k] == 'W')	bw[i][j] = 0;
				for (int k = j; k < m; ++k)
					if (grid[i][k] == 'B')	bw[i][j] = 0;
				wb[i][j] = 1;
				for (int k = 0; k < j; ++k)
					if (grid[i][k] == 'B')	wb[i][j] = 0;
				for (int k = j; k < m; ++k)
					if (grid[i][k] == 'W')	wb[i][j] = 0;
			}
		int ans = 0;
		(ans += f(0, 0, 2, 1, 1)) %= M;
		return ans;
			
	}
};
