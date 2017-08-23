#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
vector<LL> B(51);
struct ImportantSequence {
	int getCount(vector <int> b, string operators) {
		int n = b.size();
		for (int i = 0; i < n; ++i)	B[i] = b[i];
		LL L = 1, R = 1e18, now = -1, last = 0;
		for (int i = 0; i < n; ++i) {
			cout << B[i] << endl;
			if (now == 1)	B[i] = last - B[i];
			else B[i] += last;
			now = (now == 1) ? (operators[i] == '+' ? -1 : 1) : (operators[i] == '+' ? 1 : -1);
			if (now == 1)	R = min(R, (LL)B[i] - 1);
			else L = max(L, (LL)B[i] + 1);
			last = B[i];
		}
		return L > R ? 0 : R - L > 2e9 ? -1 : R - L + 1;
	}
};
