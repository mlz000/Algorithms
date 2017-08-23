#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
const int N = 55;
int cnt[N][2];
struct TheDevice {
    int minimumAdditional(vector <string> plates) {
  		int n = plates.size(), m = plates[0].size();    
    	for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				++cnt[j][plates[i][j] - '0'];
		int ans = 0;
		for (int i = 0; i < m; ++i) {
			int t = 2;
			if (cnt[i][0] && cnt[i][1])	--t;
			if (cnt[i][1] >= 2)	--t;
			ans = max(ans, t);
		}
		return ans;
	}
};
