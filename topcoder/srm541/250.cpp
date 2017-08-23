#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
map<char, int> s;
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};
const int N = 55;
int f[N];
bool vis[N];
struct AntsMeet {
	int countAnts(vector <int> x, vector <int> y, string direction) {
		int n = x.size();
		s['N'] = 0, s['E'] = 1, s['W'] = 2, s['S'] = 3;
		for (int i = 0; i < n; ++i)	x[i] <<= 1, y[i] <<= 1, f[i] = s[direction[i]], vis[i] = 1;
		for (int i = 1; i <= 4001; ++i) {
			for (int j = 0; j < n; ++j)
				if (vis[j]) {
					for (int k = j + 1; k < n; ++k)
						if (vis[k]) {
							if (x[j] == x[k] && y[j] == y[k])	vis[j] = vis[k] = 0;
						}
				}
			for (int j = 0; j < n; ++j)
				if (vis[j]) {
					x[j] += dx[f[j]];
					y[j] += dy[f[j]];
				}
		}
		int ans = 0;
		for (int i = 0; i < n; ++i)	
			if (vis[i])	++ans;
		return ans;
	}
};
