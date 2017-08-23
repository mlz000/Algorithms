#include<iostream>
#include<stdio.h>
using namespace std;
int f[10];
int main()
{
   int i,n,k;
   long long ans=1;
   long long t;
   scanf("%d%d",&n,&k);
   for(i=1;i<=n;i++)
   {
        ans=ans*i;
        if(ans%10==0) ans=ans/10;
   }
   t=ans;
   for(i=k;i>=1;--i)
   {
     f[i]=ans%10;
     ans=ans/10;
   }
   ans=1;
   for(i=1;i<=k;i++)
   ans=10*ans;
   if(ans>t) printf("%I64d",t);
  else {
         for(i=1;i<=k;i++)
         printf("%d",f[i]);
       }
   system("pause");
   return 0;
}
