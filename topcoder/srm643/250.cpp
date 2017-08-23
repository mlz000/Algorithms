#include <bits/stdc++.h>
using namespace std;
#define sz(x)	x.size() 
#define pb push_back
vector<long long> ans;
class TheKingsFactorization {
    public:
	vector<long long> getVector(long long N, vector<long long> primes) {
		int m = sz(primes);
		for (int i = 0; i < m; ++i)	N /= primes[i];
		for (int i = 0; i < m - 1; ++i) {
			ans.pb(primes[i]);
			for (long long j = primes[i]; j <= primes[i + 1]; ++j) {
				if (j * j > N) {
					if (N > 1)	ans.pb(N), N = 1;
					break;
				}
				if (0 == N % j) {
					N /= j;
					ans.pb(j);
					break;
				}
			}
		}
		ans.pb(primes[m - 1]);
		if (N > 1)	ans.pb(N);
		return ans;
	}
};	 
