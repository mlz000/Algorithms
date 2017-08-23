#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<functional>
#include<cstdlib>
#include<cmath>
using namespace std;
const int N=100005;
int n;
long long a[N],b[N];
int calc()
{
    int i=1,j=1,k=n,l=n,ans=0;
    while(i<=k)
    {
        if(a[i]>b[j])   ans+=2,++i,++j;
        else if(a[k]>b[l])  ans+=2,--k,--l;
        else 
        {
            if(a[i]==b[l])  ans++;  
            i++,l--; 
        }    
    }
    return ans;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)   scanf("%d",&a[i]);
    for(int i=1;i<=n;++i)   scanf("%d",&b[i]);
    sort(&a[1],&a[n+1]),sort(&b[1],&b[n+1]);
    printf("%d ",calc());
    swap(a,b);
    printf("%d",2*n-calc());
    return 0;
}
