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
    if(n>0) printf("%d\n",(n+1)*n/2);
    else 
    {
         int tot=2-n;
         printf("%d\n",(n+1)*tot/2);
    }
    return 0;
} 
