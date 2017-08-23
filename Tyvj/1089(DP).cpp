#include<cstdio> 
#include<climits> 
#include<iostream>
#include<string> 
#include<cstring>
#include<algorithm>
using namespace std;
const int N=102;
int a[N],b[N],s1[N],s2[N];
int f[2][N*1000];
int main()
{
	int i,j,n,k;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		 scanf("%d %d",&a[i],&b[i]);
	     if(a[i]>0) s1[i]=s1[i-1]+a[i];
	}
	  for(i=1;i<=n;++i)
		for(j=0;j<=s1[i];++j)
	     f[i%2][j]=max(f[1-(i%2)][j],f[1-(i%2)][j-a[i]]+b[i]);
	int ans;
	for(i=s1[n];i>=0;--i)
	 ans=max(ans,f[n%2][i]+i);
	printf("%d\n",ans);     
    system("pause");
	return 0; 
}
