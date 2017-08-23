#include<cstdio>//ÁÚÎ»½»»»·¨ 
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int N=80000;
struct data
{
    int id;
    double l;
    double f;
}a[N];
bool cmp(const data p,const data q)
{
   return q.f*p.l<p.f*q.l;
}
int main()
{
      int i,n,m;
     while(scanf("%d",&n)==1)
     {
      for(i=1;i<=n;++i) scanf("%d%lf%lf",&a[i].id,&a[i].l,&a[i].f);
      scanf("%d",&m);
      sort(&a[1],&a[n+1],cmp); 
      printf("%d\n",a[m].id);
     }
      //system("pause");
      return 0;
} 
