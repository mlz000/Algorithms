#include <bits/stdc++.h>
using namespace std;
typedef complex<double> CP;
const double Pi = acos(-1.0);
const int N = 100005, M = 1 << 16, S = 30, len = 16;;
int n, a[N];
int cnt[M], pre[M], in[M], now[M];
CP w[M], temp[M], x[M], y[M], z[M];
void fft(CP* p,int deep,int flag) {
	if (deep == len)	return;
	int step= 1 << deep;
	fft(p, deep + 1, flag);
	fft(p + step, deep + 1, flag);
	int num= 1 << (len - deep);
	int ss=0, half = num / 2;
	CP a,b;
	for (int i = 0; i < half; ++i) {
		a = p[ss];
		b = p[ss + step];
		if (!flag)	b *= w[i << deep];
		else b /= w[i << deep];
		temp[i] = a + b;
		temp[i + half] = a - b;
		ss += 2 * step;
	}
	for (int i = 0; i < num; ++i)	p[i * step] = temp[i];
	return;
}
int main() {
	scanf("%d", &n);
	int mx = 0;
	for (int i = 0; i < n; ++i)	scanf("%d", &a[i]), ++cnt[a[i]];
	for (int i = 0; i < M; ++i)	w[i]=CP(cos(2 * Pi * i / M), sin(2 * Pi * i / M));
	int i = 0;
	long long ans = 0ll;
	int sz = ceil((double)n / 30);
	while (i * sz < n){
		int l = i * sz, r = min((i + 1) * sz, n);
		memset(in, 0, sizeof(in));
		memset(now, 0, sizeof(now));
		for (int j = l; j < r; ++j)	++in[a[j]];
		for (int j = 0; j < M; ++j)	x[j] = CP(pre[j], 0), y[j] = CP(cnt[j] - in[j] - pre[j], 0);
		fft(x, 0, 0);
		fft(y, 0, 0);
		for (int j = 0; j < M; ++j)	z[j] = x[j] * y[j];
		fft(z, 0, 1);
		for (int j = l; j < r; ++j) {
			++now[a[j]];
			int mid = a[j] << 1;
			ans += round(z[mid].real() / M);//两个数都不在本块中
			for (int k = l; k < r; ++k)
				if (k < j && mid - a[k] >= 0) {
					int num = mid - a[k];
					ans += cnt[num] - pre[num] - now[num];	//一个在后面
				}
				else if (k > j && mid - a[k] >= 0) {
					int num = mid - a[k];
					ans += pre[num];
				}
		}
		for (int j = l; j < r; ++j)	++pre[a[j]];
		++i;
	}
	printf("%lld\n", ans);
	return 0;
}	
