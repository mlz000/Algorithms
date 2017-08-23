 #include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath> 
using namespace std;
const int N=100005;
int f[N]; 
long long a[N],c[N]; 
int n; 
void sum(int x,long long y)
{
   for(;x<=n;x+=(x&(-x)))
    c[x]+=y; 
} 
long long ans(int x)
{
  long long cnt=0; 
  for(;x;x-=(x&(-x)))
    cnt+=c[x];
  return cnt;   
} 
int F(int x)
{
   if(f[x]==x) return f[x];
   return f[x]=F(f[x]); 
} 
int main()
{
    int i,j,m,k,l,r; 
    scanf("%d",&n);
    for(i=1;i<=n;++i)
     {
        scanf("%I64d",&a[i]); 
        c[i]=a[i];
     }
    for(i=1;i<=n+5;++i)
     f[i]=i; 
    for(i=1;i<=n;++i)
      if(i+(i&(-i))<=n) c[i+(i&(-i))]+=c[i];  
    scanf("%d",&m);
    long long t; 
    for(i=1;i<=m;++i)
    {
      scanf("%d%d%d",&k,&l,&r);
      if(l>r) swap(l,r); 
      if(k==1) printf("%I64d\n",ans(r)-ans(l-1));
      else
      {
         for(j=F(l);j<=r;j=F(j+1)) 
         {
                t=(long long)sqrt((double)a[j]); 
                sum(j,t-a[j]); //把a[i]加上t-a[i]，即开方，修改 
                a[j]=t;
                if(t==1) f[j]=j+1;//1开方永远为1，跳过 
         } 
      } 
    }  
    return 0;
}
