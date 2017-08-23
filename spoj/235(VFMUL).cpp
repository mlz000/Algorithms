#include <bits/stdc++.h>//FFT
using namespace std;
#pragma GCC optimize("O2")
typedef complex<double> CP;
const int M = 1 << 20;
const double Pi = acos(-1.0);
char s1[M], s2[M];
int n, po, out[M];
CP a[M], b[M], c[M], w[M], temp[M];
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
int main(){
	int T;
	scanf("%d", &T);
    while(T--){
		memset(out, 0, sizeof(out));
        scanf("%s%s", s1, s2);
		int l1 = strlen(s1), l2 = strlen(s2);
		n = 1, po = 0;
		while(l1 * 2 > n || l2 * 2 > n) n <<= 1, ++po;
		for (int i = 0; i < n; ++i)	w[i]=CP(cos(2 * Pi * i / n), sin(2 * Pi * i / n));
		reverse(s1, s1 + l1), reverse(s2, s2 + l2);
		for (int i = 0; i < l1; ++i)	a[i] = CP(s1[i] - '0', 0);
		for (int i = l1; i < n; ++i)	a[i] = CP(0, 0);
		for (int i = 0; i < l2; ++i)	b[i] = CP(s2[i] - '0', 0);
		for (int i = l2; i < n; ++i)	b[i] = CP(0, 0);
        fft(a, 0, 0);
		fft(b, 0, 0);
        for(int i = 0; i < n; ++i)    c[i] = a[i] * b[i];
        fft(c, 0, 1);   
        for (int i = 0; i < n; ++i) {
			int x = (int)round(c[i].real() / n);
			out[i] += x;
			out[i + 1] += out[i] / 10;
			out[i] %= 10;
		}
        while(n > 1 && !out[n - 1]) --n;
        for(int i = n - 1; i >= 0; --i) printf("%d", out[i]);
		puts("");
    }
    return 0;
}

