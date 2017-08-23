#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=105;
int T,n,m,a[N][N];
long long ans;
void solve1(){
    a[0][1]=0;
    for(int i=1;i<=n;++i){
        int now=a[i-1][1]^1;
        for(int j=1;j<=m;++j){
            a[i][j]=now;
            now^=1;
        }
    }
    long long tmp=0ll;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j){
            if(a[i][j]==1){
                int now=1;
                if(i+1<=n && a[i+1][j]==0)    now*=2;
                if(j+1<=m && a[i][j+1]==0)    now*=2;
                if(i-1>=1 && a[i-1][j]==0)    now*=2;
                if(j-1>=1 && a[i][j-1]==0)    now*=2;
                tmp+=now;
            }
        }
    ans=max(ans,tmp);
    a[0][1]=1;
    for(int i=1;i<=n;++i){
        int now=a[i-1][1]^1;
        for(int j=1;j<=m;++j){
            a[i][j]=now;
            now^=1;
        }
    }
    tmp=0ll;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j){
            if(a[i][j]==1){
                int now=1;
                if(i+1<=n && a[i+1][j]==0)    now*=2;
                if(j+1<=m && a[i][j+1]==0)    now*=2;
                if(i-1>=1 && a[i-1][j]==0)    now*=2;
                if(j-1>=1 && a[i][j-1]==0)    now*=2;
                tmp+=now;
            }
        }
    ans=max(ans,tmp);
}
int main(){
    scanf("%d",&T);
    while(T--){
        ans=0ll;
        scanf("%d%d",&n,&m);
        solve1();
        printf("%I64d\n",ans);
    }
    return 0;
}
