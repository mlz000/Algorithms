#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#pragma comment(linker, "/STACK:1024000000,1024000000") 
typedef long long LL;
inline void read(int &t) {
    int f = 1;char c;
    while (c = getchar(), c < '0' || c > '9') if (c == '-') f = -1;
    t = c - '0';
    while (c = getchar(), c >= '0' && c <= '9') t = t * 10 + c - '0';
    t *= f;
}
const int N = 55;
char s[N][N];
int g[N][N];
int main() {
	int T;
	read(T);
	int n, m;
	while (T--) {
		memset(s, 0, sizeof(s));
		memset(g, 0, sizeof(g));
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)	scanf("%s", s[i]);
		m = strlen(s[1]);
		for (int i = 1; i <= n; ++i)
			for (int j = 0; j < m; ++j) {
				if (s[i][j] == 'R')	g[i][j + 1] = 1;
				else if (s[i][j] == 'B')	g[i][j + 1] = 2;
				else if (s[i][j] == 'G')	g[i][j + 1] = 3;
			}
		int ans = 0;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j) {
				if (g[i][j] >= 2) {
					++ans;
					int x = i, y = j;
					while (x >= 1 && x <= n && y >= 1 & y <= m) {
						if (g[x][y] < 2)	break;
						g[x][y] -= 2;
						++x, --y;
					}
				}
				if (g[i][j] >= 1) {
					++ans;
					int x = i, y = j;
					while (x >= 1 && x <= n && y >= 1 & y <= m) {
						if (g[x][y] < 1 || g[x][y] == 2)	break;
						--g[x][y];
						++x, ++y;
					}
				}
			}
		cout << ans << endl;
	}
	return 0;
}
