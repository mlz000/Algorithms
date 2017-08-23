#include <bits/stdc++.h>
using namespace std;
class MagicCandy {
	public:
	int whichOne(int n) {
		int last = n;
		while (n > 1) {
			int d = sqrt(n);
			if (d * d == n)	--last;
			n -= d;
		}
		return last;
	}
};
