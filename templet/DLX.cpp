//精确覆盖
struct DLX{
	int n, sz;
	int S[Maxc], row[N], col[N], L[N], R[N], U[N], D[N];
	int ansd, ans[Maxr];
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
//重复覆盖
struct DLX{
	int n, sz;
	int S[Maxc], row[N], col[N], L[N], R[N], U[N], D[N];
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
