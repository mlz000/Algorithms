#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
class FoxAndGCDLCM {
	public:
		long long get(long long G, long long L) {
			if (L % G != 0)	return -1;
			LL t = L / G;
			LL ans = 1000000000000000ll;
			for (LL i = 1; i * i <= t; ++i) {
				if (t % i == 0 && __gcd(i, t / i) == 1)	ans = min(ans, G * (t / i + i));
			}
			return ans;
		}
};
