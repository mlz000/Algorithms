#include<cstdio>
#include<cstring>
#include<iostream>
const int N=1000005;
int f[N],a[N],q[N];
using namespace std;
int main()
{ 
    int i,j,n,m; 
	scanf("%d%d",&n,&m);
	memset(f,0x3f,sizeof(f));
	for(i=1;i<=n;++i)
	 scanf("%d",&a[i]);
    int l=0,r=0;
    f[0]=0;
    for(i=1;i<=n;++i)
	{
	 while(q[l]<i-m && l<=r) ++l;
	  f[i]=f[q[l]]+a[i]; 
	 while(l<=r && f[q[r]]>=f[i]) r--;
	  q[++r]=i;
	}
	int ans=1000000;
	for(i=n;i>=n-m+1;--i)
	 ans=min(ans,f[i]);
	printf("%d",ans);
	//system("pause");
    return 0;
}
