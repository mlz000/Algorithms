#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
double dfs(int n,double x,double y)
{
    if(n==1) return max(x,y)/min(x,y);
    double ans=1<<30;
    for(int i=1;i<=n-1;++i)
    {
        double px=x*i/n;double py=y*i/n;
        ans=min(ans,max(dfs(i,px,y),dfs(n-i,x-px,y)));//枚举分成几人和几人的蛋糕 
        ans=min(ans,max(dfs(i,x,py),dfs(n-i,x,y-py)));
    }
    return ans; 
}
int main()
{
    double x,y;
    int n;
    scanf("%lf%lf%d",&x,&y,&n); 
    printf("%.6lf",dfs(n,x,y));
    return 0;
}
