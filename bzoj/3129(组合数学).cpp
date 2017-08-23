#include<cstdio>
using namespace std;
long long n,m,delta,lim;
long long qp(long long b,long long e)
{    long long t,s;
   s=1,t=b;
   while (e)
   {    if (e&1)
       {    s=s*t;
           s%=lim;
       }
       t=t*t;
       t%=lim;
       e/=2;
   }
   return s%lim;
}
long long work()
{    long long ans,t;
   if (n==1)
       return m%lim;
   ans=m-(n-1)*delta;
   ans%=lim;
   ans*=qp(delta,n-1);
   ans%=lim;
   if (delta&1) 
   {    t=(delta-1)/2*qp(delta,n-1);
       t%=lim;
   }
   else
   {    t=delta/2*(delta-1);
       t%=lim;
       t*=qp(delta,n-2);
       t%=lim;
   }
   t=t*(n-1)%lim;
   ans=(ans+t)%lim;
   return ans;
}
int main()
{   long long ans; 
   scanf("%lld%lld%lld%lld",&m,&n,&delta,&lim);
   printf("%lld\n",work());
   return 0;
}
