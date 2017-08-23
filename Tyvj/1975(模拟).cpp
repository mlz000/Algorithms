#include<cstdio>//核心在于算出N的约数个数，只需要算出每个质因子，然后乘法原理即可 
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1005;
long long tot;
long long seq[N];
long long calc(long long t)
{
   long long ans=1ll;
   long long i;
   for(i=0;i<tot;i++)
   {
      long long tmp=1ll;
	  while(t%seq[i]==0) {t=t/seq[i];tmp++;}
	  ans=ans*tmp;     
   }
   return ans;
}
long long gcd(long long a,long long b) {return b==0?a:gcd(b,a%b);}
int main()
{
    long long t,i,j,k,n,m,ans,p,q;
	scanf("%I64d%I64d",&n,&p);
    m=n;
    for(i=2;i*i<=m;++i)
    {
	  if(m%i==0) 
	  {
			seq[tot++]=i;
			while(m%i==0) m=m/i;
	  } 
	}
	if(m!=1) seq[tot++]=m;
	int yue=calc(n); 
   while(p--)
   {
      scanf("%I64d%I64d",&t,&q);
      if(t==1) {k=gcd(n,q);ans=calc(k);}
      else if(t==2) 
      {
	    if(n%q!=0) ans=0;
	    else ans=calc(n/q);
	  }
	  else if(t==3) 
	  {
		 if(n%q!=0) ans=yue;
		 else ans=yue-calc(n/q);
	  }
	  printf("%I64d\n",ans);
   }
   // system("pause");
    return 0;
}

