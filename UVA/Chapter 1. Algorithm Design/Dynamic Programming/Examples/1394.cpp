#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=10005;
int n,k,m,f[N];
int main(){
	while(scanf("%d%d%d",&n,&k,&m)&&n&&m&&k){
		f[1]=0;
		for(int i=2;i<=n;++i)	f[i]=(f[i-1]+k)%i;
		printf("%d\n",(f[n]+m-k+1)%n<=0?((f[n]+m-k+1)%n)+n:(f[n]+m-k+1)%n);
	}
	return 0;
}
