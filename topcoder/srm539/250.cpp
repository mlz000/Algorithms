#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
const int M = 9000;
vector<pii> a;
class Over9000Rocks {
	public:
		int countPossibilities(vector <int> lowerBound, vector <int> upperBound) {
        	int n = lowerBound.size();
			for (int i = 0; i < 1 << n; ++i) {
				int l = 0, r = 0;
				for (int j = 0; j < n; ++j) {
					if (i >> j & 1) {
						l += lowerBound[j];
						r += upperBound[j];
					}
				}
				l = max(l, M + 1);
				if (l <= r)	a.pb(mp(l, r));
			}
			sort(a.begin(), a.end());
			int R = 0, ans = 0;
			for (int i = 0; i < a.size(); ++i) {
				if (a[i].F > R)	ans += a[i].S - a[i].F + 1;
				else if (a[i].S > R)	ans += a[i].S - R;
				R = max(R, a[i].S);
			}
			return ans;
		}
};
