#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int dfs(LL x, LL l, LL r, LL L, LL R) {
	if (r < L || l > R)	return 0;
	if (x < 2)	return x;
	return dfs(x / 2, l, r, L, (L + R) / 2 - 1) + dfs(x % 2, l, r, (L + R) >> 1, (L + R) >> 1) + dfs(x / 2, l, r, (L + R) / 2 + 1, R);
}
int main() {
	LL n, l, r;
	cin >> n >> l >> r;
	LL x = n, L = 1, R = 1;
	while (x > 1) {
		R = R * 2 + 1;
		x >>= 1;
	}
	cout << dfs(n, l, r, L, R) << endl;
	return 0;
}

