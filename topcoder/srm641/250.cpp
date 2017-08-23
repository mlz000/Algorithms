#include <bits/stdc++.h>
using namespace std;
#define sz(x)	x.size() 
class TrianglesContainOrigin {
    public:
	long long count(vector <int> x, vector <int> y) {
		int n = sz(x);
		long long ans = 0ll;
		for (int i = 0; i < n; ++i) {
			int l = 0, r = 0;
			if (y[i] == 0)	continue;
			for (int j = 0; j < n; ++j) {
				if (j == i)	continue;
				if (y[i] >= 0 && y[j] >= 0)	continue;
				if (y[i] < 0 && y[j] < 0)	continue;
				if (y[i] * x[j] - y[j] * x[i] > 0)	++l;
				else ++r;
			}
			ans += (long long)l * r;
		}
		return ans;
	}
};
