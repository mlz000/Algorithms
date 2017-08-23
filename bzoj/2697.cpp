#include<cstdio>
#include<iostream>
#include<algorithm> 
using namespace std;
const int K=305;
int c[K];
bool cmp(const int a,const int b)
{
    return a>b;
}
int main()
{
     int i,j,n,k,num;
     int ans=0;
     scanf("%d%d",&n,&k);
     for(i=1;i<=k;++i)
      scanf("%d",&c[i]);
      sort(&c[1],&c[k+1],cmp);
      num=n;
      if(n>=k*2) 
      {
            for(i=1;i<k;++i) {ans+=c[i]*(num-1);num=num-2;}
            ans+=c[k]*(num-1);
      }
      else {
            i=1;
            while(num-1>0)
            {
                ans+=c[i]*(num-1);
                num=num-2;
                i++;
                }
           }
      printf("%d\n",ans);
     // system("pause");
      return 0;
}
