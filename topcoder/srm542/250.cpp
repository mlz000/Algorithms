#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
const int M = 1e9 + 7;
const int N = 5000;
struct PatrolRoute {
    int countRoutes(int X, int Y, int minT, int maxT) {
		LL ans = 0;
  		for (int i = 2; i < X; ++i)
			for (int j = 2; j < Y; ++j) {
				if ((i + j) * 2 >= minT && (i + j) * 2 <= maxT) {
					ans += 1ll * (X - i) * (Y - j) % M * (i - 1) % M * (j - 1) % M;
				}
			}
		return ans * 6 % M;
    }
};
