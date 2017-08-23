const int M = 1e9 + 7;
typedef long long ll;
const int D[6][6] = {
	{1, 1, 1, 0, 0, 0},
	{1, 0, 0, 0, 0, 0},
	{0, 1, 0, 0, 0, 0},
	{1, 1, 1, 1, 1, 1},
	{0, 0, 0, 1, 0, 0},
	{0, 0, 0, 0, 1, 0}
};
struct Matrix{
	int arr[6][6];
};
Matrix operator* (const Matrix &a, const Matrix &b){
	Matrix tmp;
	memset(tmp.arr, 0, sizeof(tmp.arr));
	for (int i = 0;i < 6; ++i)
		for (int j = 0;j < 6; ++j){
			ll t = 0;
			for (int k = 0; k < 6; ++k)
				t = (t + (ll)a.arr[i][k] * b.arr[k][j]) % M;
			tmp.arr[i][j] = t;
		}	
	return tmp;
}
Matrix operator^ (const Matrix &a, long long m){
	Matrix tmp, A;
	memset(tmp.arr, 0, sizeof(tmp.arr));
	A = a;
	for (int i = 0; i < 6; ++i)	tmp.arr[i][i] = 1;
	for (;m ; m >>= 1){
		if (m & 1)	tmp = tmp * A;
		A = A * A;
	}
	return tmp;
}
Matrix a, b;
class Solution {
public:
    int checkRecord(int n) {
        a.arr[0][0] = 1;
        memcpy(b.arr, D, sizeof(b.arr));
        Matrix c = (b ^ n) * a;
        int ans = 0;
        for (int i = 0; i < 6; ++i) (ans += c.arr[i][0]) %= M;
        return ans;
    }
};