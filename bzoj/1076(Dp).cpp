#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
const int N=25;
using namespace std;
int p[N],d[N],w[N];
double f[105][1<<16]; 
int main()
{
    int i,j,k,l,n,x;
    for(i=1;i<=20;++i)  p[i]=1<<(i-1);
    scanf("%d%d",&n,&k);
    for(i=1;i<=k;++i)
    {
        scanf("%d",&w[i]);
        while(scanf("%d",&x)&&x)    d[i]+=p[x];//¶þ½øÖÆ×´Ì¬ 
    }
    for(i=n;i>=1;--i)
     for(j=0;j<p[k+1];++j)
     {
        f[i][j]=0.0;
        for(l=1;l<=k;++l)
        {
            if((d[l]&j)==d[l])   f[i][j]+=max(f[i+1][j],f[i+1][j|p[l]]+w[l]);
            else  f[i][j]+=f[i+1][j];
        }
        f[i][j]/=(double)k;
     }
    printf("%.6lf",f[1][0]);
    return 0;
}
