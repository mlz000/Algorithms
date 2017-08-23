#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<climits> 
using namespace std;
int prim[11]={0,2,3,5,7,11,13,17,19,23,29};
long long n,ans,MAX;
void dfs(int now,int t,long long all,int add)
{
    if(all>n)   return;
    if(add==MAX) ans=min(ans,all);
    if(add>MAX) MAX=add,ans=all;
    for(int i=1;i<=t;++i)   dfs(now+1,i,all*(long long)pow(1.0*prim[now],1.0*i),add*(i+1)); 
}
int main()
{
    scanf("%lld",&n);
    dfs(1,10,1,1);
    printf("%lld",ans);
    return 0;
}
