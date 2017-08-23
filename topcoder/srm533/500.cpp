#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int r[N], c[N];
bool ok[N][N], vis[N][N];
int n, m, tot;
void dfs(int x, int y) {
	vis[x][y] = 1;
	--tot;
	for (int j = 0; j < m; ++j)
		if (ok[x][j] && !vis[x][j])	dfs(x, j);
	for (int i = 0; i < n; ++i)
		if (ok[i][y] && !vis[i][y])	dfs(i, y);
}
class MagicBoard {
	public:
	string ableToUnlock(vector <string> board) {
		n = board.size(), m = board[0].size();
		int x, y;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) 
				if (board[i][j] == '#')	{
					ok[i][j] = 1;
					++r[i], ++c[j];
					x = i, y = j;
					++tot;
				}
		int rr = 0, cc = 0;
		for (int i = 0; i < n; ++i)	if (r[i] & 1)	++rr;
		for (int j = 0; j < m; ++j)	if (c[j] & 1)	++cc;
		if (rr + cc > 2)	return "NO";
		if (rr + cc == 2 && !cc)	return "NO";
		dfs(x, y);
		return tot ? "NO" : "YES";
	}
};
