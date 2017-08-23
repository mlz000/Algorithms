#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
const int N=50005;
struct data
{
   int  sd;
   int num;
}a[N];
int b[N];
bool ok[N];
bool cmp(const data p,const data q)
{
  if(p.num==q.num) return p.sd<q.sd;
  else return p.num<q.num;
}
int main()
{
     int i,n,t;
     scanf("%d",&t);
     while(t--)
     {
		memset(a,-1,sizeof(a));
		memset(b,-1,sizeof(b));
		memset(ok,false,sizeof(ok));
	    scanf("%d",&n);
	    for(i=1;i<=n;++i)
	      {
			  scanf("%d",&a[i].num );  
	          a[i].sd=i;
	          b[i]=a[i].num;
		  }
	    sort(&a[1],&a[n+1],cmp);
	     for(i=1;i<=n;++i)
	     {
		    if(a[i].num!=a[i-1].num) ok[a[i].sd]=true;
		 }
		 for(i=1;i<=n;++i)
		   if(ok[i]) printf("%d ",b[i]);
		   printf("\n"); 
	 }
	 return 0;
} 
