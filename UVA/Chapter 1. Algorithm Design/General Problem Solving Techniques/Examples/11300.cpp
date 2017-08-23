#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int N=1000005;
long long a[N],b[N];
long long ABS(long long x)
{
   if(x>=0) return x;
   else return -x;
}
int main()
{
      int i,n;
      while(scanf("%d",&n)!=EOF)
      {
        long long sum=0ll;
        for(i=1;i<=n;++i)
        {
           scanf("%lld",&a[i]);
           sum+=a[i];
        }
        long long ave=sum/n;
        memset(b,0,sizeof(b));
        for(i=1;i<n;++i)
         b[i]=b[i-1]+a[i]-ave;
        sort(&b[1],&b[n+1]);
        long long ans=0ll;
        for(i=0;i<n;++i)
         ans+=ABS(b[i]-b[n/2]);
        printf("%lld\n",ans); 
      }
      //system("pause");
      return 0;
}
