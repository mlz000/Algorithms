#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e9;
class CorrectMultiplication {
	public:
	long long getMinimum(int a, int b, int c) {
		LL ans = (LL)1e12;
		if (a > b)	swap(a, b);
		for (LL i = 1; i <= 40000; ++i) {//a
			LL x = c / i;
			if (x)	ans = min(ans, abs(a - i) + abs(b - x) + abs(c - i * x));
			x = c / i + 1;
			if (x)	ans = min(ans, abs(a - i) + abs(b - x) + abs(c - i * x));
		}
		return ans;
	}
};


