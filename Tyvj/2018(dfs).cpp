#include<cstring> 
#include<cstdio>
#include<queue> 
#include<iostream>
#include<algorithm>
using namespace std;
const int N=20;
long long a[N]; 
bool v[N]; 
int n,w,ans,f[N]; 
bool cmp(const int a,const int b) {return a>b;} 
bool dfs(int x)//前i人必须放在前i车里 
{
   int i; 
   if(x>n) return true;
   for(i=1;i<=x && i<=ans;++i)
   {
      if(f[i]+a[x]<=w) 
      {
        f[i]+=a[x];
        if(dfs(x+1)) return true; 
        f[i]-=a[x]; 
      } 
   } 
   return false; 
} 
int main()
{ 
     int i,j; 
     scanf("%d%d",&n,&w);
     for(i=1;i<=n;++i)
      scanf("%d",&a[i]);
     sort(&a[1],&a[n+1],cmp);
     for(ans=1;ans<=n;++ans)
     {
       memset(f,0,sizeof(f)); 
       if(dfs(1)) break; 
     } 
     printf("%d\n",ans); 
    // system("pause"); 
     return 0;
}
