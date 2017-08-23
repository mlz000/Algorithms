#include <bits/stdc++.h>
using namespace std;
inline int read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
int ans[5][5] = {
	{1, 1, 1, 1, 1},
	{0, 1, 1, 1, 1}, 
	{0, 0, 2, 1, 1}, 
	{0, 0, 0, 0, 1}, 
	{0, 0, 0, 0, 0}
};
int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
char s[10][10];
bool check(int a[5][5]) {
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			if (a[i][j] != ans[i][j])	return 0;
	return 1;
}
bool astar(int now, int a[5][5], int k) {
	int t = 0;
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			if (a[i][j] != ans[i][j]) {
				if (++t + now > k)	return 0;
			}
	return 1;
}
bool dfs(int now, int a[5][5], int x, int y, int k) {
	if (now == k)	return check(a);
	for (int i = 0; i < 8; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || nx > 4 || ny < 0 || ny > 4)	continue;
		swap(a[x][y], a[nx][ny]);
		if (astar(now, a, k)) {
			if (dfs(now + 1, a, nx, ny, k))	return 1;
		}
		swap(a[x][y], a[nx][ny]);
	}
	return 0;
}
int main() {
	int T;
	read(T);
	while (T--) {
		int a[5][5];
		memset(a, 0, sizeof(a));
		for (int i = 0; i < 5; ++i)	scanf("%s", s[i]);
		int x, y;
		for (int i = 0; i < 5; ++i)
			for (int j = 0; j < 5; ++j) {
				if (s[i][j] == '*')	a[i][j] = 2, x = i, y = j;
				else a[i][j] = s[i][j] - '0';
			}
		int f = 0;
		for (int i = 1; i <= 15; ++i)
			if (dfs(0, a, x, y, i)) {
				f = i;
				break;
			}
		if (f)	printf("%d\n", f);
		else puts("-1");
	}
	return 0;
}
