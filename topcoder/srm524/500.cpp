#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
bool vis[N];
vector<int> C;
class LongestSequence {
	public:
	void dfs(int u, int len) {
		for (int i = 0, v; i < C.size(); ++i) {
			v = u + C[i];
			if (v >= 0 && v <= len && !vis[v]) {
				vis[v] = 1;
				dfs(v, len); 
			}
		}
	}
	bool check(int len) {
		dfs(0, len);
		return !vis[0];
	}
	int maxLength(vector <int> c) {
		int ans = 0;
		C = c;
		int l = 0, r = 2000;
		if (check(r))	ans = -1;
		else {
			while (l <= r) {
				memset(vis, 0, sizeof(vis));
				int mid = l + r >> 1;
				if (check(mid))	ans = mid, l = mid + 1;
				else r = mid - 1;
			}
		}
		return ans;
	}
};
