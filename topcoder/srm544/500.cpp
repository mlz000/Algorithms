#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
struct FlipGame {
    int minOperations(vector <string> board) {
  		int ans = -1;
    	int n = board.size(), m = board[0].size();
		while (1) {
			++ans;
			int last = -1;
			bool ok = 0;
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < m; ++j)
					if (board[i][j] == '1')	ok = 1;
			if (!ok)	break;
			for (int i = 0; i < n; ++i) {
				for (int j = last + 1; j < m; ++j)
					if (board[i][j] == '1') {
						last = j;
					}
				for (int j = 0; j <= last; ++j)	
					board[i][j] = (board[i][j] == '1') ? '0' : '1';
			}
		}
		return ans;
	}
};
