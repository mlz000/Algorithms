#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int n, p[N], a[N];
int main() {
	scanf("%d", &n); 
	p[0] = 1;
	for (int k = 1; k <= 6; ++k)	p[k] = p[k - 1] * 10;
	int ans = 0;
	for (int i = 0; i <= 6; ++i) {
		int t = (n / p[i]) % 10;
		for (int j = 1; j <= t; ++j)	a[j] += p[i];
		ans = max(ans, t);
	}
	printf("%d\n%d", ans, a[1]);
	for (int i = 2; i <= ans; ++i) printf(" %d", a[i]);
	puts("");
	return 0;
}
