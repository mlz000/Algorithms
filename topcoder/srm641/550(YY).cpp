#include <bits/stdc++.h>
using namespace std;
#define sz(x)	x.size() 
class ShufflingCardsDiv1 {
    public:
	int shuffle(vector <int> p) {
		int n = sz(p) / 2;
		int cnt = 0;
		bool f = 1;
		for (int i = 0; i < n << 1; ++i)				
			if (p[i] != i + 1)	f = 0; 
		for (int i = 0; i < n; ++i) {
			if (n < p[i << 1])	++cnt;
		}
		if (f)	return 0;
		if (!cnt)	return 1;
		if (cnt == n / 2)	return 2;
		if (cnt == n && (cnt & 1))	return 4;
		return 3;
	}
};
