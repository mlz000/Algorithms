#include<cstdio> 
#include<climits> 
#include<iostream>
#include<string> 
#include<cstring>
#include<algorithm>
using namespace std;
const int N=35;
int n,m,MOD;
struct ma 
{
   int n;
   int m[N][N];	
   void clear()
   { 
     for(int i=1;i<=n;++i)
	  for(int j=1;j<=n;++j)
	   m[i][j]=0; 
   }		
   void in(int t)
   {
      n=t;
      for(int i=1;i<=n;++i)
       for(int j=1;j<=n;++j)
        scanf("%d",&m[i][j]);
   }
   void out()
   {
     for(int i=1;i<=n;++i)
     {
	    for(int j=1;j<n;++j)
         printf("%d ",m[i][j]);
        printf("%d\n",m[i][n]);
	 }
   }
   void operator +=(const ma &b)
   {
      for(int i=1;i<=n;++i)
       for(int j=1;j<=n;++j)
        m[i][j]=(m[i][j]+b.m[i][j])%MOD;
   }
}a,b,f;
ma operator *(const ma &a,const ma &b)
{
    ma c;
    c.n=n;
    c.clear();
    for(int i=1;i<=n;++i)
     for(int j=1;j<=n;++j)
      for(int k=1;k<=n;++k)
      c.m[i][j]=(c.m[i][j]+a.m[i][k]*b.m[k][j])%MOD;
    return c;
}
int main()
{
    int i;
    scanf("%d%d%d",&n,&m,&MOD);
    a.in(n);
    b=a;
    f=a;
    for(i=0;(1<<i)<=m;++i);
    for(i=i-2;i>=0;--i)
    {
	  f+=b*f;
	  b=b*b;
	  if(((1<<i)&m)>0) {b=b*a;f+=b;} 
	}
	f.out();
	//system("pause");
	return 0; 
}
