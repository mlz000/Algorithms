#include<cstdio>//��i��Ϊ���⣬��ǰi-1���ȷ��������ͬ��ż��Ҳȷ����2^(n-i+1)/2.��2����ָ���ȱ���� 
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
    if(n&1)//����
    {
       ans=pow(2ll,n/2+1)-1;//2����ָ���ȱ����2^(n/2+1)-1
       ans=ans*2%MOD; //��ż�����ͬ 
    } 
    else 
    {
       ans=pow(2ll,n/2)-1;//2^(n/2)-1��ż�����ͬ
       ans=ans*2%MOD;
       ans=(ans+pow(2ll,n/2))%MOD;//�ټ���2^(n/2) 
    } 
    cout<<ans<<endl;
   // system("pause"); 
    return 0;
}
