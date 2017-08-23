#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int y,m,d,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&y,&m,&d);
        if((m+d)%2==0 || (m==9 && d==30) || (m==11 && d==30))   printf("YES\n");
        else printf("NO\n");       
    }
    return 0;
}
