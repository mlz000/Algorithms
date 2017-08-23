#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=505,MOD=1024523;
int f[N][N][N];
char s1[N],s2[N];
void add(int &x,int y)
{
	x+=y;
	if(x>=MOD)	x-=MOD;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s",s1+1);reverse(s1+1,s1+n+1);
	scanf("%s",s2+1);reverse(s2+1,s2+m+1);
	f[0][0][0]=1;
	for(int i=0;i<=n;++i)
		for(int j=0;j<=m;++j)
			for(int k=0;k<=n;++k)
			{
				int l=i+j-k;
				if(l<0 || l>m)	continue;
				if(s1[i+1]==s1[k+1])	add(f[i+1][j][k+1],f[i][j][k]);
				if(s1[i+1]==s2[l+1])	add(f[i+1][j][k],f[i][j][k]);
				if(s2[j+1]==s2[l+1])	add(f[i][j+1][k],f[i][j][k]);
				if(s2[j+1]==s1[k+1])	add(f[i][j+1][k+1],f[i][j][k]);
			}
	printf("%d\n",f[n][m][n]);
	return 0;
}
