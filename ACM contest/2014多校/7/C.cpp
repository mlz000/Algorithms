#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    for(int tt=1;tt<=T;++tt){
        printf("Case #%d: ",tt);
        long long n;
        scanf("%I64d",&n);
        int k=sqrt((double)n/3);
        int ans=0;
        for(int i=4;i<=k;++i){
            bool flag=false;
            long long tmp=n;
            int last=tmp%i;
            if(last>6 || last<3)    continue;
            tmp/=i;
            while(tmp){
                last=tmp%i;
                if(last>6 || last<3)    {flag=true;break;}
                tmp/=i;
            }
            if(!flag)    ans++;    
        }
        for(int i=3;i<=6;++i)
            for(int j=3;j<=6;++j){
                int t=max(max(i,j),k);
                if(((n-j)%i)==0 && ((n-j)/i)>t)    ans++;
            }
        if(n==3 || n==4 || n==5 || n==6){
            puts("-1");
            continue;
        }
        printf("%d\n",ans);
    }
    return 0;
}
