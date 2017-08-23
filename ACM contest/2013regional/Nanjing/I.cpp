#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1002,pp=1000003;
int f[maxn][maxn][2];
int a[maxn],ans[maxn],mi[101];
int i,j,k,m,n;

int main() {
	mi[0]=1;
	for (i=1;i<=30;i++) mi[i]=mi[i-1]*2%pp;
	while (scanf("%d",&n)!=EOF) {
		for (i=1;i<=n;i++) scanf("%d",&a[i]);
		memset(ans,0,sizeof(ans));
		for (k=0;k<=30;k++) {
			for (i=0;i<=n;i++)
				for (j=0;j<=n;j++)
					f[i][j][0]=f[i][j][1]=0;
			f[0][0][0]=1;
			for (i=0;i<n;i++) {
				for (j=0;j<=i;j++) {
					f[i+1][j][0]=(f[i+1][j][0]+f[i][j][0])%pp;
					f[i+1][j][1]=(f[i+1][j][1]+f[i][j][1])%pp;
					if (a[i+1] & (1<<k)) {
						f[i+1][j+1][0]=(f[i+1][j+1][0]+f[i][j][1])%pp;
						f[i+1][j+1][1]=(f[i+1][j+1][1]+f[i][j][0])%pp;
					}
					else {
						f[i+1][j+1][0]=(f[i+1][j+1][0]+f[i][j][0])%pp;
						f[i+1][j+1][1]=(f[i+1][j+1][1]+f[i][j][1])%pp;
					}
				}
			}
			for (i=1;i<=n;i++) ans[i]=(ans[i]+(long long)mi[k]*f[n][i][1]%pp)%pp;
		}
		for (i=1;i<=n-1;i++) printf("%d ",ans[i]);
		printf("%d\n",ans[n]);
	}
	return 0;
}

