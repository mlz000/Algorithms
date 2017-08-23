#include <bits/stdc++.h>
using namespace std;
#define sz(x)	x.size() 
const int N = 55;
bool v[N], num[105];
class GreaterGame {
   	public:
	double calc(vector <int> hand, vector <int> sothe) {
		int n = sz(hand); 
		sort(hand.begin(), hand.end());
		sort(sothe.begin(), sothe.end());
		for (int i = 0; i < n; ++i) {
			if (sothe[i] != -1)	num[sothe[i]] = 1;
			num[hand[i]] = 1;
		}
		double ans = 0.0;
		for (int i = 0; i < n; ++i) {
			if (sothe[i] == -1)	continue;
			bool f = 0;
			for (int j = 0; j < n; ++j)
				if (hand[j] > sothe[i] && !v[j]) {
					ans += 1;
					v[j] = 1;
					f = 1;
					break;
				}
			if (!f) {
				for (int j = 0; j < n; ++j)
					if (!v[j]) {
						v[j] = 1;
						break;
					}
			}
		}
		for (int i = 0; i < n; ++i) {
			if (v[i])	continue;
			double x = 0.0, y = 0.0;
			for (int j = 1; j <= n * 2; ++j) {
				if (!num[j]) {
					y += 1;
					if (j < hand[i])	x += 1;
				}
			}
			ans += x / y;
		}
		return ans;
	}
};
