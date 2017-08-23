#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int N=10005;
int a[N],ans[N]; 
int main()
{
    int i,n;
    bool ok=false;
    int res=0;
    scanf("%d",&n);
    for(i=1;i<=n;++i)   scanf("%d",&a[i]);
    for(ans[1]=0;ans[1]<=1;++ans[1])
    {
        ans[2]=a[1]-ans[1];
        ok=false;
        for(i=3;i<=n;++i)
        {
            ans[i]=a[i-1]-ans[i-1]-ans[i-2];
            if(ans[i]<0)   {ok=true;break;} 
        }
        if(ans[n]==a[n]-ans[n-1] && !ok)   res++; 
    }
    printf("%d",res);
    return 0;
}
