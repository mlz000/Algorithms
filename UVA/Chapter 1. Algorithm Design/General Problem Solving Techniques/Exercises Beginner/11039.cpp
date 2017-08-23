#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=500005;
int a[N],b[N];
int tot1,tot2;
int work(int p)
{
    int ans=1;
    int i,j;
    i=j=1;
    while(i<=tot1 && j<=tot2)
    {
      if(p)
      {
         while(a[i]>b[j] && j<=tot2) j++;
         if(j<=tot2) ans++;
         p=0;
      }
      else 
      {
         while(a[i]<b[j] && i<=tot1) i++;
         if(i<=tot1) ans++;
         p=1;
      }
    }
    return ans;
}
int main()
{
      int t;
      int i,j,n;
      scanf("%d",&t);
      for(i=1;i<=t;++i)
      {
        int num=0;
        tot1=0;tot2=0;
        scanf("%d",&n);
        for(j=1;j<=n;++j)
        {
          int x;
          scanf("%d",&x);
          if(x>0) a[++tot1]=x;
          else if(x<0) b[++tot2]=-x;
        } 
        if(!tot1 || !tot2) printf("1\n");
        else 
        {
           sort(&a[1],&a[tot1+1]);
           sort(&b[1],&b[tot2+1]);
        int MAX=max(work(1),work(0));
        printf("%d\n",MAX);
        }
      }
      return 0;
}
