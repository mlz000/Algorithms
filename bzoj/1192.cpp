#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<queue> 
using namespace std;
int main()
{
    int i,m;
    scanf("%d",&m);
    int num=1;
    for(i=1;;++i)
    {
        num=(num<<1);
        if(num>m)   break;
    }
    printf("%d",i);
    return 0;
}
