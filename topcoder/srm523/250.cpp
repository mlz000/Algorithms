#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
class CountingSeries {
	public:
	long long countThem(long long a, long long b, long long c, long long d, long long u) {
		LL ans = 0;
		if (d == 1) {
			LL y = a + (u - a) / b * b;
			LL x = a;
			if (x <= u)	ans += (y - x) / b + 1;
			if (c * d <= u)	++ans;
			if ((c * d >= a && (c * d - a) % b == 0) && a + (c * d - a) / b * b >= 1 && a + (c * d - a) / b * b <= u)	--ans;
		}
		else {
			LL y = a + (u - a) / b * b;
			LL x = a;
			if (x <= u)	ans += (y - x) / b + 1;
			LL t = c;
			for (int i = 0; ; ++i) {
				if (t > u)	break;
				if (!(t >= a && (t - a) % b == 0 && (t - a) / b <= u))	++ans;
				t *= d;
			}
		}
		return ans;
	}
};
