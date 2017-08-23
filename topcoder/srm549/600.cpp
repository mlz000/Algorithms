#include <bits/stdc++.h>//dp
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
vector<pii> g;
const int N = 13, inf = 100;
struct MagicalHats {
	int p[N], r[N], c[N], dp[1594323];
	int n, m, totcoin, tothat, num;
	inline int gao(int mask, int i, int s) {// 0:not selected 1:no coin 2:has coin
		return mask + s * p[i];
	}
	inline int get(int mask, int i) {
		return (mask / p[i]) % 3;
	}
	int dfs(int mask, int cocnt, int hatcnt, int r[], int c[]) {
		if (~dp[mask]) return dp[mask];
		int &t = dp[mask];
		t = -inf;
		if (hatcnt == tothat) {
			if (cocnt != totcoin)	return t = -inf;
			for (int i = 0; i < n; ++i)	
				if (r[i] & 1)	return t = -inf;
			for (int i = 0; i < m; ++i)
				if (c[i] & 1)	return t = -inf;
			return t = 0;
		}
		for (int i = 0; i < tothat; ++i) {
			int x = g[i].F, y = g[i].S;
			int s = get(mask, i);
			if (!s) {//not selected
				int t1 = -inf, t2 = -inf, state;
				if (cocnt < totcoin) {//has coin
					int cnt = 1;
					if (hatcnt >= num)	cnt = 0;
					state = gao(mask, i, 2);
					r[x] += 2;
					c[y] += 2;
					t1 = dfs(state, cocnt + 1, hatcnt + 1, r, c) + cnt;
					r[x] -= 2;
					c[y] -= 2;
				}
				//no coin
				++r[x];
				++c[y];
				state = gao(mask, i, 1);
				t2 = dfs(state, cocnt, hatcnt + 1, r, c);
				--r[x];
				--c[y];
				if (t1 < 0)	t = max(t, t2);
				if (t2 < 0)	t = max(t, t1);
				t = max(t, min(t1, t2));
			}
		}
		return t;
	}
    int findMaximumReward(vector <string> board, vector <int> coins, int numGuesses) {
     	p[0] = 1;
		for (int i = 1; i < 13; ++i)	p[i] = p[i - 1] * 3;
    	this -> n = board.size(), this -> m = board[0].size();
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (board[i][j] == 'H')	g.pb(mp(i, j));
		this -> totcoin = coins.size(), this -> tothat = g.size(), this -> num = numGuesses;
		memset(dp, -1, sizeof(dp));
		int cnt = dfs(0, 0, 0, r, c);
		sort(coins.begin(), coins.end());
		if (cnt < 0)	return -1;
		int ans = 0;
		for (int i = 0; i < cnt; ++i)	ans += coins[i];
		return ans;
	}
};
