#include<stdio.h>
#include<stdlib.h>
int main()
{
      int i,j,n,m,x,y,t[1001],c[1001],max[1001]={0}; 
      scanf("%d%d",&m,&n);
      for(i=1;i<=n;i++){
        scanf("%d%d",&x,&y);
        for(j=m;j>=x;j--)
      {  
        if(max[j-x]+y>=max[j]) max[j]=max[j-x]+y;
      }              
                       }
        printf("%d\n",max[m]);
       return 0;
}
