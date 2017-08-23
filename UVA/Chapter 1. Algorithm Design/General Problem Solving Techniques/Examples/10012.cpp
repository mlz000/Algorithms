#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<climits>
#include<cmath>
#define ll long long
#define D double
using namespace std;
const int N=10;
int n;
int a[N];
double r[N],d[N];
D check(int b[])
{
    memset(d,0,sizeof(d));
    d[b[1]]=r[b[1]];
    for(int j=2;j<=n;++j) 
    d[b[j]]=d[b[j-1]]+(D)sqrt((r[b[j]]+r[b[j-1]])*(r[b[j]]+r[b[j-1]])-(r[b[j]]-r[b[j-1]])*(r[b[j]]-r[b[j-1]])); 
     for(int j=1;j<=n;++j)
    {
      for(int k=1;k<j;++k)
      {
      if((d[b[j]]-d[b[k]])*(d[b[j]]-d[b[k]])+(r[b[j]]-r[b[k]])*(r[b[j]]-r[b[k]])<(r[b[j]]+r[b[k]])*(r[b[j]]+r[b[k]]))
      return (D)INT_MAX;
      }
    }
    return d[b[n]]+r[b[n]];
}
int main()
{
      int i,t;
      scanf("%d",&t);
      while(t--)
      {
         scanf("%d",&n);
         for(i=1;i<=n;++i) a[i]=i;
         for(i=1;i<=n;++i) scanf("%lf",&r[i]);
         D MIN=check(a);
         while(next_permutation(&a[1],&a[n]))
         {
            D tmp=check(a);
            if(tmp<MIN) MIN=tmp;
         }
         printf("%.3lf\n",MIN);
      }
      system("pause");
      return 0;
}
