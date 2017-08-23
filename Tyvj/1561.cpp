#include<stdio.h>
#include<stdlib.h>
#include<iostream>
const int four[18]={0,1,16,81,256,625,1296,2401,4096,6561,10000,14641,20736,28561,38416,50625,65536,83521};
int f[100001];
int min(int a,int b)
{
    return a<b?a:b;
}
int main()
{   
    int m,t,i,j;
 scanf("%d",&m);
 for(t=1;t<=17;f[four[t]]=1,t++)
 if(four[t]>m){t--;break;}
 for(int i=1;i<=t;i++)
 for(int j=four[i]+1;j<=m;j++)
 {
 if(f[j]) f[j]=min(f[j],f[j-four[i]]+1);
 else f[j]=f[j-four[i]]+1;
        }
 printf("%d",f[m]);
 return 0;
}
