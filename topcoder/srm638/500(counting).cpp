#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x)	(int)x.size() 
const int N = 55, M = (int)1e9 + 7;
class NarrowPassage2 {
    public:
	int count(vector <int> a, int maxSizeSum) {
		if (a.empty())	return 1;
		int n = sz(a);
		int pos = max_element(a.begin(), a.end()) - a.begin();
		int tot = n;
		long long ans = 1ll;
		vector<int> l, r;
		for (int i = 0; i < n; ++i) {
			if (i == pos)	continue;
			if (i != pos && a[i] + a[pos] <= maxSizeSum) {
				ans = ans * tot % M;
				--tot;
			}
			else {
				if (i < pos)	l.pb(a[i]);
				else r.pb(a[i]);
			}
		}
		ans = ans * count(l, maxSizeSum) % M;
		ans = ans * count(r, maxSizeSum) % M;
		return ans;
	}
};
