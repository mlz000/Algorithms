#include<stdio.h>
int a[14];
int main()
{ 
    int k,i,j,line=0;
    int n1,n2,n3,n4,n5,n6;
    while(scanf("%d",&k)&&k)
    {
          if(line) printf("\n");
          for(i=1;i<=k;i++)
           scanf("%d",&a[i]);
        for(n1=1;n1<=k-5;n1++)
         for(n2=n1+1;n2<=k-4;n2++)
          for(n3=n2+1;n3<=k-3;n3++)
           for(n4=n3+1;n4<=k-2;n4++)
            for(n5=n4+1;n5<=k-1;n5++)
             for(n6=n5+1;n6<=k;n6++)
              printf("%d %d %d %d %d %d\n",a[n1],a[n2],a[n3],a[n4],a[n5],a[n6]);
              line=1;
    }                     
}
