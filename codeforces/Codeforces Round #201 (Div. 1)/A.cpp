#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int n, a[N];
int main() {
	scanf("%d", &n);
	int t, mx = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		mx = max(a[i], mx);
		t = (i == 1) ? a[i] : __gcd(t, a[i]);
	}
	int cnt = (mx - t) / t + 1 - n;
	printf("%s\n", (cnt) & 1 ? "Alice" : "Bob");
	return 0;
}
