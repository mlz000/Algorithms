#include <bits/stdc++.h>
using namespace std;
double p[10], pp[7][7][7][7][7],  dp[(1 << 14) + 5];
int cnt[10], x[7], sum[7][7][7][7][7][14];
bool f[15], v[7][7][7][7][7];
void gao(int *x, double t) {
	memset(cnt, 0, sizeof(cnt));
	sort(&x[0], &x[5]);
	if (v[x[0]][x[1]][x[2]][x[3]][x[4]]) {
		pp[x[0]][x[1]][x[2]][x[3]][x[4]] += t;
		return;
	}
	pp[x[0]][x[1]][x[2]][x[3]][x[4]] = t;
	v[x[0]][x[1]][x[2]][x[3]][x[4]] = 1;
	int summ = 0;
	for (int i = 0; i < 5; ++i) {
		cnt[x[i]]++, summ += x[i];
	}
	memset(sum[x[0]][x[1]][x[2]][x[3]][x[4]], 0, sizeof(sum[x[0]][x[1]][x[2]][x[3]][x[4]]));
	for (int i = 0; i < 6; ++i)
		sum[x[0]][x[1]][x[2]][x[3]][x[4]][i] = cnt[i + 1] * (i + 1);
	bool ok2 = 0, ok3 = 0;
	for (int i = 6; i <= 13; ++i)	f[i] = 0;
	int tot = 0;
	for (int i = 1; i <= 6; ++i) {
		if (cnt[i] == 2)	ok2 = 1, ++tot;
		if (cnt[i] >= 3)	f[7] = 1;
		if (cnt[i] >= 4)	f[8] = 1;
		if (cnt[i] == 3)	ok3 = 1;
		if (i <= 3) {
			if (cnt[i] && cnt[i + 1] && cnt[i + 2] && cnt[i + 3])	f[10] = 1;
		}
		if (i <= 2) {
			if (cnt[i] && cnt[i + 1] && cnt[i + 2] && cnt[i + 3] && cnt[i + 4])	f[11] = 1;
		}
		if (cnt[i] == 5)	f[12] = 1;
	}
	if (ok2 && ok3)	f[9] = 1;
	if (tot == 2)	f[6] = 1;
	if (f[6] || (ok2 && ok3))	sum[x[0]][x[1]][x[2]][x[3]][x[4]][6] = summ;
	if (f[7])	sum[x[0]][x[1]][x[2]][x[3]][x[4]][7] = summ;
	if (f[8])	sum[x[0]][x[1]][x[2]][x[3]][x[4]][8] = summ;
	if (f[9])	sum[x[0]][x[1]][x[2]][x[3]][x[4]][9] = 25;
	if (f[10])	sum[x[0]][x[1]][x[2]][x[3]][x[4]][10] = 30;
	if (f[11])	sum[x[0]][x[1]][x[2]][x[3]][x[4]][11] = 40;
	if (f[12])	sum[x[0]][x[1]][x[2]][x[3]][x[4]][12] = 50;
	sum[x[0]][x[1]][x[2]][x[3]][x[4]][13] = summ;
}
int main() {
	int T;
	scanf("%d", &T);
	for (int tt = 1; tt <= T; ++tt) {
		memset(sum, 0, sizeof(sum));
		memset(v, 0, sizeof(v));
		printf("Case #%d: ", tt);
		for (int i = 1; i <= 6; ++i)	scanf("%lf", &p[i]);
		for (int a = 1; a <= 6; ++a)
			for (int b = 1; b <= 6; ++b)
				for (int c = 1; c <= 6; ++c)
					for (int d = 1; d <= 6; ++d)
						for (int e = 1; e <= 6; ++e) {
							double t = p[a] * p[b] * p[c] * p[d] * p[e];
							x[0] = a, x[1] = b, x[2] = c, x[3] = d, x[4] = e;
							gao(x, t);
						}
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i < 1 << 14; ++i) {
			for (int a = 1; a <= 6; ++a)
				for (int b = a; b <= 6; ++b)
					for (int c = b; c <= 6; ++c)
						for (int d = c; d <= 6; ++d)
							for (int e = d; e <= 6; ++e) {
								double t = 0.0;
								for (int j = 0; j < 14; ++j)
									if ((i >> j & 1))	
										t = max(t, dp[i ^ (1 << j)] + sum[a][b][c][d][e][j]);
								dp[i] += t * pp[a][b][c][d][e];
							}
		}
		printf("%.6lf\n", dp[(1 << 14) - 1]);
	}
	return 0;
}
