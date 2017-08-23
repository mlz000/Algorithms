#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
const int N = 51;
double dp[41][N][N][N], _[N], sum[N][N][N];
struct RandomColoring {
	double getProbability(int n, int maxR, int maxG, int maxB, int startR, int startG, int startB, int d1, int d2) {
		for (int r = 0; r < maxR; ++r)
			for (int g = 0; g < maxG; ++g)
				for (int b = 0; b < maxB; ++b) {
					int t1 = abs(r - startR), t2 = abs(g - startG), t3 = abs(b - startB);
					if (!(t1 <= d2 && t2 <= d2 && t3 <= d2 && (t1 >= d1 || t2 >= d1 || t3 >= d1)))	dp[n - 1][r][g][b] = 1.0;
				}
		for (int i = n - 2; i >= 0; --i) {
			for (int r = 1; r <= maxR; ++r)
				for (int g = 1; g <= maxG; ++g)
					for (int b = 1; b <= maxB; ++b)
						sum[r][g][b] = dp[i + 1][r - 1][g - 1][b - 1] + sum[r - 1][g][b] + sum[r][g - 1][b] + sum[r][g][b - 1] - sum[r - 1][g - 1][b] - sum[r][g - 1][b - 1] - sum[r - 1][g][b - 1] + sum[r - 1][g - 1][b - 1];
			for (int r = 0; r < maxR; ++r)
				for (int g = 0; g < maxG; ++g)
					for (int b = 0; b < maxB; ++b) {
						double &t = dp[i][r][g][b];
						int r1 = max(r - d2, 0), r2 = min(r + d2 + 1, maxR);
						int g1 = max(g - d2, 0), g2 = min(g + d2 + 1, maxG);
						int b1 = max(b - d2, 0), b2 = min(b + d2 + 1, maxB);
						int tot = (r2 - r1) * (g2 - g1) * (b2 - b1);
						t = sum[r2][g2][b2] - sum[r1][g2][b2] - sum[r2][g1][b2] - sum[r2][g2][b1] + sum[r1][g1][b2] + sum[r2][g1][b1] + sum[r1][g2][b1] - sum[r1][g1][b1];
						if (d1) {
							r1 = max(r - d1 + 1, 0), r2 = min(r + d1, maxR);
							g1 = max(g - d1 + 1, 0), g2 = min(g + d1, maxG);
							b1 = max(b - d1 + 1, 0), b2 = min(b + d1, maxB);
							tot -= (r2 - r1) * (g2 - g1) * (b2 - b1);
							t -= sum[r2][g2][b2] - sum[r1][g2][b2] - sum[r2][g1][b2] - sum[r2][g2][b1] + sum[r1][g1][b2] + sum[r2][g1][b1] + sum[r1][g2][b1] - sum[r1][g1][b1];
						}
						if (tot)	t /= tot;
					}
		}
		return dp[0][startR][startG][startB];
	}
};
