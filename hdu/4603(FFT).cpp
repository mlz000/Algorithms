#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef complex<double> CP;
const int N = 1e5 + 5, M = (1 << 18) + 10;
const double Pi = acos(-1.0);
int n, po, cnt[M], x[N];
CP a[M], c[M], w[M], temp[M];
LL sum[M];
inline void read(int &t) {
    int f = 1;char c;
    while (c = getchar(), c < '0' || c > '9') if (c == '-') f = -1;
    t = c - '0';
    while (c = getchar(), c >= '0' && c <= '9') t = t * 10 + c - '0';
    t *= f;
}
void fft(CP* p, int deep, int flag) {
	if (deep == po)	return;
	int step = 1 << deep;
	fft(p, deep + 1, flag);
	fft(p + step, deep + 1, flag);
	int num= 1 << (po - deep);
	int ss = 0, half = num / 2;
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
	int T;
	read(T);
	while (T--) {
		read(n);
		memset(sum, 0, sizeof(sum));
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; ++i)	read(x[i]), ++cnt[x[i]];
		sort(x + 1, x + n + 1);
		int t = x[n] + 1;
		int l = 1;
		po = 0;
		while (t * 2 > l)	l <<= 1, ++po;
		for (int i = 0; i < l; ++i)	w[i] = CP(cos(2 * Pi * i / l), sin(2 * Pi * i / l));
		for (int i = 0; i < l; ++i)	a[i] = CP(cnt[i], 0.0);
		fft(a, 0, 0);
		for (int i = 0; i < l; ++i)	c[i] = a[i] * a[i];
		fft(c, 0, 1);
		for (int i = 0; i < l; ++i)	sum[i] = (LL)round(c[i].real() / l);
		for (int i = 1; i <= n; ++i)	--sum[x[i] << 1];
		for (int i = 0; i < l; ++i)	sum[i] >>= 1;
		for (int i = 1; i < l; ++i)	sum[i] += sum[i - 1];
		LL ans = 0;
		for (int i = 1; i <= n; ++i) {
			LL t = sum[l - 1] - sum[x[i]];
			t -= (LL)(i - 1) * (n - i);//一大一小
			t -= n - 1;//自己加其他
			t -= (LL)(n - i) * (n - i - 1) / 2;//两大
			ans += t;
		}
		printf("%.7lf\n", 6.0 * ans / n / (n - 1) / (n - 2));
	}
	return 0;
}
