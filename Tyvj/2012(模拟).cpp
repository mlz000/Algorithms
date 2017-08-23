#include<cstdio>
#include<queue>
#include<iostream>
#include<cstring>
#include<bitset>
using namespace std;
const int N=705;
int a[N][N],ha[N],li[N];
char s[N];
int main()
{
     int i,j,n,k;
     scanf("%d%d",&n,&k);
     for(i=1;i<=n;++i)
      for(j=1;j<=n;++j)
       scanf("%d",&a[i][j]);
     for(i=1;i<=n;++i)
      {
        ha[i]=i;
        li[i]=i;
      }
     int x,y,t;
     for(i=1;i<=k;++i)
     {
       scanf("%s%d%d",s,&x,&y);
       if(s[0]=='R')
       {
         t=ha[x];
         ha[x]=ha[y];
         ha[y]=t;  
       }
       if(s[0]=='C')
       {
         t=li[x];
         li[x]=li[y];
         li[y]=t;
       }
       if(s[0]=='A') printf("%d\n",a[ha[x]][li[y]]);
     }  
    // system("pause");
     return 0;
}
