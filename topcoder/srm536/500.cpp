#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
class RollingDiceDivOne {
	public:
        long long mostLikely(vector <int> dice) {
        	sort(dice.begin(), dice.end(), greater<int>());
			LL len = dice[0], pos = 0;
			int n = dice.size();
			for (int i = 1; i < n; ++i) {
				if (len - 2 * pos >= dice[i]) pos += dice[i] - 1;
				else pos = (len + dice[i] - 2) / 2;
				len += dice[i] - 1;
			}
			return pos + n;
		}
};
