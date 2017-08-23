#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=55;
char s[N];
int f[N][N][2];
bool check(int l,int r,int len)
{
    len=len/2;
    for(int i=0;i<len;++i)
    if(s[l+i]!=s[l+len+i])  return false;
    return true;
}
int dp(int l,int r,int t)//[l,r] t表示能否放M 
{
    if(f[l][r][t])  return f[l][r][t];
    int &x=f[l][r][t],len=r-l+1;
    x=len;
    if(x==1)    return x;
    if(t)   for(int i=l;i<r;++i)  x=min(x,dp(l,i,1)+1+dp(i+1,r,1));
    for(int i=l;i<r;++i)   x=min(x,dp(l,i,t)+r-i);
    if(len%2==0 && check(l,r,len)) x=min(x,dp(l,l+len/2-1,0)+1);
    return x;
}
int main()
{
    scanf("%s",s+1);
    int l=strlen(s+1);
    printf("%d",dp(1,l,1));
    return 0;
}
