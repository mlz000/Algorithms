#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
char S[N][N];
int n, m, s[N][N];
inline int sum(int x1, int y1, int x2, int y2) {
	return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
}
int dfs(int x, int y, int dx, int dy) {
	if (sum(x, y + 1, x + dx - 1, y + dy) == dx * dy)	return dx + dfs(x, y + 1, dx, dy);
	if (sum(x + 1, y, x + dx, y + dy - 1) == dx * dy)	return dy + dfs(x + 1, y, dx, dy);
	return 0;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)	scanf("%s", S[i] + 1);
	int f = 0;
	int tx, ty;
	for (int i = 1; i <= n; ++i)	
		for (int j = 1; j <= m; ++j) {
			if (S[i][j] == 'X') {
				if (!f)	f = 1, tx = i, ty = j;
				s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + 1;
			}
			else	s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
		}
	int dx, dy, px, py, ans = INT_MAX;
	for (px = tx; S[px][ty] == 'X'; ++px);
	dx = px - tx;
	for (int i = ty; S[tx][i] == 'X'; ++i)
		if (dfs(tx, ty, dx, i - ty + 1) + dx * (i - ty + 1) == s[n][m])	ans = min(ans, dx * (i - ty + 1));
	for (py = ty; S[tx][py] == 'X'; ++py);
	dy = py - ty;
	for (int i = tx; S[i][ty] == 'X'; ++i)
		if (dfs(tx, ty, i - tx + 1, dy) + (i - tx + 1) * dy == s[n][m]) ans = min(ans, (i - tx + 1) * dy);
	if (ans > n * m)	puts("-1");
	else printf("%d\n", ans);
	return 0;
}
