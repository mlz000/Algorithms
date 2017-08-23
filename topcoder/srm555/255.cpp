#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
const int N = 55;
int dp[N];
struct CuttingBitString {
	bool ok(LL x) {
		while (x && x % 5 == 0)	x /= 5;
		return x == 1;
	}
    int getmin(string S) {
		string s = "0" + S + "1";
		int n = s.size();
		for (int i = 1; i <= n; ++i)	dp[i] = 10000;
    	for (int i = 1; i < n; ++i) {
			if (s[i] == '1') {
				for (int j = 0; j < i - 1; ++j) {
					if (dp[j] == 10000 || s[j + 1] == '0')	continue;
					LL now = 0;
					for (int k = j + 1; k <= i - 1; ++k)	now = now * 2 + (s[k] == '1' ? 1 : 0);
					if (ok(now))	dp[i - 1] = min(dp[i - 1], dp[j] + 1);
				}
			}
		}
		return dp[n - 2] == 10000 ? -1 : dp[n - 2];
	}
};
