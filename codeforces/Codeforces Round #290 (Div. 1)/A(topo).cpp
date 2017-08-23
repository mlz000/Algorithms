#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define F first
#define S second
const int N = 105;
char s[N][N];
int l[N], d[30], q[30];
vector<int> g[30];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)	scanf("%s", s[i]), l[i] = strlen(s[i]);
	bool f = 1;
	for (int i = 1; i < n; ++i) {
		int p = 0;
		while (p < l[i] && p < l[i + 1] && s[i][p] == s[i + 1][p])	++p;
		if (p >= l[i] || p >= l[i + 1]) {
			if (p >= l[i + 1]) {
				f = 0;
				break;
			}
			else continue;
		}
		g[s[i][p] - 'a'].pb(s[i + 1][p] - 'a'), ++d[s[i + 1][p] - 'a'];
	}
	int h = 0;
	for (int i = 0; i < 26; ++i)	
		if (!d[i])	q[h++] = i;;
	for (int i = 0; i < h; ++i) {
		int u = q[i];
		for (int j = 0; j < g[u].size(); ++j) {
			int v = g[u][j];
			if ((--d[v]) == 0)	q[h++] = v;
		}
	}
	if (h != 26)	f = 0;
	if (!f)	puts("Impossible");
	else {
		for (int i = 0; i < 26; ++i)	printf("%c", q[i] + 'a');
	}
	return 0;
}
