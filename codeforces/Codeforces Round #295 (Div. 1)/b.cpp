#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
const int N = 100005, M = 1e9 + 9;
typedef pair<int, int> pii;
map<pii, int> g;
int x[N], y[N];
set<int> s;
int gao(int x, int y) {
	if (g.find(mp(x, y)) == g.end())	return 2;
	return g.count(mp(x - 1, y - 1)) + g.count(mp(x, y - 1)) + g.count(mp(x + 1, y - 1));
}
bool ok(int x, int y) {
	return (gao(x + 1, y + 1) > 1 && gao(x, y + 1) > 1 && gao(x - 1, y + 1) > 1); 
}
void check(int x, int y) {
	pii t = mp(x, y);
	if (g.find(t) == g.end())	return;
	int i = g[t];
	if (s.count(i))	return;
	if (ok(x, y))	s.insert(i);
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &x[i], &y[i]);
		g[mp(x[i], y[i])] = i; 
	}
	for (int i = 0; i < n; ++i)	check(x[i], y[i]);
	int now = 1;
	long long ans = 0;
	while (s.size()) {
		int i;
		while (1) {
			set<int>::iterator t;
			if (now)	t = s.end(), t--;
			else t = s.begin();
			i = *t;
			s.erase(i);
			if (ok(x[i], y[i]))	break;
		}
		g.erase(mp(x[i], y[i]));
 		check(x[i] - 1, y[i] - 1);
    	check(x[i], y[i] - 1);
    	check(x[i] + 1, y[i] - 1);
		ans = (ans * n + i) % M;
		now ^= 1;
	}
	printf("%I64d\n", ans);
	return 0;
}
