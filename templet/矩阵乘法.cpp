struct Matrix{
	int arr[2][2];
};
Matrix operator*(const Matrix &a, const Matrix &b){
	Matrix tmp;
	memset(tmp.arr, 0, sizeof(tmp.arr));
	for (int i = 0;i < 2;++i)
		for (int j = 0;j < 2;++j){
			ll t = 0ll;
			for (int k = 0; k < 2; ++k)
				t = (t + (ll)a.arr[i][k] * b.arr[k][j]) % M;
			tmp.arr[i][j] = t;
		}	
	return tmp;
}
Matrix operator^(const Matrix &a, long long m){
	Matrix tmp, A;
	memset(tmp.arr, 0, sizeof(tmp.arr));
	A = a;
	for (int i = 0; i < 2; ++i)	tmp.arr[i][i] = 1;
	for (;m ; m>>=1){
		if (m & 1)	tmp = tmp * A;
		A = A * A;
	}
	return tmp;
}
