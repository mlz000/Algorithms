#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
const int N = 50, M = 1024;
bool d[N][N], f[N][M];
queue<pii> Q;
struct XorTravelingSalesman {
    int maxProfit(vector <int> a, vector <string> s) {
  		int n = a.size();              
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (s[i][j] == 'Y')	d[i][j] = 1;
		int mx = a[0];
		f[0][a[0]] = 1;
		Q.push(mp(0, a[0]));
		while (Q.size()) {
			pii t = Q.front();
			Q.pop();
			for (int i = 0; i < n; ++i) 
				if (d[t.F][i] && !f[i][t.S ^ a[i]]) {
					f[i][t.S ^ a[i]] = 1;
					Q.push(mp(i, t.S ^ a[i]));
					mx = max(mx, t.S ^ a[i]);
				}
		}
		return mx;
    }
};
