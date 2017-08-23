#include <bits/stdc++.h>
using namespace std;
const int Maxc = 1 << 10, N = 1 << 10;
struct DLX{
	int n, sz, ans;
	int S[Maxc], row[N], col[N], L[N], R[N], U[N], D[N];
	bool v[Maxc];
	void init(int n) {
		this -> n = n;
		ans = INT_MAX;
		for (int i = 0; i <= n; ++i)	U[i] = D[i] = i, L[i] = i - 1, R[i] = i + 1;
		L[0] = n, R[n] = 0;
		sz = n + 1;
		memset(S, 0, sizeof(S));
	}
	void addr(int r, vector <int> columns) {
		int fi = sz;
		for (int i = 0; i < columns.size(); ++i) {
			int c = columns[i];
			L[sz] = sz - 1, R[sz] = sz + 1, D[sz] = c, U[sz] = U[c];
			D[U[sz]] = sz, U[c] = sz;
			row[sz] = r, col[sz] = c;
			++S[c], ++sz;
		}
		R[sz - 1] = fi, L[fi] = sz - 1;
	}
	inline void remove(int c) {
		for (int x = D[c]; x != c; x = D[x])
			L[R[x]] = L[x], R[L[x]] = R[x];
	}
	inline void restore(int c) {
		for (int x = U[c]; x != c; x = U[x])
			L[R[x]] = R[L[x]] = x;
	}
	int astar() {
		int now = 0;
		memset(v, 0, sizeof(v));
		for (int c = R[0]; c; c = R[c])
			if (!v[c]) {
				++now;
				v[c] = 1;
				for (int i = D[c]; i != c; i = D[i])	
					for (int j = R[i]; j != i; j = R[j])
						v[col[j]] = 1;
			}
		return now;
	}
	void dfs(int d) {
		if (d + astar() > ans)	return;
		if (R[0] == 0) {
			ans = min(ans, d);
			return;
		}
		int c = R[0];//找一个未删除的最少的列
		for (int i = R[0]; i != 0; i = R[i]) {
			if (S[i] < S[c])	c = i;	
		}
		if (S[c] == 0)	return;
		for (int i = D[c]; i != c; i = D[i]) {
			remove(i);
			for (int j = R[i]; j != i; j = R[j])	remove(j);
			dfs(d + 1);
			for (int j = L[i]; j != i; j = L[j])	restore(j);
			restore(i);
		}
	}
	int solve() {
		dfs(0);
		if (ans == INT_MAX)	return 0;
		return ans;
	}
}solver;
int c[10][10], a[1 << 9];
int main() {
	c[0][0] = 1;
	for (int i = 1; i <= 8; ++i) {
		c[i][0] = 1;
		for (int j = 1; j <= i; ++j)	c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
	}
	for (int i = 1; i <= 8; ++i) 
		for (int j = 1; j <= i; ++j)
			for (int k = 1; k <= j; ++k) {
				solver.init(c[i][k]);
				memset(a, 0, sizeof(a));
				printf("%d %d %d:", i, j, k);
				if (i == 8 && j == 5 && k == 4) {
					printf("%d\n", 20);
					continue;
				}
				for (int p = 1, q = 0; p < (1 << i); ++p)
					if (__builtin_popcount(p) == k)	a[p] = ++q;
				int t = 0;
				for (int p = 1; p < (1 << i); ++p) {
					vector<int> columns;
					if (__builtin_popcount(p) == j) {
						++t;
						for (int q = p; q; q = (q - 1) & p) {
							if (__builtin_popcount(q) == k)	columns.push_back(a[q]);
						}
						solver.addr(t, columns);
					}
				}
				solver.solve();
				printf("%d\n", solver.ans);
			}
	return 0;
}
