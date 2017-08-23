#include<cstdio> 
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int N=1005;
int a[N],fl[N][N],fr[N][N];
int main()
{
    int i,j,k,n,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(fl,0,sizeof(fl));memset(fr,0,sizeof(fr));
        for(i=1;i<=n;++i)   
        {
            scanf("%d",&a[i]);
            fl[i][i]=fr[i][i]=a[i];
        }
        int p,q,x;
        for(k=1;k<n;++k)
         for(i=1;i<=n-k;++i)
         {
            j=i+k;
            p=fl[i][j-1],q=fr[i][j-1],x=a[j];
            if(x==q)    fl[i][j]=0;
            else if((x<q && x<p) || (x>q && x>p))   fl[i][j]=x;
            else if(p<q) fl[i][j]=x+1;
            else fl[i][j]=x-1;
            p=fr[i+1][j],q=fl[i+1][j],x=a[i];
            if(x==q)    fr[i][j]=0;
            else if((x<q && x<p) || (x>q && x>p))   fr[i][j]=x;
            else if(p<q) fr[i][j]=x+1;
            else fr[i][j]=x-1; 
         }    
         if(n==1)    printf("1\n");
         else printf("%d\n", (fr[1][n - 1] != a[n]));
    } 
    return 0;
}
