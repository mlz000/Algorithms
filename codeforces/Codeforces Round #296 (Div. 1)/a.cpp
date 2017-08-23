#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
typedef long long LL;
set<LL> a[2];
multiset<LL> v[2];
void gao(int p, LL x) {
	set<LL>:: iterator it = a[p].upper_bound(x);
	int t1 = *it;
	it--;
	int t2 = *it;
	v[p].erase(v[p].lower_bound(t1 - t2));
	v[p].insert(t1 - x);
	v[p].insert(x - t2);
	a[p].insert(x);
}
int main() {
	LL w, h, n;
	scanf("%I64d%I64d%I64d", &w, &h, &n);
	a[0].insert(0), a[0].insert(w);
	a[1].insert(0), a[1].insert(h);
	v[0].insert(w), v[1].insert(h);
	while (n--) {
		char s[5];
		LL x;
		scanf("%s%I64d", s, &x);
		if (s[0] == 'H')	gao(1, x);
		else gao(0, x);
		multiset<LL>::iterator it1 = v[0].end(), it2 = v[1].end();
		it1--, it2--;
		printf("%I64d\n", *(it1) * (*it2));
	}
	return 0;
}
