#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1 << 7, M = (int)1e9 + 7;
LL a[N][N], b[N][N], c[N][N];
int S;
void mul(LL x[N][N], LL y[N][N]) {
	for (int i = 0; i < S; ++i)
		for (int j = 0; j < S; ++j) {
			c[i][j] = 0ll;
			for (int k = 0; k < S; ++k)	(c[i][j] += x[i][k] * y[k][j]) %= M;
		}
	memcpy(x, c, sizeof(c));
}
int main() {
	for (int i = 0; i < (1 << 7); ++i)	a[i][i] = 1;	
	for (int h = 1, w; h <= 7; ++h) {
		S = 1 << h;
		scanf("%d", &w);
		for (int i = 0; i < S; ++i)
			for (int j = 0; j < S; ++j) {
				b[i][j] = 0;
				for (int k = 0; k < (S >> 1); ++k) 
					if ((i | j | k | (k << 1)) == S - 1)	++b[i][j];
			}
		for (; w; w >>= 1) {
			if (w & 1)	mul(a, b);
			mul(b, b);
		}
	}
	printf("%d\n", a[0][0]);
	return 0;
}
