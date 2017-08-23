#include<cstdio>//递推 
#include<algorithm>
#include<iostream>
using namespace std;
const int N=100;
int a[N],b[N];
long long f(int c[],int x,int num)
{
     if(x==0) return 0;
     if(c[x]==num) return f(c,x-1,num);
     return f(c,x-1,6-c[x]-num)+(1ll<<(x-1));
     //第X个盘子不在num柱子上，把前x-1个盘子移到中转柱子上，再把第x个盘子移到
     //num柱子上,最后把x-1个盘子整体移到num上 
}
int main()
{
      int i,j,n,T=0;
      while(scanf("%d",&n)&&n)
      {
         T++;
         long long ans=0;
         for(i=1;i<=n;++i)
          scanf("%d",&a[i]);
         for(i=1;i<=n;++i)
          scanf("%d",&b[i]);
         int j=n;
         while(j>=1 && a[j]==b[j]) j--;
         if(j>=1)
         {
           ans=f(a,j-1,6-a[j]-b[j])+f(b,j-1,6-a[j]-b[j])+1;
         }//f(a,x,pos)当前位置是a[],把前x个盘子移动到第pos的柱子上 
         printf("Case %d: %lld\n",T,ans);
      }
      //system("pause");
      return 0;
}
