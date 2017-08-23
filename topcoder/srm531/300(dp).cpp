#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 105, M = 1e9 + 7;
int f[N][N];
void add(int &x, int y) {
	x += y;
	if (x >= M)	x -= M;
}
class NoRepeatPlaylist {
	public:
	int numPlaylists(int n, int m, int p) {
		f[0][0] = 1;
		for (int i = 1; i <= p; ++i)
			for (int j = 1; j <= min(i, n); ++j) {
				f[i][j] = (LL)f[i - 1][j - 1] * (n - j + 1) % M;
				if (j > m)	add(f[i][j], (LL)f[i - 1][j] * (j - m) % M);
			}
		return f[p][n];
	}
};
