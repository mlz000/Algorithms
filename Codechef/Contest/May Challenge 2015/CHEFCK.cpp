#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e7 + 5, M = 1e9 + 7;
int A[N], L[N], R[N], Q[N], pos[N], ans[N];
int main() {
	int n, k, q;
	cin >> n >> k >> q;
	int a, b, c, d, e, f, r, s, t, m;
	cin >> a >> b >> c >> d >> e >> f >> r >> s >> t >> m >> A[1];
	int L1, La, Lc, Lm, D1, Da, Dc, Dm;
	cin >> L1 >> La >> Lc >> Lm >> D1 >> Da >> Dc >> Dm;
	LL now = t * t % s;
	for (int i = 2; i <= n; ++i) {
		if (now <= r)	A[i] = ((LL)a * A[i - 1] % m * A[i - 1] % m + (LL)b * A[i - 1] % m + c) % m;
		else A[i] = ((LL)d * A[i - 1] % m * A[i - 1] % m + (LL)e * A[i - 1] % m + f) % m;
		(now *= t) %= s;
	}
	int st = 1, ed = 0;
	for (int i = 1; i < k; ++i) {
		while (st <= ed && A[i] <= Q[ed])	--ed;
		Q[++ed] = A[i];
		pos[ed] = i;
	}
	for (int i = k; i <= n; ++i) {
		while (st <= ed && A[i] <= Q[ed])	--ed;
		Q[++ed] = A[i];
		pos[ed] = i;
		while (pos[st] < i - k + 1)	++st;
		ans[i - k + 1] = Q[st];
	}
	LL ans1 = 0, ans2 = 1;
	for (int i = 1; i <= q; ++i) {
		L1 = ((LL)La * L1 + Lc) % Lm;
		D1 = ((LL)Da * D1 + Dc) % Dm; 
		L[i] = L1 + 1;
		R[i] = min(L[i] + k - 1 + D1, n);
		int tmp = min(ans[L[i]], ans[R[i] - k + 1]);
		ans1 += tmp;
		(ans2 *= tmp) %= M;
	}
	cout << ans1 << " " << ans2 << endl;
	return 0;
}

