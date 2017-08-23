#include <bits/stdc++.h>
using namespace std ;
typedef long long LL;
#define mp make_pair
#define pb push_back
#define F first
#define S second
class Ear {
	public:
		long long getCount(vector <string> redX, vector <string> blueX, vector <string> blueY) {
			string a, b, c;
			vector<int> r, bx, by;
			for (int i = 0; i < redX.size(); ++i)	a += redX[i];
			for (int i = 0; i < blueX.size(); ++i)	b += blueX[i];
			for (int i = 0; i < blueY.size(); ++i)	c += blueY[i];
			stringstream sa(a), sb(b), sc(c);
			int x;
			while (sa >> x)	r.pb(x);
			while (sb >> x)	bx.pb(x);
			while (sc >> x)	by.pb(x);
			sort(r.begin(), r.end());
			LL ans = 0;
			int n = bx.size(), m = r.size();
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j) {
					if (i == j)	continue;
					if (by[i] > by[j]) {
						int tot = 0;
						for (int k = 0; k < m; ++k) {
							if (r[k] < bx[j]) {
								int R = max(bx[i], bx[j]) + 1;
								double x = 1e50;
								if (bx[i] != bx[j]) {
									double k = (double)(by[i] - by[j]) / (bx[i] - bx[j]);
									x = bx[i] - (double)by[i] / k;
									R = max(R, (int)floor(x + 1e-6) + 1);
								}
								int RR = lower_bound(r.begin(), r.end(), R) - r.begin();
								int LL = upper_bound(r.begin(), r.end(), bx[j]) - r.begin();
								ans += 1ll * tot * (RR + m - LL * 2 - 1) * (m - RR) / 2;
								if (r[k] < bx[i] && r[k] < x - 1e-6)	++tot;
							}		
						}
					}
				}
			return ans;
		}
};
