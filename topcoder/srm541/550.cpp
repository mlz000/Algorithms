#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
const int M = 1e9 + 7;
struct AkariDaisukiDiv1 {
	int gao(const string &s, const string &t, int l = 0, int r = 100000000) {
		int tmp = 0;
		for (int i = l; i < s.size() - t.size() + 1 && i < r; ++i)
			if (s.substr(i, t.size()) == t)	++tmp;
		return tmp;
	}
    int countF(string A, string B, string C, string S, string F, int k) {
   		int cnt = 0;
		for (; cnt < k && S.size() < F.size(); ++cnt)	S = A + S + B + S + C;
		if (S.size() < F.size())	return 0;
		int ans = gao(S, F), t = 0;	
		string p = S.substr(0, F.size()), q = S.substr(S.size() - F.size(), F.size());
		for (int i = 0; cnt < k && i < 50; ++cnt, ++i) {
			t = gao(A + p, F, 0, A.size()) + gao(q + B + p, F, 1, F.size() + B.size()) + gao(q + C, F, 1);
			ans = (ans + ans + t) % M;
			p = (A + p).substr(0, F.size()), q = (q + C).substr((q + C).size() - F.size(), F.size());
		}
		for (; cnt < k; ++cnt)	ans = (ans + ans + t) % M;
		return ans;
	}
};
