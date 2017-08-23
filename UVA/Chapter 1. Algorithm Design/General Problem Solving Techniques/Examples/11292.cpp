#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=20005;
int a[N],b[N];
int main()
{
      int i,j,n,m;
      while(scanf("%d%d",&n,&m)==2 &&n && m)
      {
            memset(a,0,sizeof(a));
            memset(b,0,sizeof(b));
            for(i=1;i<=n;++i)
             scanf("%d",&a[i]);
            for(i=1;i<=m;++i)
             scanf("%d",&b[i]);
            int ans=0;
            sort(&a[1],&a[n+1]);
            sort(&b[1],&b[m+1]);
            int now=1;
            for(i=1;i<=m;++i)
            {
              if(b[i]>=a[now]) 
              {
                        ans+=b[i];
                        if(++now>n) break;
              }
            }
            if(now<=n) printf("Loowater is doomed!\n");
            else printf("%d\n",ans);
      }
      //ssystem("pause");
      return 0;
}
