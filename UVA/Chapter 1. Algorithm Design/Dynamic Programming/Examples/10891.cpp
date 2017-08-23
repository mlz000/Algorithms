#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=105,INF=1<<30;
int n,a[N],sum[N],f[N][N],g[N][N],d[N][N];
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=105;
int n,a[N],sum[N],f[N][N],g[N][N],d[N][N];
// f[i+1][j] = min{d(i+1,j),d(i+2,j)...,d(j,j)}
// g[i][j-1] = min{d(i,j-1),d(i,j-2)...,d(i,i)}
int main(){
	while(scanf("%d",&n)&&n){
		for(int i=1;i<=n;++i)	scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i],f[i][i]=g[i][i]=d[i][i]=a[i];
		for(int l=1;l<n;++l)
			for(int i=1;i+l<=n;++i){
				int j=i+l;
				int m=0;
				m=min(m,f[i+1][j]);
				m=min(m,g[i][j-1]);
				d[i][j]=sum[j]-sum[i-1]-m;
				f[i][j]=min(d[i][j],f[i+1][j]);
				g[i][j]=min(d[i][j],g[i][j-1]);
			}
		printf("%d\n",2*d[1][n]-sum[n]);
	}
	return 0;
}

int main(){
	while(scanf("%d",&n)&&n){
		for(int i=1;i<=n;++i)	scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i],f[i][i]=g[i][i]=d[i][i]=a[i];
		for(int l=1;l<n;++l)
			for(int i=1;i+l<=n;++i){
				int j=i+l;
				int m=0;
				m=min(m,f[i+1][j]);
				m=min(m,g[i-1][j]);
				d[i][j]=sum[j]-sum[i-1]-m;
				f[i][j]=min(d[i][j],f[i+1][j]);
				g[i][j]=min(d[i][j],g[i][j-1]);
			}
		printf("%d\n",2*d[1][n]-sum[n]);
	}
	return 0;
}
