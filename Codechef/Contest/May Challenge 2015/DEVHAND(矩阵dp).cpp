#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F first 
#define S second
#define mp make_pair
#define pb push_back
const int M = 1e9 + 7;
const int N = 27;
struct Matrix{
	int arr[15][15];
}A[N], B[N];
Matrix operator*(const Matrix &a, const Matrix &b){
	Matrix tmp;
	memset(tmp.arr, 0, sizeof(tmp.arr));
	for (int i = 0;i <= 14;++i)
		for (int j = 0;j <= 14;++j){
			LL t = 0;
			for (int k = 0; k <= 14; ++k)
				t = (t + (LL)a.arr[i][k] * b.arr[k][j]) % M;
			tmp.arr[i][j] = t;
		}	
	return tmp;
}
Matrix operator^(const Matrix &a, long long m){
	Matrix tmp, A;
	memset(tmp.arr, 0, sizeof(tmp.arr));
	A = a;
	for (int i = 0; i <= 14; ++i)	tmp.arr[i][i] = 1;
	for (;m ; m >>= 1){
		if (m & 1)	tmp = tmp * A;
		A = A * A;
	}
	return tmp;
}
int a[10], b[10], now, mask[1 << 6];
bool check(int *a) {
	if (a[4] + a[5] + a[6] == 2)	return 0;
	if (!a[1] && (a[4] || a[5]))	return 0;
	if (!a[2] && (a[4] || a[6]))	return 0;
	if (!a[3] && (a[5] || a[6]))	return 0;
	return 1;
}
int gao2(int x) {
	if (mask[x] == -1)	mask[x] = ++now;
	return mask[x];
}
int gao3(int x) {
	if (a[1] == 1 && b[1] == 0 && (a[4] || a[5]))	return 0;
	if (a[2] == 1 && b[2] == 0 && (a[4] || a[6]))	return 0;
	if (a[3] == 1 && b[3] == 0 && (a[5] || a[6]))	return 0;
	int t1 = b[4] + b[5] + b[6], t2 = a[4] - b[4] + a[5] - b[5] + a[6] - b[6];
	if (t2 == 1)	t2 = 2;//number of the same
	if (t1 == 3)	t1 = 2;
	int t3 = b[1] + b[2] + b[3] - t1 - t2;	
	int t = 1;
	for (int i = 1; i <= t3; ++i)	t *= x;
	for (int i = 0; i < t2; ++i)	t *= x - i;
	return t;
}
void gao() {
	for (int i = 0; i < 1 << 6; ++i) {
		for (int j = 0; j < 6; ++j)	a[6 - j] = (i >> j & 1);
		if (check(a)) {
			int ta = gao2(i);
			for (int k = 0; k < 1 << 6; ++k) {
				bool f = 1;
				for (int l = 0; l < 6; ++l) {
					b[6 - l] = (k >> l & 1);
					if (b[6 - l] > a[6 - l]) {
						f = 0;
						break;
					}
				}
				if (!f)	continue;
				if (check(b)) {
					int tb = gao2(k);//ta trans to tb
					for (int z = 1; z <= 26; ++z)	A[z].arr[tb][ta] = gao3(z);		
				}
			}
		}
	}
}
int main() {
	int T, n, k;
	memset(mask, -1, sizeof(mask));
	mask[0] = 0;
	gao();
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &k);
		Matrix C = A[k];
		Matrix D;
		memset(D.arr, 0, sizeof(D.arr));
		D.arr[mask[63]][0] = 1;
		D = (C ^ (n + 1)) * D;
		printf("%d\n", D.arr[0][0]);
	}
	return 0;
}
