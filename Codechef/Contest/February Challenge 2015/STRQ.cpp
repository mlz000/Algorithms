#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1000005;
LL sum[N][4], sum2[N][4][4];
int c[300];
char s[N];
inline int fast() {
	char c;
	while (c = getchar(), c < '0' || c > '9');
	int t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	 t = t * 10 + c - '0';
	return t;
}
int main() {
	int q;
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	c['c'] = 0, c['h'] = 1, c['e'] = 2, c['f'] = 3;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 4; ++j)
			sum[i][j] = sum[i - 1][j];
		++sum[i][c[s[i]]];
	}
	for (int i = n; i >= 1; --i) {
		for (int k = 0; k < 4; ++k) 
			for (int j = 0; j < 4; ++j){
				sum2[i][k][j] = sum2[i + 1][k][j];
				if (c[s[i]] == k)	sum2[i][k][j] += sum[n][j] - sum[i][j];
			}
	}
	q = fast();
	while (q--) {
		char a, b;
		scanf("%c %c", &a, &b);
		int l = fast(), r = fast();
		printf("%lld\n", sum2[l][c[a]][c[b]] - sum2[r + 1][c[a]][c[b]] - (sum[r][c[a]] - sum[l - 1][c[a]]) * (sum[n][c[b]] - sum[r][c[b]]));
	}
	return 0;
}
