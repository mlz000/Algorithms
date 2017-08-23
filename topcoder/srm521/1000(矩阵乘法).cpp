#include<bits/stdc++.h>//a[n]=8a[n-1]-8a[n-2]	n=2n
using namespace std;
typedef long long ll;
#define clr(x,a) memset(x,a,sizeof(x))
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define M 1000000007
struct Matrix{
	int arr[2][2];
};
Matrix operator*(const Matrix &a,const Matrix &b){
	Matrix tmp;
	memset(tmp.arr,0,sizeof(tmp.arr));
	for(int i=0;i<2;++i)
		for(int j=0;j<2;++j){
			ll t=0ll;
			for(int k=0;k<2;++k)
				t=(t+(ll)a.arr[i][k]*b.arr[k][j])%M;
			tmp.arr[i][j]=t;
		}	
	return tmp;
}
Matrix operator^(const Matrix &a,long long m){
	Matrix tmp,A;
	memset(tmp.arr,0,sizeof(tmp.arr));
	A=a;
	for(int i=0;i<2;++i)	tmp.arr[i][i]=1;
	for(;m;m>>=1){
		if(m&1)	tmp=tmp*A;
		A=A*A;
	}
	return tmp;
}
class Chimney{
        public:
        int countWays(long long n){
            n<<=1,--n;
        	Matrix a,b,c; 
			a.arr[0][0]=1,a.arr[0][1]=4,a.arr[1][0]=a.arr[1][1]=0;
			b.arr[0][0]=0,b.arr[0][1]=-8,b.arr[1][0]=1,b.arr[1][1]=8;
			c=a*(b^n);
			return	(c.arr[0][1]+M)%M; 
		}
};
