#include <bits/stdc++.h>//enum
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
const int N = 35;
int L[N][N * N + 1000], R[N][N * N + 1000], D[N][N * N + 1000], U[N][N * N + 1000];
inline void gao(int &x, int y) {
	if (x < y)	x = y;
}
struct FoxAndFlowerShopDivOne {
    int theMaxFlowers(vector <string> s, int maxDiff) {
		memset(L, 0xc0, sizeof(L));
		memset(R, 0xc0, sizeof(R));
		memset(U, 0xc0, sizeof(U));
		memset(D, 0xc0, sizeof(D));
  		int n = s.size(), m = s[0].size();
    	for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) 
				for (int k = i; k < n; ++k)
					for (int l = j; l < m; ++l) {
						int suml = 0, sump = 0;
						for (int p = i; p <= k; ++p)
							for (int q = j; q <= l; ++q) {
								suml += s[p][q] == 'L';
								sump += s[p][q] == 'P';
							}
						int sum = suml + sump, dif = suml - sump + 1000;
						gao(D[i][dif], sum);
						gao(R[j][dif], sum);
						gao(U[k][dif], sum);
						gao(L[l][dif], sum);
					}
		for (int i = 1; i < n; ++i)	
			for (int j = 0; j < N * N + 1000; ++j)
				U[i][j] = max(U[i][j], U[i - 1][j]);
		for (int i = n - 2; i >= 0; --i)
			for (int j = 0; j < N * N + 1000; ++j)
				D[i][j] = max(D[i][j], D[i + 1][j]);
		for (int j = 1; j < m; ++j)
			for (int k = 0; k < N * N + 1000; ++k)
				L[j][k] = max(L[j][k], L[j - 1][k]);
		for (int j = m - 2; j >= 0; --j)
			for (int k = 0; k < N * N + 1000; ++k)
				R[j][k] = max(R[j][k], R[j + 1][k]);
		int ans = -1;
		for (int i = -n * m; i <= n * m; ++i)
			for (int j = -n * m; j <= n * m; ++j) {
				for (int h = 0; h < n - 1; ++h)	
					if (abs(i + j) <= maxDiff)	ans = max(ans, U[h][i + 1000] + D[h + 1][j + 1000]);
				for (int l = 0; l < m - 1; ++l)
					if (abs(i + j) <= maxDiff)	ans = max(ans, L[l][i + 1000] + R[l + 1][j + 1000]);
			}
		return ans;
	}
};
