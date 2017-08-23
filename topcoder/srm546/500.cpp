#include <bits/stdc++.h>//dp
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
int a[16];
LL ans;
struct FavouriteDigits {
	bool dfs(int p, bool f, int x1, int cnt1, int x2, int cnt2, LL now) {
		if (p == -1) {
			if (cnt1 <= 0 && cnt2 <= 0)	{
				ans = now;
				return 1;
			}
			return 0;
		}
		int lim = f ? a[p] : 0;
		for (int i = lim; i <= 9; ++i) {
			if (f) {
				if (!(i == lim || i == x1 || i == x2 || i == lim + 1))	continue;
			}
			else {
				if (!(i == lim || i == x1 || i == x2))	continue;
			}
			int d1 = cnt1 - (i == x1);
			int d2 = cnt2 - (i == x2);
			if (!now && !x1)	d1 = cnt1;
			if (dfs(p - 1, f & (i == lim), x1, d1, x2, d2, now * 10 + i))	return 1;
		}
		return 0;
	}
    long long findNext(long long N, int x1, int cnt1, int x2, int cnt2) {
 		if (x1 > x2)	swap(x1, x2), swap(cnt1, cnt2);
		int p = 0;
		while (N) {
			a[p++] = N % 10;
			N /= 10;
		}
		p = max(p, cnt1 + cnt2);
		dfs(p, 1, x1, cnt1, x2, cnt2, 0);
   		return ans;
	}
};
