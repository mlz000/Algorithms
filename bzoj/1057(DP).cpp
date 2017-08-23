#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<climits> 
using namespace std;
const int N=2005;
int ans1,ans2,a[N][N],f[N][N],h[N],l[N],r[N]; 
int main()
{
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=m;++j)  
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]!=a[i-1][j] && a[i][j]!=a[i][j-1])
            {
                f[i][j]=min(f[i-1][j-1],min(f[i-1][j],f[i][j-1]))+1;
                ans1=max(f[i][j],ans1);
            }
            else {f[i][j]=1;ans1=max(ans1,1);}
            if(a[i][j]!=a[i-1][j])  h[j]++;
            else h[j]=1;
        }
        for(j=1;j<=m;++j)
        {
            l[j]=j;
            while(l[j]>1 && h[j]<=h[l[j]-1] && a[i][l[j]]!=a[i][l[j]-1])   l[j]=l[l[j]-1];
        }
        for(j=m;j>=1;--j)
        {
            r[j]=j;
            while(r[j]<m && h[j]<=h[r[j]+1] && a[i][r[j]]!=a[i][r[j]+1])    r[j]=r[r[j]+1];
        }
        for(j=1;j<=m;++j)   ans2=max(ans2,h[j]*(r[j]-l[j]+1));
    }
    printf("%d\n%d",ans1*ans1,ans2);
    return 0;
}
