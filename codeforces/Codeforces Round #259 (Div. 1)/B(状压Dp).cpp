#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N];
int p[16]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
int f[N][1<<16],s[N],b[N][1<<16],ans[N];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<59;++i)
		for(int j=0;j<16;++j)
			if(i%p[j]==0)	s[i]|=1<<j;
	memset(f,127,sizeof(f));
	for(int i=1;i<=n;++i)	scanf("%d",&a[i]);
	for(int i=0;i<1<<16;++i)	f[0][i]=0;
	for(int i=1;i<=n;++i)
		for(int j=0;j<1<<16;++j)
			for(int k=1;k<59;++k)
				if(!(j&s[k])){
					int t=j|s[k];
					if(f[i][t]>f[i-1][j]+abs(k-a[i])){
						f[i][t]=f[i-1][j]+abs(k-a[i]);
						b[i][t]=k;
					}
				}
	int t=0;
	for(int i=1;i<1<<16;++i)	if(f[n][t]>f[n][i])	t=i;
	for(int i=n;i>=1;--i)	ans[i]=b[i][t],t^=s[b[i][t]];
	for(int i=1;i<=n;++i)	printf("%d ",ans[i]);
	return 0;
}
