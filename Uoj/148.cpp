#include <bits/stdc++.h>
using namespace std;
const int N = 50005;
int n, m, L, a[N];
bool gao(int x) {
	bool f = 1;
	int last = 0, now = m;
	for (int i = 1; i <= n; ++i) {
		if (a[i] - last < x) {
			if (now)	--now;
			else f = 0;
		}
		else last = a[i];
	}
	return f;
}
int main() {
	scanf("%d%d%d", &L, &n, &m);
	for (int i = 1; i <= n; ++i)	scanf("%d", &a[i]);
	a[++n] = L;
	int l = 1, r = L, ans = L; 
	while (l <= r) {
		int mid = l + r >> 1;
		if (gao(mid))	ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	printf("%d\n", ans);
	return 0;
}
