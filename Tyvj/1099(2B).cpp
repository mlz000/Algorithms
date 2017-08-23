#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=200005;
int a[N];
bool cmp(const int p,const int q)
{
   return p>q;
}
int main()
{
	int i,n,b;
    scanf("%d%d",&n,&b);
    for(i=1;i<=n;++i)
     scanf("%d",&a[i]);
    sort(&a[1],&a[n+1],cmp);
    int ans=0,sum=0;
    for(i=1;i<=n;++i)
    {
	  sum+=a[i];
	  ans++;
	  if(sum>=b) break;
	}
	printf("%d",ans);
    return 0;
}
