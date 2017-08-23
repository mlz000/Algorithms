#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
vector<LL> a;
struct FoxPaintingBalls {
    long long theMax(long long R, long long G, long long B, int N) {
  		if (N == 1)	return R + G + B;
		a.pb(R), a.pb(G), a.pb(B);
		sort(a.begin(), a.end());
		LL tot = (LL)N * (N + 1) / 2;
		LL x = tot / 3;
		if (tot % 3 == 0) return a[0] / x;
		LL ll = 0, ans = 0, rr = a[0] / x;
		while (ll <= rr) {
			LL mid = (ll + rr) >> 1ll;
			LL r = R - mid * x, g = G - mid * x, b = B - mid * x;
			if (r + g + b >= mid) {
				ans = mid;
				ll = mid + 1;
			}
			else rr = mid - 1;
		}
		return ans;
    }
};
