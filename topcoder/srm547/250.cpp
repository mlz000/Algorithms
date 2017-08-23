#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
struct Pillars {
    double getExpectedLength(int w, int x, int y) {
   		 double ans = 0.0;
		 if (x < y)	swap(x, y);
		 int del = x - y;
		 for (int d = 1 - y; d <= 0; ++d) {
		 	ans += (double)(y + d) * sqrt(1.0 * d * d + w * w);
		 }
		 for (int d = 1; d <= del; ++d) {
		 	ans += (double)y * sqrt(1.0 * d * d + w * w);
		 }
		 for (int d = del + 1; d < x; ++d) {
		 	ans += (double)(x - d) * sqrt(1.0 * d * d + w * w);
		 }
		 return ans / x / y;
    }
};
