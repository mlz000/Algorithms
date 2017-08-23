#include<cstdio> 
#include<stack>
#include<algorithm>
#include<iostream>
using namespace std;
const int N=100005,M=1000005;
int a[N],cnt[M],ans[M];
bool v[M],vis[M];
int main()
{
    int i,n;
    scanf("%d",&n);
    int MAX=0;
    for(i=1;i<=n;++i)   
    {
        scanf("%d",&a[i]);
        MAX=max(MAX,a[i]);
        v[a[i]]=true;
        ++cnt[a[i]];
    }
    for(i=1;i<=n;++i)
    {
        if(!vis[a[i]])
        {
            if(cnt[a[i]]!=1)    ans[a[i]]+=cnt[a[i]]-1;
            int tmp=a[i]*2;
            while(tmp<=MAX)
            {
                if(v[tmp])  ans[tmp]+=cnt[a[i]];
                tmp+=a[i];
            }
            vis[a[i]]=true;
        }
    }
    for(i=1;i<=n;++i)   printf("%d\n",ans[a[i]]); 
    return 0;
}
