#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
struct RectangularSum {
    long long minimalArea(int height, int width, long long S) {
  		int s;
		for (s = 1; (LL)s * (s - 1) / 2 <= S; ++s);
		int ans = 1e7;
		for (int n = 1; n <= s && n <= height; ++n)
			for (int m = 1; n * m <= s && m <= width; ++m) {
				if (S * 2 % n != 0)	continue;
				LL t = S * 2 / n - (LL)(n - 1) * m * width;
				if (t < 0 || t & 1)	continue;
				if (t % m != 0)	continue;
				t = t / m + 1 - m;
				if (t < 0 || t & 1)	continue;
				t /= 2;
				int y = t % width, x = t / width;
				if (x >= 0 && x + n - 1 < height && y >= 0 && y + m - 1 < width)	ans = min(ans, n * m);
			}
		return ans == 1e7 ? -1 : ans;
	}
};
