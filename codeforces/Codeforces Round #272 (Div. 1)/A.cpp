#include <bits/stdc++.h>
const int M = (int)1e9 + 7;
int main() {
	long long a, b;
	scanf("%I64d%I64d", &a, &b);
	printf("%I64d\n", (((a + 1) * a / 2 % M * b % M + a) % M) * (((b - 1) * b / 2) % M) % M);
	return 0;
}

