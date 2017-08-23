#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
char s[5], m[300];
vector<pair<int, int> > p;
int c[10][10], a[15], b[15], l[15];
int main() {
	int n;
	m['R'] = 5, m['G'] = 6, m['B'] = 7, m['Y'] = 8, m['W'] = 9;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", s);
		c[m[s[0]]][s[1] - '1'] = 1;
	}
	int ans = 20;
	for (int i = 0; i < 1 << 10; ++i) {
		bool f = 1, ok = 0;
		memset(l, 0, sizeof(l));
		int t = __builtin_popcount(i), left = 0;
		if (t >= ans)	continue;
		for (int j = 5; j < 10; ++j)
			for (int k = 0; k < 5; ++k) {
				if (c[j][k]) {
					if (i & (1 << j) && i & (1 << k))	continue;
					if (i & (1 << j)) {
						++l[j];
						if (l[j] > 1)	f = 0;
					}
					else if (i & (1 << k)) {
						++l[k];
						if (l[k] > 1)	f = 0;
					}
					else {
						++left;
						if (left > 1)	f = 0;
					}
					ok = 1;
				}
			}
		if (f && ok)	ans = min(ans, t);
	}
	printf("%d\n", ans);
	return 0;
}
