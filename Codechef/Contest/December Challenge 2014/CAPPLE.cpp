#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 5;
int a[N];
int main() {
	int n, T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)	scanf("%d", &a[i]);
		sort(a, a + n);
		int cnt = unique(a, a + n) - a;
		printf("%d\n", cnt);
	}
	return 0;
}
