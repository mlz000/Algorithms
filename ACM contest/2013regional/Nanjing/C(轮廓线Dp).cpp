#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=105,M=11,MOD=1e9+7;
int n,m,c,d,cur,dp[2][1<<M][22];
char s[N][M+3];
void add(int &x,int y){
	x+=y;
	if(x>=MOD)	x-=MOD;
}
void calc(int a,int b,int ak,int bk){
	if(b&(1<<m))	add(dp[cur][b^(1<<m)][bk],dp[cur^1][a][ak]);
}
int main(){
	while(scanf("%d%d%d%d",&n,&m,&c,&d)==4){
		cur=0;
		memset(dp[cur],0,sizeof(dp[cur]));
		for(int i=0;i<n;++i)	scanf("%s",s[i]);
		dp[0][(1<<m)-1][0]=1;
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j){
				cur^=1;
				memset(dp[cur],0,sizeof(dp[cur]));
				if(s[i][j]=='0'){
					for(int k=0;k<(1<<m);++k)	
						for(int l=0;l<=d;++l)
							calc(k,k<<1|1,l,l);
				}
				else{
					for(int k=0;k<(1<<m);++k)
						for(int l=0;l<=d;++l){
							calc(k,k<<1,l,l);
							if(l<d)	calc(k,k<<1|1,l,l+1);
							if(i && !(k&(1<<(m-1))))	calc(k,(k<<1|1)^(1<<m),l,l);
							if(j && !(k&1))	calc(k,k<<1|3,l,l);
						}
				}
			}
		int ans=0;
		for(int i=c;i<=d;++i)	add(ans,dp[cur][(1<<m)-1][i]);
		printf("%d\n",ans);
	}
	return 0;
}

