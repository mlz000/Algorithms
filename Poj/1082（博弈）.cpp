#include<cstdio>//ÆæÅ¼ĞÔÌÖÂÛ£¬²»´í 
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=50005,K=100005;
int n,k,ans;
int f[N*3];
int main()
{
   int i,t;
   int x,y,z;
   scanf("%d",&t);
   for(i=1;i<=t;++i)
   {
     scanf("%d%d%d",&x,&y,&z);
     if((y+z)%2==0) printf("YES\n");
     else if((y==9 && z==30) ||(y==10 && z==31)) printf("YES\n");
     else printf("NO\n");
   } 
   return 0;
} 
