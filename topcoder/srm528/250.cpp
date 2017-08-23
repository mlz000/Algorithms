#include <bits/stdc++.h>
using namespace std;
class Cut {
	public:
	int getMaximum(vector <int> eelLengths, int maxCuts) {
		sort(eelLengths.begin(), eelLengths.end());
		int n = eelLengths.size();
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (eelLengths[i] % 10 == 0) {
				int t = min(eelLengths[i] / 10 - 1, maxCuts);
				if ((t + 1) * 10 != eelLengths[i])	--ans;	
				ans += t + 1;
				maxCuts -= t;
			}
		}
		for (int i = 0; i < n; ++i) {
			if (eelLengths[i] % 10 != 0) {
				if (maxCuts > 0) {
					int t = min(eelLengths[i] / 10, maxCuts);
					ans += t;
					maxCuts -= t;
				}
			}
		}
		return ans;
	}
};
