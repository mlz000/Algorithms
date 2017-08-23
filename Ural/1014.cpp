#include<algorithm>
#include<iostream> 
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
int ans[505];
int main()
{
    int q;
    scanf("%d",&q);
    int now=500;
    if(q==1)   printf("1");
    else if(q==0)   printf("10");
    else
    { 
      while(q!=1)
      {
        bool flag=false;
        for(int i=9;i>=2;--i)
        {
           if(q%i==0) {q/=i;ans[now--]=i;flag=true;break;}
        }
        if(!flag && q>=10) {printf("-1");return 0;}
      }
    }
    for(int i=now+1;i<=500;++i) printf("%d",ans[i]);
    return 0;
} 
