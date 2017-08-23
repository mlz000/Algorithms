#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
int a[120],p[120],sum[120],ans[120];
using namespace std;
int main()
{
    int i,j;
    int t;
    int c;
    scanf("%d",&t);
      while(t--)
     {
              scanf("%d",&c);
      for(i=1;i<=c;++i)
      {
          scanf("%d%d",&a[i],&p[i]);
          sum[i]=a[i]+sum[i-1];
      }      
      for(i=1;i<=c;++i)//1µ½iÂòµÄÕäÖéÊý 
      {
          ans[i]=(sum[i]+10)*p[i];
          for(j=1;j<i;++j)
           ans[i]=min(ans[i],(sum[i]-sum[j]+10)*p[i]+ans[j]);
      }
       printf("%d\n",ans[c]);
       memset(ans,0,sizeof(0));
       memset(sum,0,sizeof(sum));
     }
     //system("pause");
     return 0;
}
