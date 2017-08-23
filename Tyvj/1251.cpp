#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int f[5001];
int find(int k)
{
    if(f[k]==k) return k;
    else return f[k]=find(f[k]); 
}
int main()
{
    int a,b,fa,fb,i,j,n,m,p;
    scanf("%d%d%d",&n,&m,&p);
    for(i=1;i<=n;++i)
    f[i]=i;
    for(i=1;i<=m;++i)
    {
       scanf("%d%d",&a,&b);
       fa=find(a);
       fb=find(b);
       if(fa!=fb) f[fb]=fa;
    } 
    for(i=1;i<=p;++i)
    {
        scanf("%d%d",&a,&b);
        fa=find(a);
        fb=find(b);
        if(fa==fb) printf("Yes\n");
        else printf("No\n");
    }    
   // system("pause");
    return 0;
}
