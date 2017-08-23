#include <bits/stdc++.h>
using namespace std;
const int N = 55;
bool g[N][N];
class GogoXMarisaKirisima {
	public:
	int solve(vector <string> choices) {
		int n = choices.size();
		for (int i = 0; i < n; ++i) {
			g[i][i] = 1;
			for (int j = 0; j < n; ++j)
				if (choices[i][j] == 'Y')	g[i][j] = 1;
		}
		for (int k = 0; k < n; ++k)
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					g[i][j] |= g[i][k] & g[k][j];
		if (!g[0][n - 1])	return 0;
		int ans = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (choices[i][j] == 'Y' && g[0][i] && g[j][n - 1])	++ans;
		for (int i = 1; i < n - 1; ++i)
			if (g[0][i] && g[i][n - 1])	--ans;
		return ans;
	}
};
