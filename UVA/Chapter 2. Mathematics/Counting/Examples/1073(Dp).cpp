#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N=1005;
long long f[N][N][2][2];
int n,ca;
int main(){
	f[0][1][1][1]=1;
	for(int i=1;i<=1000;++i)	f[i][0][0][0]=1;
	for(int i=1;i<=1000;++i)
		for(int j=max(1,i-5);j<=i+1;++j)
			for(int k=0;k<=1;++k)
				f[i][j][k][0]=f[i-1][j][k][0]+f[i-1][j][k][1],f[i][j][k][1]=f[i][j-1][k][0];
	while(scanf("%d",&n)&&n){
		ca++;
		printf("Case %d: ",ca);
		if(n&1 || n<3)	printf("0\n");
		else printf("%lld\n",f[(n+4)/2][(n-4)/2][0][0]+f[(n+4)/2][(n-4)/2][0][1]+f[(n+4)/2][(n-4)/2][1][0]);
	}
	return 0;
}
