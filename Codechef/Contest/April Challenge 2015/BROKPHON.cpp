#include <bits/stdc++.h>
const int N = 1e5 + 5;
int n, T, a[N];
bool v[N];
int main() {
	scanf("%d", &T);
	while (T--) {
		memset(v, 0, sizeof(v));
		int ans = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)	scanf("%d", &a[i]);
		int last = 1;
		bool f = 1;
		for (int i = 2; i <= n; ++i) {
			if (a[i] != a[i - 1])	v[i] = v[i - 1] = 1;	
		}
		for (int i = 1; i <= n; ++i)	if (v[i])	++ans;
		printf("%d\n", ans);
	}
	return 0;
}
