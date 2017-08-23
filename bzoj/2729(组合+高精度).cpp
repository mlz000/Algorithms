#include<cstdio>		//(c[n+1][2]*c[n+3][m]+c[n+1][1]*c[n+2][m-1])*A[n][n]*A[m][m]*A[2][2]
#include<algorithm>
#include<iostream>
#include<cmath>
#include<ctime>
using namespace std;
const int MOD=1000000,N=2005;
struct Bign
{
	int num[N],l;
	inline void operator +=(const Bign &b)
	{
		int jin=0;
		for(int i=2000;i>=l;--i)
		{
			num[i]=num[i]+b.num[i]+jin;
			jin=num[i]/MOD;
			num[i]%=MOD;
		}
		while(jin)
		{
			num[--l]=jin%MOD;
			jin/=MOD;
		}
	}	
	inline void operator *=(int p)
	{
		int jin=0;
		for(int i=2000;i>=l;--i)
		{
			num[i]=num[i]*p+jin;
			jin=num[i]/MOD;
			num[i]%=MOD;
		}
		while(jin)
		{
			num[--l]=jin%MOD;
			jin/=MOD;
		}
	}
	inline void print()
	{
	    printf("%d",num[l]);
	    for(l++;l<=2000;++l)
	    printf("%06d",num[l]);
	}
}ans,tmp;
int main()
{
	  int n,m;
	  scanf("%d%d",&n,&m);
	  ans.l=2000;ans.num[2000]=1;
	  for(int i=1;i<=n;++i)
	  ans*=i;
	  for(int i=n+3;i>=n-m+4;--i)
	  ans*=i;  
	  ans*=n;ans*=(n+1);
	  tmp.l=2000;tmp.num[2000]=1;
	  for(int i=n+2;i>=n-m+4;--i)
	  tmp*=i;
	  for(int i=1;i<=n;++i)
	  tmp*=i;
	  tmp*=m;tmp*=2;tmp*=(n+1);
	  ans+=tmp;
	  ans.print();
      return 0;
}
