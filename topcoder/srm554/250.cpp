#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
struct TheBrickTowerEasyDivOne {
    int find(int r1, int h1, int r2, int h2) {
  		if (h1 == h2) {
			return 2 * min(r1, r2) + (r1 == r2 ? 0 : 1);
		}
		else {
			return 2 * min(r1, r2) + (r1 > r2) + min(r1, r2) + (r2 > r1);
		}
    }
};



