#include <bits/stdc++.h>
using namespace std;
#define sz(x)	x.size() 
int sg[1005][3][3];
int dp(int l, int x, int y) {
	int &t = sg[l][x][y];
	if (~t)	return t;
	if (!l)	return 0;
	map<int, bool> mp;
	for (int i = 0; i < l; ++i)
		for (int j = 1; j <= 2; ++j) {
			if (!i && x + j == 3)	continue;
			if (i == l - 1 && j + y == 3)	continue;
			int tmp = dp(i, x, j) ^ dp(l - i - 1, j, y);
			mp[tmp] = 1;
		}
	for (int i = 0; ; ++i)	if (mp.find(i) == mp.end())	return t = i;
}
class PathGame {
    public:
	string judge(vector <string> board) {
		int n = sz(board[0]);
		memset(sg, -1, sizeof(sg));
		int st = 0, pre = 0, ans = 0, now;
		for (int i = 0; i < n; ++i) {
			now = 0;
			if (board[0][i] == '#')	now = 1;
			if (board[1][i] == '#')	now = 2;
			if (now > 0) {
				ans ^= dp(i - st, pre, now);
				st = i + 1;
				pre = now;
			}
		}
		ans ^= dp(n - st, pre, 0);
		return ans ? "Snuke" : "Sothe";
	}
};
