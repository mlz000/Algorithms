#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int N=505,MOD=1000007;
int T,n,m,k,c[N][N];
int main(){
	c[0][0]=1;
	for(int i=0;i<N;++i){
		c[i][0]=c[i][i]=1;
		for(int j=1;j<i;++j)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
	}
	scanf("%d",&T);
	for(int tt=1;tt<=T;++tt){
		printf("Case %d: ",tt);
		scanf("%d%d%d",&n,&m,&k);
		int ans=0;
		for(int s=0;s<16;++s){
			int b=0,R=n,C=m;
			if(s&1)	R--,b++;
			if(s&2)	R--,b++;
			if(s&4)	C--,b++;
			if(s&8)	C--,b++;
			if(b&1)	ans=(ans+MOD-c[R*C][k])%MOD;
			else ans=(ans+c[R*C][k])%MOD;
		}
		printf("%d\n",ans);
	}
	return 0;
}
