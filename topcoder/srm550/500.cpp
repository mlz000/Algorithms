#include <bits/stdc++.h>//conclusion
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
struct CheckerExpansion {
	vector <string> resultAfter(long long t, long long x0, long long y0, int w, int h) {
		vector<string> ans;
		for (int i = 0; i < h; ++i) {
			string s = "";
			for (int j = 0; j < w; ++j) {
				LL x = x0 + j;
				LL y = y0 + h - i - 1;
				if (y > x) {
					s += ".";
					continue;
				}
				if ((x + y) % 2 == 0) {
					LL n = (x + y) / 2;
					LL m = abs(x - n);
					if (n >= t)	s += ".";
					else if ((n & m) == m) {	//amazing 
						if (n & 1)	s += "B";
						else s += "A";
					}
					else s += ".";
				}
				else s += ".";
			}
			ans.pb(s);
		}
		return ans;
	}
};
