#include <bits/stdc++.h>//¶þ·Ö´ð°¸
using namespace std ;
const int N = 5e5 + 5, inf = 1e7;
int n, m, k, a[N], r[N], d[N], nxt[N], s[N];
bool check(int x) {
	d[n] = 0;
	for (int i = n - 1; i >= 1; --i) {
		if (r[i] > n)	d[i] = d[i + 1] + 1;
		else if (r[i] - i < x)	d[i] = d[i + 1];
		else	d[i] = d[i + 1] + (d[i + x] > d[r[i] + 1]);
	}
	return d[1] > d[r[0] + 1];
}
void work() {
	a[0] = m;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		a[i] = -a[i] + a[i - 1];
	}
	for (int i = 0, j = 1, t = 0; i < n; ++i, t += k) {
		while (j <= n && t + a[j] > 0)	++j;
		r[i] = j > n ? inf : j - 1;
		if (r[i] <= i) {
			puts("Poor Hero!");
			return;
		}
	}
	if (r[0] > n || r[r[0]] > n)	puts("Poor JRY!");
	else {
		int L = 1, R = n, ans;
		while (L <= R) {
			int mid = L + R >> 1;
			if (check(mid))	{
				ans = mid;
				L = mid + 1;
			}
			else R = mid - 1;
		}
		check(ans);
		nxt[n] = 0;
		for (int i = n - 1; i >= 0; --i) 
			nxt[i] = d[i] > d[i + 1] ? i : nxt[i + 1];
		int top = 0;
		int x = nxt[1];
		while (x) {
			s[top++] = x;
			if (r[x] > n)	break;
			x = nxt[x + ans];
		}
		printf("%d\n", ans);
		printf("%d\n", top);
		for (int i = 0; i < top; ++ i)
            printf("%d%c", s[i], i < top - 1 ? ' ' : '\n' );
	}
}
int main() {
	while (~scanf("%d%d%d", &n, &m, &k)) {
		work();
	}
	return 0;
}
