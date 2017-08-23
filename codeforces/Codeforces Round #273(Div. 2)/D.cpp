#include <bits/stdc++.h>
using namespace std;
const int N = 900, M = (int)1e9 + 7;
int f[200005];
int main() {
	int n, m, h;
	scanf("%d%d", &n, &m);
	int sum = n + m;
	for (int i = 1; i <= 900; ++i) {
		if ((i + 1) * i / 2 <= sum)	h = i;
		else break;
	}
	f[0] = 1;
	if (n > m)	swap(n, m);
	for (int i = 1; i <= h; ++i) {
		for (int j = n; j >= i; --j) {
			f[j] += f[j - i];
			if (f[j] >= M)	f[j] -= M;
		}
	}
	int ans = 0;
	sum = (h + 1) * h / 2;
	for (int i = 0; i <= n; ++i)	
		if (sum - i <= m)	ans = (ans + f[i]) % M;
	printf("%d\n", ans);
	return 0;
}
