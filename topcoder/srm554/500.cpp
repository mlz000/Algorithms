#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
const int N = 50;
vector<pii> s;
vector<int> ans;
bool vis[N];
struct TheBrickTowerMediumDivOne {
    vector <int> find(vector <int> a) {
  		int n = a.size();
		ans.pb(0), vis[0] = 1;
		for (int i = 1; i < n; ++i) {
			int p = -1;
			for (int j = 0; j < n; ++j) {
				if (!vis[j] && a[j] <= a[ans[i - 1]]) {
					p = j;
					break;
				}
			}
			if (~p)	ans.pb(p), vis[p] = 1;
			else break;
		}
		for (int i = 0; i < n; ++i)
			if (!vis[i])	s.pb(mp(a[i], i));
		sort(s.begin(), s.end());
		for (int i = 0; i < s.size(); ++i)	ans.pb(s[i].S);
		return ans;
    }
};
