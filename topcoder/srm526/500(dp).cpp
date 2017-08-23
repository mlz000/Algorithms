#include <bits/stdc++.h>
using namespace std;
const int M = 500000;
int tot, p[M];
bool check[M];
#define F first
#define S second
#define mp make_pair
int dp[2][M];
void init() {
	for (int i = 2; i < M; ++i) {
		if (!check[i])	p[++tot] = i;
		for (int j = 1; j <= tot && i * p[j] < M; ++j) {
			check[i * p[j]] = 1;
			if (i % p[j] == 0)	break;
		}
	}
}
set<pair<int, int> > prpo[2], prne[2], copo[2], cone[2];
int findmin(set<pair<int, int> > &t, int x) {
	while (!t.empty()) {
		set<pair<int, int> >:: iterator it = t.begin();
		if (it -> S < x) t.erase(it);
		else return it -> F;
	}
	return 0;
}
int findmax(set<pair<int, int> > &t, int x) {
	while (!t.empty()) {
		set<pair<int, int> >:: reverse_iterator it = t.rbegin();
		if (it -> S < x)	t.erase(t.find(*it));
		else return it -> F;
	}
	return 0;
}
class PrimeCompositeGame {
	public:
	int theOutcome(int N, int K) {
		init();
		for (int i = 1; i <= N; ++i) {
			for (int j = 0; j < 2; ++j) {
				int pick = 0;
				if (j == 0) {
					pick = findmin(prpo[1], i - K);	//win		
					if (!pick)	pick = findmin(prne[1], i - K);	//lose
				}
				else {
					pick = findmax(cone[0], i - K);
					if (!pick)	pick = findmax(copo[0], i - K);
				}
				if (!pick) {
					if (j == 0)	dp[j][i] = -1;
					else dp[j][i] = 1;
				}
				else {
					if (pick < 0)	dp[j][i] = pick - 1;
					else dp[j][i] = pick + 1;
				}
			}
			for (int j = 0; j < 2; ++j) {
				if (i == 1)	break;
				if (check[i]) {//co
					if (dp[j][i] > 0)	copo[j].insert(mp(dp[j][i], i));
					else cone[j].insert(mp(dp[j][i], i));
				}	
				else {//pr
					if (dp[j][i] > 0)	prpo[j].insert(mp(dp[j][i], i));
					else prne[j].insert(mp(dp[j][i], i));
				}
			}
		}
		int t = dp[0][N];
		if (t > 0)	return t - 1;
		else return t + 1;
	}
};
