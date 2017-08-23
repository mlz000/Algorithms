#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
struct KleofasTail {
	LL gao(LL x, LL k) {
		if (k > x)	return 0;
		if (k <= 1)	return x - k + 1;
		LL kk = k + (k % 2 == 0);
		LL t = 0;
		while (k <= x) {
			t += min(x, kk) - k + 1;
			k <<= 1;
			kk = (kk << 1 | 1);
		}
		return t;
	}
    long long countGoodSequences(long long K, long long A, long long B) {
  		return gao(B, K) - gao(A - 1, K);              
    }
};
