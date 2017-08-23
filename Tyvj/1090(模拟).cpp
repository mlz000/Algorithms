#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath> 
#include<queue> 
using namespace std;
const int N=100005; 
int a[N],d[N]; 
bool v[N]; 
int main()
{
    int i,j,k,n,m; 
    int ans=0; 
    scanf("%d%d",&m,&n); 
    for(i=1;i<=m;++i)
     scanf("%d",&d[i]);
    sort(&d[1],&d[m+1]);
    for(i=1;i<=n;++i)
     scanf("%d",&a[i]);
    sort(&a[1],&a[n+1]);
    j=1; 
    for(i=1;i<=m;++i)
     {
       while(j<=n && (a[j]<=d[i] ||v[j])) ++j;
       if(j>n) break;
       v[j]=true; 
     } 
    if(i!=m+1) {printf("0");return 0;} 
    for(i=1;i<=n;++i)
     if(!v[i]) ans+=a[i];
    printf("%d",ans);  
    //system("pause");   
    return 0; 
} 
