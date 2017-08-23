#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
const int N = 55, inf = 1e6;
int d[N][N];
struct ColorfulWolves {
    int getmin(vector <string> colormap) {
  		int n = colormap.size();
		for (int i = 0; i < n; ++i) {
			int now = 0;
			for (int j = 0; j < n; ++j) {
				if (colormap[i][j] == 'Y')	d[i][j] = now++;
				else d[i][j] = inf;
			}
		}
		for (int k = 0; k < n; ++k)
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
		return d[0][n - 1] == inf ? -1 : d[0][n - 1];
    }
};
