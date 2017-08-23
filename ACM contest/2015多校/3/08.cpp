#include <bits/stdc++.h>
using namespace std;
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#pragma comment(linker, "/STACK:1024000000,1024000000") 
typedef long long LL;
LL dfs(int l, int r) {
	if (!l)	return r;
	if (l < 0 || l > r)	return -1;
	if (r - l  > l)	return -1;
	LL t = 1e18;
	LL x = 1e18;
	if (r != r * 2 - l) {
		x = dfs(l, r * 2 - l);
		if (~x)	t = min(t, x);
	}
	if (r != r * 2 + 1 - l) {
		x = dfs(l, r * 2 + 1 - l);
		if (~x)	t = min(t, x);
	}
	if (l != 2 * l - 1 - r) {
		x = dfs(2 * l - 1 - r, r);
		if (~x)	t = min(t, x);
	}
	if (l != 2 * l - 2 - r) {
		x = dfs(2 * l - 2 - r, r);
		if (~x)	t = min(t, x);
	}
	if (t == 1e18)	t = -1;
	return t;
}
int main() {
	int l, r;
	while (scanf("%d%d", &l, &r) != EOF) {
		LL ans = dfs(l, r);
		cout << ans << endl;
	}
	return 0;
}
