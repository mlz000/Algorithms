#include <bits/stdc++.h>
using namespace std;
#define sz(x)	x.size() 
const int N = 55;
int rk[N];
class SuffixArrayDiv1 {
    public:
	int minimalCharacters(vector <int> SA) {
		int n = sz(SA), ans = n;
		for (int i = 0; i < n; ++i)	rk[SA[i]] = i;
		rk[n] = -1;//empty
		for (int i = 0; i < n - 1; ++i) {
			if (rk[SA[i] + 1] < rk[SA[i + 1] + 1])	--ans;//s[sa[i]] = s[sa[i+1]]
		}
		return ans;
	}
};
	
