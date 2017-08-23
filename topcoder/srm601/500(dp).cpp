#include <bits/stdc++.h>//dp
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
const int N = 2005, M = 1e9 + 7;
int dp[N][2048][2];
int n, m;
int f(int x, int a, int b, int pos) {
	int &t = dp[x][a][b];
	if (~t)	return t;
	if (x == 0)	{
		if ((a >> pos & 1) && !b && (a & (((1 << 12) - 1) ^ ((1 << pos + 1) - 1))) == 0)	return t = 1;
		else return t = 0;
	}
	t = f(x - 1, a, b, pos);
	if (x <= n)	(t += f(x - 1, a ^ x, b ^ (x >> pos & 1), pos)) %= M;
	if (x <= m)	(t += f(x - 1, a ^ x, b, pos)) %= M;
	return t;
}
class WinterAndSnowmen {
	public:
		int getNumber(int nn, int mm) {
			int ans = 0;
			n = nn, m = mm;
			for (int i = 0; i < 11; ++i) {
				memset(dp, -1, sizeof(dp));
				(ans += f(max(n, m), 0, 0, i)) %= M;
			}
			return ans;
		}
};
