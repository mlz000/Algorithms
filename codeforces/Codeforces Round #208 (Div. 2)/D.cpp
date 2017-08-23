#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int N=3005;
int a[N],b[N],c[N],f[N][2];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)	scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)	scanf("%d",&b[i]);
	for(int i=1;i<=n;++i)	scanf("%d",&c[i]);
	f[1][1]=a[1],f[1][0]=b[1];
	for(int i=2;i<=n;++i)
	{
		f[i][0]=max(f[i-1][0]+b[i],f[i-1][1]+c[i]);
		f[i][1]=max(f[i-1][0]+a[i],f[i-1][1]+b[i]);
	}
	printf("%d\n",f[n][1]);
	return 0;
}
