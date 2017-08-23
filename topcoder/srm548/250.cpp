#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
const int N = 55;
bool check(int x, vector<int> h) {
	int n = h.size();
	for (int i = 0; i < n; ++i) {
		if (!i) {
			if (h[i] - x >= 1)	h[i] -= x;
			else h[i] = 1;
		}
		else {
			if (h[i] + x > h[i - 1]) {
				int t = h[i - 1] + 1;
				h[i] = max(t, h[i] - x);
			}
			else return 0;
		}
	}
	return 1;
}
struct KingdomAndTrees {
    int minLevel(vector <int> heights) {
		int l = 0, r = 1e9;
		int ans = -1;
		while (l <= r) {
			int mid = l + r >> 1;
			if (check(mid, heights)) {
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		return ans;
    }
};
