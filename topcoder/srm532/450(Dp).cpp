#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 31, MOD = 1e9 + 7;
int n, m, k, f[N][N][9][(1 << 9) + 1];
class DengklekBuildingRoads {
	public:
	int numWays(int N, int M, int K) {
		f[0][0][0][0] = 1;
		for (int i = 1; i <= N; ++i)
			for (int j = 0; j <= M; ++j) {
				for (int mask = 0; mask < 1 << (K + 1); ++mask)	
					if (!(mask >> K & 1))	f[i][j][K][mask] = f[i - 1][j][0][mask << 1];
				for (int k = K - 1; k >= 0; --k) {
					for (int mask = 0; mask < 1 << (K + 1); ++mask) {
						f[i][j][k][mask] = f[i][j][k + 1][mask];
						if (i + k + 1 <= N && j)	(f[i][j][k][mask] += f[i][j - 1][k][mask ^ ((1 << (k + 1)) | 1)]) %= MOD;
					}
				}
			}
		return f[N][M][0][0];
	}
};
