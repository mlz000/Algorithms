#include<stdio.h>
#include<stdlib.h>
#define MAX(a,b) a>b?a:b
int i,j,n,m,t[1001],c[1001],max[1001][1001]; 
int main()
{
      scanf("%d%d",&m,&n);
      for(i=1;i<=n;i++)
      scanf("%d%d",&t[i],&c[i]);
      for(i=1;i<=n;i++){
        for(j=1;j<=m;j++)
      {  
        if(t[i]<=j)                 
        max[i][j]=MAX(max[i-1][j],max[i-1][j-t[i]]+c[i]);
        else max[i][j]=max[i-1][j];
      }              
                       }
        max[0][0]=max[n][1];
        for(i=1;i<=m;i++)
        if(max[n][i]>max[0][0]) max[0][0]=max[n][i];
        printf("%d\n",max[0][0]);
        return 0;
}
