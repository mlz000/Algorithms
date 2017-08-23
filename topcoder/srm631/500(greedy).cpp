#include <bits/stdc++.h>
using namespace std;
#define sz(x)	x.size()
#define mp make_pair
#define X first
#define Y second
const int N = 1005, inf = 0x3f3f3f3f;
pair<int, int > c[N];
class CatsOnTheLineDiv1 {
    public:
	int getNumber(vector <int> a, vector <int> b, int time) {
		int n = sz(a), ans = 0;
		for (int i = 0; i < n; ++i)	c[i] = mp(a[i] - time, b[i]);
		sort(c, c + n);
		int l = -inf, sink = -inf;
		for (int i = 0; i < n; ++i) {
			int ll = c[i].X, r = ll + time * 2;
			if (ll <= sink)	continue;
			l = max(l, ll);
			if (r - l + 1 < c[i].Y) {
				sink = r;
				++ans;
			}
			else l += c[i].Y;
		}
		return ans;
	}
};

