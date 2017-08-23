//״ѹDp
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
const int N = 16;
int small[51], same[51];
vector<double> ans; 
double dp[N][1 << N];
double gao(int x, int mask, int l) {
	if (dp[x][mask] != -1.0)	return dp[x][mask];
	double &t = dp[x][mask];
	if (mask == (1 << x))	return t = 1.0;
	t = 0.0;
	int cnt = 0;
	for (int i = 0; i < l; ++i) {
		if ((small[i] & mask) > 0)	++cnt;
		else if ((same[i] & mask) != mask)	++cnt, t += gao(x, mask & same[i], l);
	}
	t /= cnt;
	return t;
}
struct StrangeDictionary2 {
    vector <double> getProbabilities(vector <string> words) {
  		int n = words.size(), l = words[0].size();
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < 1 << n; ++j)
				dp[i][j] = -1.0;
		for (int i = 0; i < n; ++i) {
			memset(small, 0, sizeof(small));
			memset(same, 0, sizeof(same));
			for (int k = 0; k < l; ++k)
				for (int j = 0; j < n; ++j) {
					if (words[j][k] < words[i][k])	small[k] |= 1 << j;
					else if (words[j][k] == words[i][k])	same[k] |= 1 << j;
				}
			ans.pb(gao(i, (1 << n) - 1, l));
		}
		return ans;
    }
};
