#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
LL gao(vector<int> a) {
	stack<LL> S;
	int n = a.size();
	for (int i = 0; i < 100; ++i)	S.push(0);
	for (int i = 0; i < n; ++i) {
		if (!a[i]) {
			LL x = S.top();
			S.pop();
			LL y = S.top();
			S.pop();
			S.push(x + y);
		}
		else S.push(a[i]);
	}
	return S.top();
}
struct Suminator {
    int findMissing(vector <int> a, int S) {
  		int n = a.size();
		int p;
		for (int i = 0; i < n; ++i)	
			if (a[i] == -1)	p = i;
		a[p] = 0;
		LL t = gao(a);
		if (t == S)	return 0;
		a[p] = 1;
		LL u = gao(a);
		a[p] = 2;
		LL v = gao(a);
		if (u == v)	return -1;
		if (u <= S)	return S - u + 1;
		return -1;
    }
};

