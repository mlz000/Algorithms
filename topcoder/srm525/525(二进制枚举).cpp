#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int a[N], g[N][N];
#define pb push_back
vector<int> s[N], t[N];
bool ok[N][2];
class Rumor {
	public:
	int getMinimum(string knowledge, vector <string> graph) {
		int n = knowledge.size();
		for (int i = 0; i < n; ++i)
			if (knowledge[i] == 'Y')	a[i] = 1;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (graph[i][j] == 'Y')	g[i][j] = 1;
		int ans = INT_MAX;
		for (int i = 0; i < 1 << n; ++i) {
			memset(ok, 0, sizeof(ok));
			for (int j = 0; j < n; ++j)	s[j].clear(), t[j].clear();
			for (int j = 0; j < n; ++j) {
				if (a[j]) {
					s[j].pb(0), s[j].pb(1);
					if (i >> j & 1)	swap(s[j][0], s[j][1]);
					ok[j][0] = ok[j][1] = 1;
				}
			}
			for (int T = 0; ; ++T) {
				bool f = 1;
				for (int j = 0; j < n; ++j)
					for (int k = 0; k < 2; ++k)
						if (!ok[j][k]) {
							f = 0;
							break;
						}
				if (f) {
					ans = min(ans, T);
					break;
				}
				for (int j = 0; j < n; ++j) 
					if (s[j].size()) {
						f = 1;
						int x = s[j][0];
						for (int k = 0; k < n; ++k)
							if (g[j][k] && !ok[k][x]) {
								ok[k][x] = 1;
								t[k].pb(x);
							}
						s[j].erase(s[j].begin());
					}
				if (!f)	break;
				for (int j = 0; j < n; ++j) {
					for (int k = 0; k < t[j].size(); ++k)	s[j].pb(t[j][k]);
					t[j].clear();
				}
				for (int j = 0; j < n; ++j)	
					if (s[j].size() == 2) {
						s[j][0] = 0, s[j][1] = 1;
						if (i >> j & 1)	swap(s[j][0], s[j][1]);
					}
			}
		}
		return ans == INT_MAX ? -1 : ans;
	}
};
