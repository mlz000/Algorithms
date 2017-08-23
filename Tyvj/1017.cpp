#include<cstdio>
#include<iostream>
using namespace std;
int f[1001];
int cnt;
int find(int p)
{
   if(f[p]==p) return p;
   else return f[p]=find(f[p]); 
}
int main()
{
    int a,b,fa,fb,i,j,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;++i)
    f[i]=i;
    for(i=1;i<=n;++i)
    {
        scanf("%d%d",&a,&b);
        fa=find(a);
        fb=find(b);
        if(fa==fb) cnt++;
        else f[fb]=fa;
    }
    printf("%d",cnt);
    //system("pause");
    return 0; 
    
} 
