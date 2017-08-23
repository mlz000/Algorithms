#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
typedef long long LL;
LL phi(LL x) {
	LL t = x;
	for (LL i = 2ll; i * i <= x; ++i) {
		if (x % i == 0) {
			t -= t / i;
			while (x % i == 0)	x /= i;	
		}
	}
	if (x > 1)	t -= t / x;
	return t;
}
int main() {
	LL n, k;
	cin >> n >> k;
	k = (k + 1) / 2;
	while (k-- && n > 1) {
		n = phi(n);
	}
	cout << n % M << endl;
	return 0;
}
