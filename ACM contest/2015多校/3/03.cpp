#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 55, M = 1e9 + 7;
int a[N];
struct Matrix{
	int n;
	int arr[N][N];
}mat;
Matrix operator*(const Matrix &a, const Matrix &b){
	Matrix tmp;
	memset(tmp.arr, 0, sizeof(tmp.arr));
	int n = mat.n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j){
			int t = 0ll;
			for (int k = 0; k < n; ++k)
				t = (t + (LL)a.arr[i][k] * b.arr[k][j] % M) % M;
			tmp.arr[i][j] = t;
		}	
	return tmp;
}
Matrix operator^(const Matrix &a, int m){
	Matrix tmp, A;
	memset(tmp.arr, 0, sizeof(tmp.arr));
	A = a;
	int n = mat.n;
	for (int i = 0; i < n; ++i)	tmp.arr[i][i] = 1;
	for (; m; m >>= 1){
		if (m & 1)	tmp = tmp * A;
		A = A * A;
	}
	return tmp;
}
bool ok(int x, int y) {
	char s1[15], s2[15];
	sprintf(s1, "%d", x);
	sprintf(s2, "%d", y);
	int l1 = strlen(s1), l2 = strlen(s2);
	for (int i = 0; i < l1; i++) {  
		int k = 0;  
		while (i + k < l1 && k < l2 && s1[i + k] == s2[k])  ++k;
		if (i + k == l1 && k > 1)  
			return 1;  
	}  
    return 0;  
}
int main() {
	int n, m, T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)	scanf("%d", &a[i]);
		sort(a, a + n);
		n = unique(a, a + n) - a;
		memset(mat.arr, 0, sizeof(mat.arr));
		mat.n = n;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) 
				if (ok(a[i], a[j]))	mat.arr[i][j] = 1;
		mat = mat ^ (m - 1);
		int ans = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)	
				(ans += mat.arr[i][j]) %= M;
		printf("%d\n", ans);
	}
	return 0;
}
