#include<stdio.h>
#include<stdlib.h>
bool f[20001];
int w[31];
int main()
{
     int v,n,i,j;
     scanf("%d",&v);
     scanf("%d",&n);
     for(i=1;i<=n;i++)
    {
      scanf("%d",&w[i]);
    }
    f[0]=true;
     for(i=1;i<=n;i++)
      for(j=v;j>=w[i];j--)
      {
         if(f[j-w[i]]) f[j]=true; 
      }
    for(i=v;i>=0;i--)
    if(f[i]) {printf("%d",v-i);break;}
    //system("pause");
    return 0;
}
