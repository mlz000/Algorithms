#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		LL a, b;
		scanf("%lld%lld", &a, &b);
		LL t = b;
		LL c = __gcd(a, b);
		while (c != 1) {
			a = c, b /= c;
			c = __gcd(a, b);
		}
		printf("%s\n", b == 1 ? "Yes" : "No");
	}
	return 0;
}
