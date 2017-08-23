#include<cstdio>
#include<iostream>
#include<algorithm>
#include<climits>
#include<cstring>
using namespace std;
const  int N=50005;
int a[N],f[N]; 
int n,t; 
bool check(int x)
{
    int i,j;
	for(i=1;i<=n;++i)
     {
	   f[i]=INT_MAX;
	  for(j=1;j<=x+1;++j)
	   if(i-j>=0) f[i]=min(f[i],f[i-j]+a[i]);//最多连续空x段 
     }
     int MIN=10000000;
     for(i=n;i>=n-x;--i)
      MIN=min(MIN,f[i]);
     return MIN<=t;
}
int main()
{
    int i;
	scanf("%d%d",&n,&t);
	for(i=1;i<=n;++i)
	 scanf("%d",&a[i]);
	int l=0,r=n;
	while(l<=r)
	{
	   if(l==r) break;
	   int mid=(l+r)>>1;
	   if(check(mid)) r=mid;
	   else l=mid+1;
	} 
	printf("%d",r);
	//system("pause");
    return 0;
}
