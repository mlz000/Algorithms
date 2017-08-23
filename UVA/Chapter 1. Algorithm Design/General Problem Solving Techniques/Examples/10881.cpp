#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=10005;
struct data
{
    int id;
    int pos;
    int di;//×ó-1 0Åö×²ÖÐ ÓÒ1 
}a[N],b[N];
bool cmp(const data &p,const data &q)
{
   return p.pos<q.pos;
}
int num[N];
char s[][10]={"L","Turning","R"};
int main()
{
      int t;
      scanf("%d",&t);
      for(int j=1;j<=t;++j)
      {
        int i,l,time,n;
        scanf("%d%d%d",&l,&time,&n);
        for(i=1;i<=n;++i)
        {
          int x;char c;
          scanf("%d %c",&x,&c);
          a[i].id=i;
          a[i].pos=x;
          if(c=='L') a[i].di=-1;
          else a[i].di=1;
          b[i].di=a[i].di;
          b[i].pos=x+time*a[i].di; 
        }
        sort(&a[1],&a[n+1],cmp);
        for(i=1;i<=n;++i)
         num[a[i].id]=i;
        sort(&b[1],&b[n+1],cmp); 
        for(i=1;i<n;++i)
         if(b[i].pos==b[i+1].pos) b[i].di=b[i+1].di=0;
        printf("Case #%d:\n",j);
        for(i=1;i<=n;++i)
        {
          int tmp=num[i];
          if(b[tmp].pos<0 || b[tmp].pos>l) printf("Fell off\n");
          else printf("%d %s\n",b[tmp].pos,s[b[tmp].di+1]);
        }  
        printf("\n");
      }   
      return 0;
}
