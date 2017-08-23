#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int N=405,M=1005;
int n,m,tot,a[N],b[N];
bool ans[N];
bool judge()
{
    for(int k=1;k<=n;++k)
    {
        if(b[k]<0)  return false;
        if(b[k]%3)
        {
            if(k>n-2)   return false;
            int x=b[k]%3;
            b[k]-=x;b[k+1]-=x;b[k+2]-=x;
        }
    }
    return true;
}
int main()
{
    int i,j,x;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m*3+1;++i)   scanf("%d",&x),a[x]++; 
    for(i=1;i<=n;++i)
    {
        bool mark=false;
        memcpy(b,a,sizeof(a));
        b[i]++;//枚举等待牌 
        for(j=1;j<=n && !mark;++j)
        if(b[j]>=2) 
        {
            b[j]-=2;//枚举对子 
            if(judge()) ans[i]=true,mark=true,++tot;
            memcpy(b,a,sizeof(a));
            b[i]++;
        }
    }
    for(i=1;i<=n;++i)   
    {
     if(ans[i] && tot>1)  --tot,printf("%d ",i);
     else if(ans[i] && tot==1)   {printf("%d\n",i);break;}
    }
    if(!tot)   printf("NO\n");
    return 0;
}
