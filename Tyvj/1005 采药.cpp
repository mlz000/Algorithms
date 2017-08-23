#include<stdio.h>
#include<stdlib.h>
int i,j,n,m,t[1001],c[1001],max[1001]; 
int main()
{
      scanf("%d%d",&m,&n);
      for(i=1;i<=n;i++)
      scanf("%d%d",&t[i],&c[i]);
      for(i=1;i<=n;i++){
        for(j=m;j>=t[i];j--)
      {  
        if(max[j-t[i]]+c[i]>=max[j]) max[j]=max[j-t[i]]+c[i];
      }              
                       }
        printf("%d\n",max[m]);
        system("pause");
       return 0;
}
