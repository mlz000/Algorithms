#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
struct ElectionFraudDiv1 {
    int MinimumVoters(vector <int> percentages) {
  		int n = percentages.size();
		for (int i = 1; i <= 1000; ++i) {
			bool f = 1;
			int l = 0, r = 0;
			for (int j = 0; j < n; ++j) {
				int x = percentages[j];
				bool ok = 0;
			 	for (int k = 0; k <= i; ++k) {
					if ((int)((100.0000 / i * k) + 0.500005) == x) {
						ok = 1;
						l += k;
						break;
					}
				}
			 	for (int k = i; k >= 0; --k) {
					if ((int)((100.0000 / i * k) + 0.500005) == x) {
						ok = 1;
						r += k;
						break;
					}
				}
				if (!ok)	f = 0;
			}
			if (f && l <= i && i <= r)	return i;
		}
		return -1;
    }
};
