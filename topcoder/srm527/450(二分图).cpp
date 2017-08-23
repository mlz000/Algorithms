#include <bits/stdc++.h>
using namespace std;
const int N = 35;
int n, m, g[N][N], l[N], v[N];
bool check(vector <string> a, vector <string> b, int x, int y) {
	for (int i = 0; i < n; ++i) {
		char c = a[i][x], d = b[y][i];
		if (c != d && c != '?' && d != '?')	return 0; 
	}
	return 1;
}
bool can(int u) {
	for (int i = 0; i < m; ++i) {
		if (g[u][i] && !v[i]) {
			v[i] = 1;
			if (l[i] == -1 || can(l[i])) {
				l[i] = u;
				return 1;
			}
		}
	}
	return 0;
}
bool ok() {
	memset(l, -1, sizeof(l));
	int cnt = 0;
	for (int i = 0; i < m; ++i) {
		memset(v, 0, sizeof(v));
		if (can(i))	++cnt;
	}
	return cnt == m;
}
class P8XMatrixRecovery {
	public:
	vector <string> solve(vector <string> rows, vector <string> columns) {
		n = rows.size(), m = columns.size();
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				if (rows[i][j] != '?')	continue;
				rows[i][j] = '0';
				memset(g, 0, sizeof(g));
				for (int k = 0; k < m; ++k)
					for (int l = 0; l < m; ++l)
						if (check(rows, columns, k, l))	g[k][l] = 1;
				if (!ok())	rows[i][j] = '1';
			}
		return rows;
	}
};
