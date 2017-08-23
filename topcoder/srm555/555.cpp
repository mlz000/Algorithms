#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
const int N = 1600, M = 555555555;
int c[N << 1][N << 1];
struct XorBoard {
    int count(int H, int W, int Rcount, int Ccount, int S) {
		for (int i = 0; i <= 1555 * 2; ++i) {
			c[i][0] = 1;
			for (int j = 1; j <= i; ++j)	c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % M;
		}
		int ans = 0;
  		for (int i = 0; i <= Rcount && i <= H; ++i)
			for (int j = 0; j <= Ccount && j <= W; ++j) {
				if (i * W + j * H - 2 * i * j != S)	continue;
				if ((Rcount - i) & 1 || (Ccount - j) & 1)	continue;
				int rl = (Rcount - i) / 2, cl = (Ccount - j) / 2;
				(ans += (LL)c[rl + H - 1][rl] * c[H][i] % M * c[cl + W - 1][cl] % M * c[W][j] % M) %= M;
			}
		return ans;
    }
};
