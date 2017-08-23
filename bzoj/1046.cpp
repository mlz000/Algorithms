#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int N=10005;
int a[N],d[N],f[N],ans[N];
int main()
{
    int n,m,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;++i)   scanf("%d",&a[i]);
    int ans=0;
    for(i=n;i>=1;--i)
    {
         int l=1,r=ans;
         while(l<=r)
         {
            int mid=(l+r)>>1;
            if(f[mid]>a[i]) l=mid+1;
            else r=mid-1; 
         }
         f[l]=a[i];
         d[i]=l;
         ans=max(ans,l);
    }   
    scanf("%d",&m);
    while(m--)
    {
        int L;
        scanf("%d",&L);
        if(L>ans)   {printf("Impossible\n");continue;}
        int last=-1;
        for (int i=1;i<=n;i++) 
          if(d[i]>=L && a[i]>last) 
          {
              printf("%d",a[i]);
              if(L==1)  {printf("\n");break;}
              else printf(" "), L--, last=a[i];
          }  
    }
    return 0;
}
