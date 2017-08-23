#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
const int N = 55;
class MergersDivOne {
	public:
		double findMaximum(vector <int> revenues) {
			int n = revenues.size();
			sort(revenues.begin(), revenues.end());
			double ans = (revenues[0] + revenues[1]) * 0.5;
			for (int i = 2; i < n;  ++i) {
				ans = (ans + revenues[i]) * 0.5;
			}
			return ans;
		}
};
