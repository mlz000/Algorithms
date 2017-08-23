#include<cstdio> 
#include<iostream>
#include<algorithm> 
using namespace std; 
const int N=100005;
int a[N],b[N];
int n; 
double ansand,ansor;
void solve(int w)
{
   int i; 
   int last[2]={0,0};
   for(i=1;i<=n;++i)
    b[i]=((a[i]>>w)&1);
   for(i=1;i<=n;++i) 
   {
     if(i!=1)
     {
       if(b[i]==0)
       {
         ansor+=(double)(1<<w)/n/n*last[1]; 
       }
       else 
       {
         ansand+=(double)(1<<w)/n/n*(i-last[0]-1);
         ansor+=(double)(1<<w)/n/n*(i-1); 
       } 
     }
     last[b[i]]=i; 
   }
   for(i=1;i<=n;++i)
   if(b[i])
   {
     ansand+=(double)(1<<w)/n/n/2;
     ansor+=(double)(1<<w)/n/n/2; 
   } 
} 
int main()
{
      int i; 
      scanf("%d",&n);
      for(i=1;i<=n;++i)
       scanf("%d",&a[i]);
      for(i=0;i<31;++i)
       solve(i);
      printf("%.3lf %.3lf\n",ansand*2,ansor*2); 
     // system("pause");  
      return 0; 
} 

