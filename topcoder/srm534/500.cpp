#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
int p[20];
const int N = 505;
LL a[N];
vector<int> b;
map<LL, LL> dp;
map<LL, LL>:: iterator it;
class EllysNumbers {
	public:
		long long getSubsets(long long n, vector <string> special) {
			string s = accumulate(special.begin(), special.end(), string());
			istringstream ss(s);
			int m = 0, x;
			while (ss >> x)	a[m++] = x;
			for (int i = 0; i < m; ++i)
				if (__gcd(a[i], n / a[i]) == 1)	b.pb(a[i]);
			dp[n] = 1;
			for (int i = 0; i < b.size(); ++i)
				for (it = dp.begin(); it != dp.end(); it++)
					if (it -> F % b[i] == 0) {
						dp[it -> F / b[i]] += it -> S;
					}
			return dp[1];
		}
};
