#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
int a[10001];
int main()
{
   int i,j,n,k,ans;
   bool f=true;
   scanf("%d%d",&n,&k);
   for(i=1;i<=n;i++)
   scanf("%d",&a[i]);
   sort(a,a+n+1);
   ans=a[n+1-k]-a[k];
   if(ans>=2)
   {
      for(i=2;i<=sqrt(ans);i++)
     {
     if(ans!=i&&ans%i==0) f=false;                        
     }
   if(f) printf("YES\n%d",ans);
   else printf("NO\n%d",ans);
   }
   else printf("NO\n%d",ans);
   //system("pause");
   return 0;
} 
