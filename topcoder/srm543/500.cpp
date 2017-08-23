#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
const double inf = 1e20;
double dp[2][100005];
struct EllysRivers {
    double getMin(int length, int walk, vector <int> width, vector <int> speed) {
		int n = width.size();
		for (int i = 0; i <= length; ++i)	dp[0][i] = (double)i / walk;
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j <= length; ++j)	dp[i & 1][j] = inf;
			int last = 0;
			for (int j = 0; j <= length; ++j)
				for (int k = last; k <= j; ++k) {
					double t =  dp[(i - 1) & 1][k] + hypot(width[i - 1], j - k) / speed[i - 1];
					if (t > dp[i & 1][j])	break;
					dp[i & 1][j] = t;
					last = k;
				}
		}
		return dp[n & 1][length];
    }
};
