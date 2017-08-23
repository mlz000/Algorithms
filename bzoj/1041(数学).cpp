#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
long long r,d,a,b;
long long calc(long long x)
{
    long long tmp=0ll;
    for(long long a=1;a*a*2<x;++a) 
    {
        long long b=sqrt(x-a*a);
        if(a*a+b*b==x && __gcd(a,b)==1) tmp++;
    }   
    return tmp;
}
int main()
{
    long long ans=0ll;
    scanf("%lld",&r);
    r=r<<1ll;
    for(d=1;d*d<=r;++d)
    {
        if(r%d==0)
        {
            ans+=calc(r/d); 
            if(d*d!=r)  ans+=calc(d);
        }
    }
    ans=ans*4+4;
    printf("%lld",ans);
    return 0;
}
