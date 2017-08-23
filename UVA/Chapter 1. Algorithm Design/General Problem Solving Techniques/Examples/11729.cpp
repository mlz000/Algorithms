#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1005;
int a[N],b[N];
struct data
{
  int b;
  int j;
};
bool cmp(const data &p,const data &q)
{
   return p.j>q.j;
}
int main()
{
      int i,j,n,m;
      int t=0;
      while(scanf("%d",&n) && n)
      {
        data a[N];
        t++;
        for(i=1;i<=n;++i)
         scanf("%d%d",&a[i].b,&a[i].j);
        sort(&a[1],&a[n+1],cmp); 
        int ans=0;
        int s=0;
        for(i=1;i<=n;++i)
        {
          s+=a[i].b;
          ans=max(ans,s+a[i].j);
        }  
        printf("Case %d: %d\n",t,ans);
      }
      //system("pause");
      return 0;
}
