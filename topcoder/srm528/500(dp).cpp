#include <bits/stdc++.h>//Ã¶¾Ù+dp
using namespace std;
long long f[21][21];
class SPartition {
	public:
	long long getCount(string s) {
		int n = s.size(); 
		int tx = 0, to = 0;
		for (int i = 0; i < n; ++i)	{
			if (s[i] == 'x')	++tx;
			else ++to;
		}
		if ((tx & 1) || (to & 1))	return 0;
		long long ans = 0;
		for (int i = 0; i < (1 << (n / 2)); ++i) {
			memset(f, 0, sizeof(f));
			f[0][0] = 1;
			if (__builtin_popcount(i) != tx / 2)	continue;
			for (int j = 0; j < n; ++j) {
				for (int k = 0; k <= min(n / 2, j); ++k) 
					if (s[j] == 'x') {
						if (f[k][j - k]){
							if (k != n / 2 && (i >> k & 1))	f[k + 1][j - k] += f[k][j - k];
							if (j - k != n / 2 && (i >> (j - k) & 1))	f[k][j - k + 1] += f[k][j - k];
						}
					}
					else {
						if (f[k][j - k]) {
							if (k != n / 2 && !(i >> k & 1))	f[k + 1][j - k] += f[k][j - k];
							if (j - k != n / 2 && !(i >> (j - k) & 1))	f[k][j - k + 1] += f[k][j - k];
						}
					}
			}
			ans += f[n / 2][n / 2];
		}
		return ans;
	}
};
