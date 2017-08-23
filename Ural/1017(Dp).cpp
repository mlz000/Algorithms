#include<algorithm>
#include<iostream> 
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
long long f[505];
int main()
{
    int n;
    scanf("%d",&n);
    f[0]=1;
    for(int i=1;i<=n;++i)
     for(int j=n;j>=i;--j)
     f[j]+=f[j-i];
    printf("%I64d",f[n]-1); 
    return 0;
} 
