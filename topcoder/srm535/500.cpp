#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
const int N = 55;
double w[N];
class FoxAndBusiness {
	public:
		double minimumCost(int K, int totalWork, vector <int> a, vector <int> p) {
			int n = a.size();
			double l = 0, r = 1e18, mid;
			for (int i = 1; i <= 500; ++i) {
				mid = (l + r) * 0.5;
				for (int j = 0; j < n; ++j)
					w[j] = mid * a[j] - (double)a[j] * p[j];
				sort(&w[0], &w[n]);
				reverse(&w[0], &w[n]);
				double t = 0;
				for (int j = 0; j < K; ++j)	t += w[j];
				if (t >= 3600.0 * K)	r = mid;
				else l = mid;
			}
			return mid * totalWork;
		}
};
