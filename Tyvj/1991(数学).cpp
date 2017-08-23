#include<cstdio>//第i项为蛋糕，即前i-1项均确定，后面同奇偶的也确定即2^(n-i+1)/2.即2的幂指数等比求和 
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath> 
using namespace std;
const int MOD=1000000007;
long long pow(long long a,long long p)
{
    if(p==0) return 1;
    long long t=pow(a,p>>1);
    t=t*t%MOD;
    if(p&1) t=t*a%MOD;
    return t; 
} 
int main()
{ 
    long long n,ans; 
    scanf("%I64d",&n);
    if(n&1)//奇数
    {
       ans=pow(2ll,n/2+1)-1;//2的幂指数等比求和2^(n/2+1)-1
       ans=ans*2%MOD; //奇偶情况相同 
    } 
    else 
    {
       ans=pow(2ll,n/2)-1;//2^(n/2)-1奇偶情况不同
       ans=ans*2%MOD;
       ans=(ans+pow(2ll,n/2))%MOD;//再加上2^(n/2) 
    } 
    cout<<ans<<endl;
   // system("pause"); 
    return 0;
}
