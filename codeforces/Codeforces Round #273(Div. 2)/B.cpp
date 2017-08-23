#include <bits/stdc++.h>
using namespace std;
int main() {
	long long n, m;
	scanf("%I64d%I64d", &n, &m);
	long long a = n / m;
	long long b = n % m;
	printf("%I64d %I64d\n", (a + 1) * a / 2 * b + (a - 1) * a / 2 * (m - b), (n - m + 1) * (n - m) / 2);
	return 0;
}
