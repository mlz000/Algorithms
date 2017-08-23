#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
char s[N][N];
bitset<N> b[N];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", s[i] + 1);
		for (int j = 1; j <= n; ++j)
			if (s[i][j] == '1')	b[i].set(j);
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j) {
			if (i == j)	continue;
			if (!b[i][j] && (b[i] & b[j]).any())	ans += 2;
		}
	printf("%d\n", ans);
	return 0;
}
