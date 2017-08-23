#include<cstdio>
#include<iostream>
#include<algorithm>
#include<climits>
#include<cstring>
using namespace std;
const int N=50005;
int n,d[N],a[N],st[20][N],Log[N];
void build()
{
    int logn=Log[n];
    for(int i=0;i<=n;++i)   st[0][i]=a[i];
    for(int i=1;i<=logn;++i)
     for(int j=1;j<=n-(1<<i)+1;++j)
      st[i][j]=max(st[i-1][j],st[i-1][j+(1<<(i-1))]);
}
int find(int x)
{
    return lower_bound(d+1,d+n+1,x)-d;;
} 
inline int query(int l,int r)
{
    if(l>r) return INT_MIN;
    int len=Log[r-l+1];
    return max(st[len][l],st[len][r-(1<<len)+1]);
} 
int main()
{
    int i,j,k;
    for(i=1,j=1,k=-1;i<=N-5;++i)
    {
        if(i==j)   Log[i]=++k,j<<=1;
        else Log[i]=k;
    }
    scanf("%d",&n);
    for(i=1;i<=n;++i)   scanf("%d%d",&d[i],&a[i]);
    build();
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int x,y,ans;
        scanf("%d%d",&x,&y);
        int l=find(x),r=find(y);
        bool lx=(l<=n && d[l]==x),rx=(r<=n && d[r]==y);
        if(!rx) --r;
        if(lx)
        {
           if(rx)
           {
                int m=query(l+1,r-1);
                if(a[l]<a[r])   ans=0;
                else if(m<a[r])   
                {
                    if(r-l==y-x)    ans=1;
                    else ans=-1;
                }    
                else ans=0;
           }  
           else 
           {
                int m=query(l+1,r);
                if(m<a[l])  ans=-1;
                else ans=0;
           }     
        }
        else if(rx)
             {
                int m=query(l,r-1);
                if(m>=a[r]) ans=0;
                else ans=-1;
             }
        else ans=-1;
        if(ans==1)  printf("true\n");
        else if(!ans)   printf("false\n");
        else printf("maybe\n");
    }
    return 0;
} 
