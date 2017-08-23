#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
struct FoxAndMountainEasy {
    string possible(int n, int h0, int hn, string s) {
    	int l = s.size();
		int mn = 0, now = 0;
		for (int i = 0; i < l; ++i) {
			if (s[i] == 'U')	++now;
			else --now;
			mn = min(mn, now);
		}
		mn = h0 + mn;
		int del = hn - h0 - now;
		n -= l;
		if (mn < 0)	del += mn, n += mn;
		if (abs(del) > n || n < 0)	return "NO";
		int t = del - n;
		if (t & 1)	return "NO";
		return "YES";
    }
};
