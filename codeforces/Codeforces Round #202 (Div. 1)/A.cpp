#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int n;
long long a[N];
int main() {
	scanf("%d", &n);
	long long mx = 0, sum = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%I64d", &a[i]);
		sum += a[i];
		mx = max(mx, a[i]);
	}
	printf("%I64d\n", max(mx, (sum - 1) / (n - 1) + 1));
	return 0;
}
