#include <bits/stdc++.h>//greedy
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
const int N = 25;
struct TheJediTest {
    int minimumSupervisors(vector <int> a, int K) {
  		int n = a.size();
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			int t = a[i] / K + (a[i] % K != 0);
			if (a[i] % K != 0) {
				int left = (K * t - a[i]);
				int go;
				if (i + 1 < n) {
					go = min(a[i + 1], left);
					a[i + 1] -= go, left -= go;
				}
				if (i + 2 < n) {
					a[i + 2] -= min(left, a[i + 2]);
				}
			}
			ans += t;
		}
		return ans;
    }
};
