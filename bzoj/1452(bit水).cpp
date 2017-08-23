#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
const int N=305;
int n,m,a[N][N],c[105][N][N];
void add(int x,int y,int k,int num)
{
    int i,j;
    for(i=x;i<=n;i+=i&-i)
     for(j=y;j<=m;j+=j&-j)
      c[k][i][j]+=num;
}
int ask(int x,int y,int k)
{
    int tmp=0;
    int i,j;
    for(i=x;i;i-=i&-i)
     for(j=y;j;j-=j&-j)
       tmp+=c[k][i][j];
    return tmp;    
}
int main()
{
    scanf("%d%d",&n,&m);
    int i,j;
    for(i=1;i<=n;++i)
     for(j=1;j<=m;++j)
     {
        scanf("%d",&a[i][j]);
        add(i,j,a[i][j],1);
     }
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int x;
        scanf("%d",&x);
        if(x==1)
        {
            int xx,yy,c; 
            scanf("%d%d%d",&xx,&yy,&c);
            if(c==a[xx][yy]) continue;
            add(xx,yy,a[xx][yy],-1);
            add(xx,yy,c,1);
            a[xx][yy]=c;
        }
        else if(x==2)
        {
            int x1,y1,x2,y2,c;
            scanf("%d%d%d%d%d",&x1,&x2,&y1,&y2,&c);
            printf("%d\n",ask(x2,y2,c)-ask(x1-1,y2,c)-ask(x2,y1-1,c)+ask(x1-1,y1-1,c));
        }
    } 
    return 0; 
} 
