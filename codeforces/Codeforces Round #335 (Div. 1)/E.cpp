#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
const double inf = 1e15;
double p[N][N], lp[N], pro[N], E[N];
bool vis[N];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%lf", &p[i][j]);
			p[i][j] /= 100.0;
		}
		E[i] = inf;
		pro[i] = 1.0;
	}
	E[n] = 0;
	for (int i = 1; i <= n; ++i) {
		int t = -1;
		double mn = inf;
		for (int j = 1; j <= n; ++j)
			if (!vis[j] && E[j] < mn) {
				mn = E[j];
				t = j;
			}
		if (t == -1)	break;
		vis[t] = 1;
		for (int j = 1; j <= n; ++j) 
			if (!vis[j]) {
				lp[j] += E[t] * p[j][t] * pro[j];
				pro[j] *= (1.0 - p[j][t]);
				if (pro[j] < 1)	E[j] = (lp[j] + 1) / (1 - pro[j]);
			}
	}
	printf("%.10lf\n", E[1]);
	return 0;
}
