#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
#define pb push_back
const int Maxc = 65, Maxr = 65, N = 4000;
int n, k;
struct DLX{
	int n, sz;
	int S[Maxc], col[N], L[N], R[N], U[N], D[N];
	bool v[Maxc];
	void init(int n) {
		this -> n = n;
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
			col[sz] = c;
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
	bool dfs(int d) {
		if (d + astar() > k)	return 0;
		if (R[0] == 0) {
			return d <= k;
		}
		int c = R[0];//找一个未删除的最少的列
		for (int i = R[0]; i != 0; i = R[i]) {
			if (S[i] < S[c])	c = i;	
		}
		if (S[c] == 0)	return 0;
		for (int i = D[c]; i != c; i = D[i]) {
			remove(i);
			for (int j = R[i]; j != i; j = R[j])	remove(j);
			if (dfs(d+1))	return 1;
			for (int j = L[i]; j != i; j = L[j])	restore(j);
			restore(i);
		}
		return 0;
	}
	bool solve() {
		if (!dfs(0))	return false;
		return true;
	}
}solver;
long long x[Maxr], y[Maxr], p[Maxc][Maxc];
inline long long D(int a, int b) {
	return (long long)abs(x[a] - x[b]) + abs(y[a] - y[b]);
}
bool ok(long long dis) {
	solver.init(n);
	for (int i = 1; i <= n; ++i) {
		vector <int> columns;
		for (int j = 1; j <= n; ++j)
			if(p[i][j] <= dis)	columns.pb(j);
		solver.addr(i, columns);
	}
	return solver.solve();
}
int main() {
	int T;
	scanf("%d", &T);
	for (int tt = 1; tt <= T; ++tt) {
		vector <long long> d;
		printf("Case #%d: ",tt);
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; ++i)	scanf("%I64d%I64d", &x[i], &y[i]);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j) {
				p[i][j] = D(i, j);
				d.pb(p[i][j]);
			}
		sort(d.begin(), d.end());
		unique(d.begin(), d.end());
		int l = 0, r = d.size() - 1;
		long long ans;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (ok(d[mid]))	r = mid - 1, ans = d[mid];
			else l = mid + 1;
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
