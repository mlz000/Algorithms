#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int a[N];
int main() {
	int n, x;
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; ++i)	scanf("%d", &a[i]);
	int ans = x;
	for (int i = 1; i <= n; ++i) {
		if (a[i] < x)	--ans;
		else if (a[i] == x)	++ans;
	}
	printf("%d\n", ans);
	return 0;
}
