#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define F first
#define S second
vector<pair<int, int> > a;
int b[55];
class DengklekMakingChains {
	public:
	int maxBeauty(vector <string> chains) {
		int n = chains.size(); 
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			int t = 0, t1 = 0, t2 = 0;
			bool f = 1;
			for (int j = 0; j < chains[i].size(); ++j) {
				if (chains[i][j] >= '0' && chains[i][j] <= '9')	 t += chains[i][j] - '0';
				if (chains[i][j] == '.') {
					f = 0;
					if (!t1)	t1 = t;
					b[i] = max(b[i], t);
					t = 0;
				}
			}
			if (f)	ans += t;
			else {
				if (chains[i][0] == '.')	t1 = 0;
				b[i] = max(b[i], t);
				t2 = t, a.pb(mp(t1, t2));
			}
		}
		n = a.size();
		int t = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i == j)	continue;
				t = max(t, a[i].S + a[j].F);
			}
			t = max(t, a[i].S);
			t = max(t, a[i].F);
		}
		ans += t;
		n = chains.size();
		for (int i = 0; i < n; ++i)	ans = max(ans, b[i]);
		return ans;
	}
};
