#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int d[(1 << N) + 10];
class EllysCheckers {
	public:
	string getWinner(string board) {
		int n = board.size();
		int t = 0;
		for (int i = 0; i < n; ++i) {
			if (board[i] == 'o')	t += n - i - 1;
		}
		return t & 1 ? "YES" : "NO";
	}
};
