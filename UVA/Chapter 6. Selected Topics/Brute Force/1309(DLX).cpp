#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 20500;
struct DLX{
	int n, sz;
	int S[1500], row[N], col[N], L[N], R[N], U[N], D[N];
	int ansd, ans[5000];
	void init(int n) {
		this -> n = n;//虚拟节点
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
	void remove(int c) {
		L[R[c]] = L[c];
		R[L[c]] = R[c];
		for (int i = D[c]; i != c; i = D[i])
			for(int j = R[i]; j != i; j = R[j]) {
				U[D[j]] = U[j], D[U[j]] = D[j], --S[col[j]];
			}
	}
	void restore(int c) {
		for (int i = U[c]; i != c; i = U[i])
			for (int j = L[i]; j != i; j = L[j]) {
				++S[col[j]], U[D[j]] = j, D[U[j]] = j;
			}
		L[R[c]] = c;
		R[L[c]] = c;
	}
	bool dfs(int d) {
		if (R[0] == 0) {
			ansd = d;
			return true;
		}
		int c = R[0];//找一个未删除的最少的列
		for (int i = R[0]; i != 0; i = R[i]) {
			if (S[i] < S[c])	c = i;	
		}
		remove(c);
		for (int i = D[c]; i != c; i = D[i]) {
			ans[d] = row[i];
			for (int j = R[i]; j != i; j = R[j])	remove(col[j]);
			if (dfs(d+1))	return true;
			for (int j = L[i]; j != i; j = L[j])	restore(col[j]);
		}
		restore(c);
		return false;
	}
	bool solve(vector <int>& v) {
		v.clear();
		if (!dfs(0))	return false;
		for (int i = 0; i < ansd; ++i)	v.push_back(ans[i]);
		return true;
	}
}solver;
char s[20][20];
bool read() {
	for (int i = 0; i < 16; ++i) {
		if (scanf("%s", s[i])!=1)	return false;
	}
	return true;
}
int encode(int a, int b, int c) {
	return a * 256 + b * 16 + c + 1;
}
void decode(int code, int& a, int& b, int& c) {
	--code;
	c = code % 16, code /= 16;
	b = code % 16, code /= 16;
	a = code;
}
int main() {
	int t = 0;
	while (read()) {
		if (++t != 1)	printf("\n");
		solver.init(1024);
		for (int i = 0; i < 16; ++i)
			for (int j = 0; j < 16; ++j)
				for (int k = 0; k < 16; ++k)
					if(s[i][j] == '-' || s[i][j] == 'A' + k) {
						vector <int> columns;
						columns.pb(encode(0, i, j));
						columns.pb(encode(1, i, k));
						columns.pb(encode(2, j, k));
						columns.pb(encode(3, (i / 4) * 4 + j / 4, k));
						solver.addr(encode(i, j, k), columns);
					}
		vector <int> ans;
		solver.solve(ans);
		for (int i = 0; i < ans.size(); ++i) {
			int r, c, v;
			decode(ans[i], r, c, v);
			s[r][c] = 'A' + v;
		}
		for (int i = 0; i < 16; ++i)	printf("%s\n", s[i]);
	}
	return 0;
}
