#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=160,M=51123987;
char s[N];
int next[N][3],f[N][N/3][N/3][N/3];
void add(int &x,int y){
	x+=y;
	if(x>=M)	x%=M;
}
int main(){
	int n;
	scanf("%d",&n);
	scanf("%s",s);
	next[n][0]=next[n][1]=next[n][2]=n;
	for(int i=n-1;i>=0;--i){
		next[i][0]=next[i+1][0],next[i][1]=next[i+1][1],next[i][2]=next[i+1][2];
		next[i][s[i]-'a']=i;
	}
	int m=(n+2)/3;
	int ans=0;
	f[0][0][0][0]=1;
	for(int i=0;i<n;++i)
		for(int j=0;j<=m;++j)
			for(int k=0;k<=m;++k)
				for(int l=0;l<=m;++l){
					if(j+k+l==n && abs(j-k)<=1 && abs(j-l)<=1 && abs(k-l)<=1)	add(ans,f[i][j][k][l]);
						add(f[next[i][0]][j+1][k][l],f[i][j][k][l]);
						add(f[next[i][1]][j][k+1][l],f[i][j][k][l]);
						add(f[next[i][2]][j][k][l+1],f[i][j][k][l]);
				}
	printf("%d",ans);
	return 0;
}
