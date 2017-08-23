#include <bits/stdc++.h>
using namespace std;
const int N = 55;
typedef long long LL;
LL f[N][N];
vector<int> w;
LL dp(int l, int r) {
	if (r - l == 1)	return f[l][r] = 0;
	LL &t = f[l][r];
	if (~t)	return t;
	t = 0;
	for (int i = l + 1; i < r; ++i) {
		t = max(t, dp(l, i) + dp(i, r) + w[l] * w[r]);
	}
	return t;
}
class CasketOfStar {
	public:
	int maxEnergy(vector <int> weight) {
		w = weight;
		int n = weight.size();
		memset(f, -1, sizeof(f));
		return dp(0, n - 1);
	}
};
