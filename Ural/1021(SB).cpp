#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
const int N=50005;
bool v[N*4];
int main()
{
    int n,m,i;
    scanf("%d",&n);
    int tmp,u=100000;
    for(i=0;i<n;i++)
    {
        scanf("%d",&tmp);
        v[tmp+u]=1;
    }
    scanf("%d",&m);
    int t=0;
    for(i=0;i<m;i++)
    {
        scanf("%d",&tmp);
        if(v[u+10000-tmp])
        {
            t=1;
            break;
        }
    }
    if(t)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}

