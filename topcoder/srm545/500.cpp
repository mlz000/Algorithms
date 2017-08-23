#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
const int N = 2005, M = 1e9 + 7;
int c[N][N];
struct Spacetsk {
    int countsets(int L, int H, int K) {
		if (K == 1)	return (H + 1) * (L + 1) % M;
		c[0][0] = 1;
		for (int i = 1; i <= 2001; ++i) {
			c[i][0] = 1;
			for (int j = 1; j <= i; ++j)	c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % M;
		}
		int ans = 0;
		for (int i = 0; i <= L; ++i)	(ans += c[H + 1][K]) %= M;
		for (int dx = 1; dx <= L; ++dx)
			 for (int dy = 1; dy <= H; ++dy) {
				if (__gcd(dx, dy) == 1) {
					int sum = 0, cnt = 0;
					for (int x = 0, y = 0; x <= L; x += dx, y += dy) {
						if (y <= H)	++cnt;	
						int num = min(dx, L - x + 1);
						(sum += 1ll * num * c[cnt][K] % M) %= M;
					}
					(ans += sum * 2 % M) %= M;
				}
			 }
		return ans;
    }
};
