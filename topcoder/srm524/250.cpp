#include <bits/stdc++.h>
using namespace std;
class MagicDiamonds {
	public:
	long long minimalTransfer(long long n) {
		if (n <= 3)	return n;
		for (long long i = 2; i * i <= n; ++i) {
			if (n % i == 0)	return 1;
		}
		return 2;
	}
};
