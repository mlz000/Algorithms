#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define F first
#define S second
const int N = 200;
typedef pair<int, int> pii;
vector<pii> g[3];
char s[N][N], ss[N][N];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", s[i]);
		for (int j = 0; j < n; ++j) {
			if (s[i][j] == '.')	g[0].pb(mp(i, j));
			else if (s[i][j] == 'o')	g[1].pb(mp(i, j));
			else g[2].pb(mp(i, j));
		}
	}
	for (int i = 1; i < n << 1; ++i)
		for (int j = 1; j < n << 1; ++j)
			ss[i][j] = 'x';//can
	ss[n][n] = 'o';//chess
	for (int i = 0; i < g[0].size(); ++i)
		for (int j = 0; j < g[1].size(); ++j)
			ss[n + g[0][i].F - g[1][j].F][n + g[0][i].S - g[1][j].S] = '.';//can't
	bool f;
	for (int i = 0; i < g[2].size(); ++i) {
		f = 0;
		for (int j = 0; j < g[1].size(); ++j)
			if (ss[n + g[2][i].F - g[1][j].F][n + g[2][i].S - g[1][j].S] == 'x')	f = 1;
		if (!f)	break;
	}
	if (!f)	puts("NO");
	else {
		puts("YES");
		for (int i = 1; i < n << 1; ++i)	printf("%s\n", ss[i] + 1);
	}
	return 0;
}


