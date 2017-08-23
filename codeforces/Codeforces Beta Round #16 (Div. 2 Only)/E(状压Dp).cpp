#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=20;
int n;
double p[N][N],f[1<<N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			scanf("%lf",&p[i][j]);
	f[(1<<n)-1]=1;
	for(int i=(1<<n)-1;i>=0;--i){
		int x=__builtin_popcount(i);
		if(x<2)	continue;
		double tmp=2*f[i]/x/(x-1);
		for(int j=1;j<=n;++j)
			for(int k=j+1;k<=n;++k)
				if((i&(1<<(j-1))) && (i&(1<<(k-1))))
					f[i^(1<<(k-1))]+=tmp*p[j][k],f[i^(1<<(j-1))]+=tmp*p[k][j];
	}
	for(int i=1;i<=n;++i) printf("%.10lf ",f[1<<(i-1)]);
	return 0;
}
