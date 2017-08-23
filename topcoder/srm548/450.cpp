#include <bits/stdc++.h>//dp
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
const int N = 55;
bool dp[N][N * N];
struct KingdomAndDice {
    double newFairness(vector <int> firstDie, vector <int> secondDie, int X) {
  		int n = firstDie.size();
		int now = 0, nd = 0;
		sort(secondDie.begin(), secondDie.end());
		for (int i = 0; i < n; ++i) {
			nd += firstDie[i] == 0;
			for (int j = 0; j < n; ++j)
				if (firstDie[i] > secondDie[j])	++now;
		}
		secondDie.pb(X + 1);
		for (int i = 0; i <= nd; ++i)	dp[i][now] = 1;
		for (int i = 0; i < n; ++i) {
			int l = secondDie[i] + 1;
			int r = secondDie[i + 1] - 1;
			int cnt = r - l + 1;
			for (int j = 0; j < n; ++j)
				if (firstDie[j] >= l && firstDie[j] <= r)	--cnt;
			cnt = min(cnt, nd);
			for (int j = 0; j < cnt; ++j)
				for (int k = nd - 1; k >= 0; --k)
					for (int p = 0; p <= n * n; ++p)
						if (dp[k][p] && p + i + 1 <= n * n)	dp[k + 1][p + i + 1] = 1;
		}
		double ans = now;
		double mn = 1000000;
		for (int k = 0; k <= n * n; ++k)
			for (int j = 0; j <= nd; ++j)	
				if (dp[j][k] && abs(n * n - k * 2) < mn)	ans = k, mn = abs(n * n - k * 2);
		return ans / n / n;
    }
};
