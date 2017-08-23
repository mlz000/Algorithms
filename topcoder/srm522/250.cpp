#include <bits/stdc++.h>
using namespace std;
class RowAndCoins {
	public:
	string getWinner(string cells) {
		int l = cells.size();
		return cells[0] == 'A' || cells[l - 1] == 'A' ? "Alice" : "Bob";
	}
};
