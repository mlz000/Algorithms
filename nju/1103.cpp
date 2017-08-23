#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 205;
int a[16][4] = {
	{0, 0, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0}, {0, 0, 1, 1},
	{0, 1, 0, 0}, {0, 1, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 1},
	{1, 0, 0, 0}, {1, 0, 0, 1}, {1, 0, 1, 0}, {1, 0, 1, 1},
	{1, 1, 0, 0}, {1, 1, 0, 1}, {1, 1, 1, 0}, {1, 1, 1, 1}
};
char s[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
char str[] = {'A', 'D', 'J', 'K', 'S', 'W'};
char S[N][55];
int n, m, cnt, g[N][N], ans[10];
bool check(int x, int y) {
	return (x >= 0 && x <= n + 1 && y >= 0 && y <= m + 1);
}
void dfs1(int x, int y) {
	if (!check(x, y) || g[x][y] != 0)	return ;
	g[x][y] = -1;
	dfs1(x + 1, y);
	dfs1(x - 1, y);
	dfs1(x, y + 1);
	dfs1(x, y - 1);
}
void dfs2(int x, int y) {
	if (!check(x, y) || g[x][y] == -1)	return ;
	if (!g[x][y]) {
		++cnt;
		dfs1(x, y);
		return ;
	}
	g[x][y] = -1;
	dfs2(x + 1, y);
	dfs2(x - 1, y);
	dfs2(x, y + 1);
	dfs2(x, y - 1);
}
int main() {
	int tt = 0;
	while (scanf("%d%d", &n, &m) != EOF) {
		if (!n && !m)	break;
		printf("Case %d: ", ++tt);
		memset(ans, 0, sizeof(ans));
		memset(g, 0, sizeof(g));
		for (int i = 1; i <= n; ++i)	scanf("%s", S[i] + 1);
		for (int i = 1; i <= n; ++i) {
			int now = 0;
			for (int j = 1; j <= m; ++j)
				for (int k = 0; k < 16; ++k)
					if (S[i][j] == s[k]) {
						for (int l = 0; l < 4; ++l)	g[i][++now] = a[k][l];
						break;
					}
		}
		m <<= 2;
		dfs1(0, 0);//Íâ²ãÀ©Õ¹Ò»²ã
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j) 
				if (g[i][j] == 1) {
					cnt = 0;
					dfs2(i, j);
					if (cnt == 0)	++ans[5];
					if (cnt == 1)	++ans[0];
					if (cnt == 2) 	++ans[3];
					if (cnt == 3)	++ans[2];
					if (cnt == 4)	++ans[4];
					if (cnt == 5)	++ans[1];
				}
		for (int i = 0; i < 6; ++i)
			for (int j = 1; j <= ans[i]; ++j)	
				printf("%c", str[i]);
		puts("");
	}
	return 0;
}
