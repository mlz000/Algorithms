#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int(x.size()))
#define pb push_back
vector<int> wp, wc, bp, bc;
bool v[2005];
class StoryFromTCO {
    public:
	int minimumChanges(vector<int> places, vector<int> cutoff) {
		int n = sz(places);
		for (int i = 0; i < n; ++i) {
			if (places[i] <= cutoff[i]) {
				wp.pb(places[i]);
				wc.pb(cutoff[i]);
			}
			else {
				bp.pb(places[i]);
				bc.pb(cutoff[i]);
			}
		}
		sort(bp.begin(), bp.end());
		sort(bc.begin(), bc.end());
		int i = 0;
		while (i < sz(bp)) {
			if (bp[i] > bc[i]) {
				int p = -1;
				for (int j = 0; j < sz(wp); ++j) {
					if (!v[j] && wp[j] <= bc[i]) {
						if (p == -1)	p = j;
						else if (wc[p] < wc[j])	p = j;
					}
				}
				if (p == -1)	return -1;
				v[p] = 1;
				bp.pb(wp[p]);
				bc.pb(wc[p]);
				sort(bp.begin() + i, bp.end());
				sort(bc.begin() + i, bc.end());
			}
			else ++i;
		}
		return sz(bp);
	}
};
