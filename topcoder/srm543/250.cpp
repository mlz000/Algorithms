#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
LL gao(LL x) {
	LL t = 0;
	for (int i = 40; i >= 0; --i) {
		LL p = 1ll << i;
		if (x == 3 || !x) return t;
		if (x == 2)	return t + 3;
		if (x == 1)	return t + 1;
		if (p <= x) {
			if ((x - p + 1) & 1)	t += p;
			x ^= p;
		}
	}
	return t;
}
struct EllysXors {
    long long getXor(long long L, long long R) {
        return gao(R) ^ gao(L - 1);
    }
};
