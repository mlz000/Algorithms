#include <bits/stdc++.h>
using namespace std;
class MagicBlizzard {
	public:
	double expectation(vector <int> range, vector <int> amount) {
		double ans = 0.0;
		int n = range.size(), k = 0; 
		for (int i = 0; i < n; ++i) {
			for (int j = n - 1; j > 0; --j)
				if (range[j - 1] > range[j])	swap(range[j - 1], range[j]), swap(amount[j - 1], amount[j]);
			for (int j = 0; j < amount[i]; ++j)
				ans += 2.0 * (k++) / (2.0 * range[i] + 1) / (2.0 * range[i] + 1) + 1;
		}
		return ans;
	}
};
