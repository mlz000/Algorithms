#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<climits> 
using namespace std;
const int N=1000005;
long long x,ans,a[N],sum[N];
int main()
{
    int i,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)   
    {
        scanf("%lld",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    x=sum[n]/n;
    for(i=1;i<=n;++i)   sum[i]-=x*i;
    sort(&sum[1],&sum[n+1]);
    int mid=sum[(n+1)/2];
    for(i=1;i<=n;++i)   ans+=abs(sum[i]-mid);
    printf("%lld",ans);
    return 0;
}
