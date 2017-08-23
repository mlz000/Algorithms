#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n); 
        int x,ans=0;
        bool flag=false;
        for(int i=1;i<=n;++i)   {scanf("%d",&x),ans^=x;if(x>1) flag=true;}
        if(!flag && n&1)  printf("Brother\n");    
        else if(flag && ans==0)  printf("Brother\n");
        else printf("John\n");
    }
    return 0;
}
