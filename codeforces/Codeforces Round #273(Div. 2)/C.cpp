#include <bits/stdc++.h>
using namespace std;
long long a[5];
int main() {
	for (int i = 0; i < 3; ++i)	scanf("%d", &a[i]);
	sort(a, a + 3);
	long long ans = min((a[0] + a[1] + a[2]) / 3, a[0] + a[1]);
	printf("%I64d\n", ans);
	return 0;
}

