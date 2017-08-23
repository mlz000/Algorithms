#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=505;
int a[N][N];
long long rx[N],ry[N],bx[N],by[N];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)	scanf("%I64d%I64d",&rx[i],&ry[i]);
	for(int i=1;i<=m;++i)	scanf("%I64d%I64d",&bx[i],&by[i]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(rx[i]<rx[j]){
				long long A=ry[j]-ry[i],B=rx[i]-rx[j],C=-A*rx[i]-B*ry[i];//Ax+By+C=0
				for(int k=1;k<=m;++k)
					if(bx[k]>=rx[i] && bx[k]<rx[j] && A*bx[k]+B*by[k]+C>0)	a[i][j]++;
				a[j][i]=-a[i][j];
			}
	int ans=0;
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			for(int k=j+1;k<=n;++k)
				if(a[i][j]+a[j][k]+a[k][i]==0)	ans++;
	printf("%d\n",ans);
	return 0;
}
