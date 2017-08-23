#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=205,M=21;
int d[N],p[N],ans[M];
int f[M][M*40],path[M][M*40];
int main()
{
    int i,j,k,n,m,t1,t2;
    int tcase=1;
    while(scanf("%d%d",&n,&m)&&n&&m)
    {
        memset(f,-1,sizeof(f));
        memset(path,0,sizeof(path));
        int temp=m*20;
        f[0][temp]=0;//差可能为负，先加一个值
        for(i=1;i<=n;++i)
         scanf("%d%d",&p[i],&d[i]);
         for(j=0;j<m;++j)
         {
             for(k=0;k<=temp*2;++k)
             {
                if(f[j][k]>=0)
                 for(i=1;i<=n;++i)
                 {
                   if(f[j][k]+p[i]+d[i]>f[j+1][k+p[i]-d[i]])
                   {
                         t1=j;
                         t2=k;
                       while(t1>0 && path[t1][t2]!=i)
                       {
                           t2-=p[path[t1][t2]]-d[path[t1][t2]];
                           t1--;
                       }
                       if(t1==0)            //第i个人未出现过
                       {
                           f[j+1][k+p[i]-d[i]]=f[j][k]+p[i]+d[i];
                           path[j+1][k+p[i]-d[i]]=i;
                       }
                   }
                 }
             }
         }
         i=temp;
         int k=0;
         while(f[m][i+k]<0 && f[m][i-k]<0)//找差的最小值
         k++;
         if(f[m][i+k]>f[m][i-k])
         j=i+k;
         else j=i-k;
         printf("Jury #%d\n",tcase);
         tcase++;
         printf("Best jury has value %d for prosecution and value %d for defence:\n",(f[m][j]+j-temp)/2,(f[m][j]-j+temp)/2);
         for(i=1;i<=m;++i)
         {
             ans[i]=path[m-i+1][j];
             j-=p[ans[i]]-d[ans[i]];
         }
         sort(&ans[1],&ans[m+1]);
         for(i=1;i<=m;++i)
         printf("%d ",ans[i]);
         printf("\n");
    }
    return 0;
}
