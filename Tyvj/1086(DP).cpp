#include<cstdio> //01±³°ü 
#include<climits> 
#include<iostream>
#include<string> 
#include<cstring>
#include<algorithm>
using namespace std;
const int N=405;
struct data
{
   int h;
   int a;
   int c;
}d[N];
bool f[40000];
const int MOD=1000000000;
bool cmp(data p,data q)
{
   return p.a<q.a;
}
int main()
{ 
	 int i,j,k,n;
	 scanf("%d",&n);
	 for(i=1;i<=n;++i)
	  scanf("%d%d%d",&d[i].h,&d[i].a,&d[i].c);
	 sort(&d[1],&d[n+1],cmp);
	 f[0]=true;
	 for(i=1;i<=n;++i)
	  for(j=1;j<=d[i].c;++j)
	   for(k=d[i].a;k>=d[i].h;--k)
	    {
	      if(f[k-d[i].h]) f[k]=true;
		}
	 for(i=d[n].a;i>=0;--i)
	  if(f[i]) {printf("%d\n",i);break;}	 
	 //system("pause");
	 return 0; 
} 
