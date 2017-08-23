#include<iostream>
#include<stack> 
#include<cstdio> 
#include<cstring> 
#include<climits> 
#include<algorithm>
using namespace std; 
const int N=105;
int d[N][N]; 
int main()
{
     int n,m,i,j,k;
     int x,y; 
     scanf("%d%d",&n,&m);
     memset(d,0x3f,sizeof(d)); 
     for(i=1;i<=m;++i)
     {
       scanf("%d%d",&x,&y);
       d[x][y]=1;
       d[y][x]=1; 
     }
     for(i=1;i<=n;++i)
      d[i][i]=0;
     for(i=1;i<=n;++i)
      for(j=1;j<=n;++j)
       for(k=1;k<=n;++k)
        if(i!=j && j!=k && k!=i) 
         if(d[j][i]+d[i][k]<d[j][k]) d[j][k]=d[j][i]+d[i][k];
     int ans=0; 
     for(i=1;i<=n;++i)
      for(j=1;j<=n;++j)
       if(d[i][j]!=0x3f3f3f3f) 
       ans=max(ans,d[i][j]);
     cout<<ans;       
     //system("pause"); 
     return 0;
}

