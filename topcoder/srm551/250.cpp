#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
struct ColorfulChocolates {
    int maximumSpread(string chocolates, int maxSwaps) {
  		int ans = 0;
		int n = chocolates.size();
		for (int i = 0; i < n; ++i) {
			string s = chocolates;
			int now = 1;
			vector<int> a;
			for (int j = i - 1; j >= 0; --j)
				if (s[j] == s[i])	a.pb(i - j - now), ++now;
			now = 1;
			for (int j = i + 1; j < n; ++j)
				if (s[j] == s[i])	a.pb(j - i - now), ++now;
			sort(a.begin(), a.end());
			int cnt = maxSwaps;
			int t = 1;
			for (int i = 0; i < a.size(); ++i)
				if (cnt - a[i] >= 0) {
					cnt -= a[i];
					++t;
				}
			ans = max(ans, t);
		}
		return ans;
    }
};
