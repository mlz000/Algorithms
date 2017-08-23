#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int MOD=12345678,N=155,K=25;
int f[N][N][K][K];
void add(int &x,int y)
{
    x+=y;
    if(x>MOD)  x-=MOD;  
}
int main()
{
    int n,m,k,i,j,p,q;
    f[0][0][0][0]=1;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<=n;++i)
     for(j=0;j<=m;++j) 
      for(p=0;p<=k;++p)
       for(q=0;q<=k;++q)
        if(f[i][j][p][q])
        {
            if(i<n && p<k)  add(f[i+1][j][p+1][max(q-1,0)],f[i][j][p][q]);
            if(j<m && q<k)  add(f[i][j+1][max(p-1,0)][q+1],f[i][j][p][q]);
        }
    int ans=0;
    for(i=0;i<=k;++i)
     for(j=0;j<=k;++j)
     add(ans,f[n][m][i][j]);
     printf("%d",ans);    
    return 0;
}
