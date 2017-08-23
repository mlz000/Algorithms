#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[101000],b[100100];
int main()
{
int m,n,p;
    scanf("%d%d",&m,&n);
    for(p=0;p<m;p++)
    scanf("%d",&a[p]);
    for(p=0;p<n;p++)
    scanf("%d",&b[p]);
sort(a,a+m);
sort(b,b+n);
int i=0,j=0,ans=0,k=0;
for(;i<n;i++)
{
k=1<<20;
for(;j<m;j++)
if(abs(a[j]-b[i])<=k)k=abs(a[j]-b[i]);
else break;
ans+=k;
j--;
}
printf("%d",ans);
}
