#include<iostream>//Dp 左端点和右端点为递增序列，枚举i的4种情况
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define t f[!(i&1)][j][k]
const int N=350,MOD=1000000007;
int f[2][N][N];
void add(int &x,int y){
	x+=y;
	if(x>=MOD)	x-=MOD;
}
int main(){
	int n,m,x;
	scanf("%d%d%d",&n,&m,&x);
	if(n>m)	{printf("0");return 0;}
	f[0][0][0]=1;
	for(int i=1;i<=m;++i){
		for(int j=0;j<=min(i,n);++j)
			for(int k=0;k<=j;++k){
					if(t){
						if(i!=x)	add(f[i&1][j][k],t);
						if(i!=x && j>=k+1)	add(f[i&1][j][k+1],t);
						add(f[i&1][j+1][k],t);
						add(f[i&1][j+1][k+1],t);
						t=0;
					}
			    }
	}
	long long ans=f[m&1][n][n];	
    for(int i=2;i<=n;++i)	ans=ans*i%MOD;
	cout<<ans<<endl;
	return 0;
}
