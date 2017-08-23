#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=35;
int root[N][N];
int  sum[N][N];
int dp(int l,int r)
{
  if(l>r) return 1;
  if(sum[l][r]!=-1) return sum[l][r];
   int i;
   for(i=l;i<=r;++i)
    {
     int now=dp(l,i-1)*dp(i+1,r)+sum[i][i];
     if(now>sum[l][r])
     {
      sum[l][r]=now;
      root[l][r]=i;
     }
    }
    return sum[l][r];
}
void print(int l,int r)
{
    if(l>r) return ;
    printf("%d ",root[l][r]);
    print(l,root[l][r]-1);
    print(root[l][r]+1,r);
}
int main()
{
     int i,j,n;
     scanf("%d",&n);
     memset(sum,-1,sizeof(sum));
     memset(root,-1,sizeof(root));
     for(i=1;i<=n;++i)
      {
        scanf("%d",&sum[i][i]);
        root[i][i]=i;
      } 
     printf("%d\n",dp(1,n)); 
     print(1,n); 
    //  system("pause");
      return 0;
}
