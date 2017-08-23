#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];
int main() {
	int n, cnt = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)	scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 2; i < n; ++i) {
		if (a[i] > a[1] && a[i] < a[n])	++cnt;
	}
	printf("%d\n", cnt);
	return 0;
}

