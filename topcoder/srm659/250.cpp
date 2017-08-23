#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int a[N];
class ApplesAndOrangesEasy {
	public:
	int maximumApples(int N, int K, vector <int> info) {
		int sz = info.size(), ans = 0;
		for (int i = 0; i < sz; ++i)	ans += a[info[i]] = 1;
		for (int i = 1; i <= N; ++i) {
			int now = 0;
			for (int j = i; j >= max(1, i - K + 1); --j) {
				if (a[j])	++now;
			}
			if (now < K / 2 && !a[i])	a[i] = 2, ++now, ++ans;
			else if (now > K / 2) {
				for (int j = i; j >= max(1, i - K + 1); --j)
					if (now > K / 2 && a[j] == 2) {
						a[j] = 0;
						--now, --ans;
					}
			}
		}
		return ans;
	}
};
