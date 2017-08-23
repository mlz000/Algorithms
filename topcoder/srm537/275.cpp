#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
int a, b;
int v[205];
bool check(int x, int y, int num) {
	if (num == a || num == b)	memset(v, -1, sizeof(v));
	if (!num)	return 1;
	if (num < 0)	return 0;
	int &t = v[num];
	if (~t)	return t;
	t = check(x, y, num - x) | check(x, y, num - y);
	return t;
}
class KingXNewCurrency {
        public:
        int howMany(int A, int B, int X) {
			int ans = 0;
			a = A, b = B;
			if (a % X == 0 && b % X == 0)	ans = -1;
			else {
				for (int i = 1; i <= 200; ++i) {
					if (check(X, i, a) && check(X, i, b))	++ans;
				}
			}
			return ans;
		}
};
