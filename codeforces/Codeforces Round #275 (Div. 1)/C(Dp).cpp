#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 51, M = 21;
char s[N][M];
LL a[1 << M]; 
double f[1 << M];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)	scanf("%s", s[i]);
	int l = strlen(s[0]);
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j) {
			LL t = 0;
			for (int k = 0; k < l; ++k)
				t |= (s[i][k] == s[j][k]) << k;
			a[t] |= (1ll << i) | (1ll << j);
		}
	for (int i = (1 << l) - 1; i >= 0; --i)
		for (int j = 0; j < l; ++j)
			if (i >> j & 1)	a[i ^ (1 << j)] |= a[i];
	f[0] = 1;
	double ans = 0;
	for (int i = 0; i < 1 << l; ++i) {
		int x = __builtin_popcount(i);
		for (int j = 0; j < l; ++j)
			if (!(i >> j & 1))	f[i | (1 << j)] += f[i] / (l - x);
		for (int j = 0; j < n; ++j)
			if (a[i] >> j & 1)	ans += f[i];	
	}
	printf("%.10lf\n", ans / n);
	return 0;
}
