#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int i,n,T;
    scanf("%d",&T);
    while(T--)
    {
        int ans=0;int cnt=0;
        scanf("%d",&n);
        for(i=1;i<=n;++i)   
        {
            int x;
            scanf("%d",&x);
            ans^=x;
            if(x==1) cnt++;
        }
        if(cnt==n) 
        {
            if(n%2==0)   printf("John\n");
            else printf("Brother\n");
        }
        else if(ans!=0) printf("John\n");
        else printf("Brother\n");
    }
    return 0;
}
