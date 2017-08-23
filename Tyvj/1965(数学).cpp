#include<cstdio>  //只需要考虑1~N中哪些数的因数有奇数个就可以了，当且仅当x=P div x时，也就是P=x^2时，P有奇数个因数 
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath> 
using namespace std;
int main()
{
    int i,n,t; 
      scanf("%d",&t);
    for(i=1;i<=t;++i)
    {
        scanf("%d",&n);
        int x=sqrt(n);
        printf("%d\n",x);   
    }  
    return 0;
}
