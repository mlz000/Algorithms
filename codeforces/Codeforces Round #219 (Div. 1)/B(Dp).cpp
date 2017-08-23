#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=45;
int n,m,q,a[N][N],sum[N][N];
char s[N][N];
long long cnt[N][N][N][N];
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;++i){
		scanf("%s",s[i]);
		for(int j=1;j<=m;++j)	a[i][j]=s[i][j-1]-'0';
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
	for(int x1=1;x1<=n;++x1)
		for(int y1=1;y1<=m;++y1)
			for(int x2=x1;x2<=n;++x2)
				for(int y2=y1;y2<=m;++y2)
					cnt[x1][y1][x2][y2]=(sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1]==0);
	for(int x1=n;x1>=2;--x1)
		for(int y1=1;y1<=m;++y1)
			for(int x2=x1;x2<=n;++x2)
				for(int y2=y1;y2<=m;++y2)
					cnt[x1-1][y1][x2][y2]+=cnt[x1][y1][x2][y2];
	for(int x1=1;x1<=n;++x1)
		for(int y1=m;y1>=2;--y1)
			for(int x2=x1;x2<=n;++x2)
				for(int y2=y1;y2<=m;++y2)	
					cnt[x1][y1-1][x2][y2]+=cnt[x1][y1][x2][y2];
	for(int x1=1;x1<=n;++x1)
		for(int y1=1;y1<=m;++y1)
			for(int x2=x1;x2<n;++x2)
				for(int y2=y1;y2<=m;++y2)
					cnt[x1][y1][x2+1][y2]+=cnt[x1][y1][x2][y2];
	for(int x1=1;x1<=n;++x1)
		for(int y1=1;y1<=m;++y1)
			for(int x2=x1;x2<=n;++x2)
				for(int y2=y1;y2<m;++y2)
					cnt[x1][y1][x2][y2+1]+=cnt[x1][y1][x2][y2];
	while(q--){
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		printf("%I64d\n",cnt[x1][y1][x2][y2]);
	}
	return 0;
}

