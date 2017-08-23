#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int N=1005;
struct data
{
   double l;
   double r;
}a[N];
bool cmp(const data &p,const data &q)
{
    return p.l<q.l;
}
int main()
{
      
      int i,j,n,l;
      double w;
      int T=0;
      while(scanf("%d%d%lf",&n,&l,&w)!=EOF)
      {
         int tot=0;
         bool flag=false;
         for(i=1;i<=n;++i)
         {
            double p,r;
            scanf("%lf%lf",&p,&r);
            if(r*2>=w) 
            {
                  double tmp=sqrt((r*r-w*w/4));
                  a[++tot].l=p-tmp;
                  a[tot].r=p+tmp;
            }
         }
         sort(&a[1],&a[tot+1],cmp);
         T++;
         printf("Case #%d: ",T);
         if(a[1].l>0) {printf("-1\n");continue;}
         int ans=0;
         double left=0.0,right=0.0;
         i=1;
         while(i<=tot)
         {
           j=i;
           while(j<=tot && a[j].l<=left) 
           {
               if(a[j].r>right)    right=a[j].r;
               j++;
           }
           if(j==i) break;
           left=right;
           i=j;
           ans++;
           if(left>=l) {flag=true;break;}
         } 
         if(flag) printf("%d\n",ans);
         else printf("-1\n");
      }
      system("pause");
      return 0;
}
