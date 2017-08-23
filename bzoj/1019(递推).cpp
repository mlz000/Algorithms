#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
char s[10][5];
int g[35][5];
long long f[35][5];
int main()
{
    int i,j,n;
    scanf("%d\n",&n);
    for(i=1;i<=6;++i)
     for(j=0;j<3;++j)
     scanf("%c",&s[i][j]);
    for(i=1;i<=3;++i)
     for(j=1;j<=6;++j)
     if(s[j][0]-'A'+1==i)
     {
        f[i][1]=1;
        g[i][1]=s[j][1]-'A'+1;
        break;
     } 
    int x,y,z; 
    for(i=2;i<=n;++i)
     for(x=1;x<=3;++x)
     {
        y=g[x][i-1];
        z=6-x-y;
        f[x][i]=f[x][i-1]+1;
        if(g[y][i-1]==z)
        {
            f[x][i]+=f[y][i-1];
            g[x][i]=z;                     
        }
        else 
        {
            f[x][i]+=f[x][i-1]+1+f[y][i-1];
            g[x][i]=y;
        }
     } 
    printf("%lld\n",f[1][n]); 
    return 0;
}
