#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<map>
#include<vector>
using namespace std;
const int N=1000005;
int x[N],y[N],c[N],prex[N],prey[N],Q[N],f[N][2];
map<long long,int>mp;
vector<int>xx,yy;
int main(){
    int T,n,m,k,q;
    scanf("%d",&T);
    for(int tt=1;tt<=T;++tt){    
        printf("Case #%d:\n",tt);
        scanf("%d%d%d",&n,&m,&k);
        xx.clear(),yy.clear();
        for(int i=1;i<=k;++i){
            scanf("%d%d%d",&x[i],&y[i],&c[i]);
            xx.push_back(x[i]);
            yy.push_back(y[i]);
        }
        sort(xx.begin(),xx.end());
        sort(yy.begin(),yy.end());
        scanf("%d",&q);
        for(int i=1;i<=q;++i){
            scanf("%d",&Q[i]);
            scanf("%d%d",&f[i][0],&f[i][1]);
        }
        for(int i=1;i<=k;++i){
            x[i]=lower_bound(xx.begin(),xx.end(),x[i])-xx.begin()+1;
            y[i]=lower_bound(yy.begin(),yy.end(),y[i])-yy.begin()+1;
            mp[(x[i]-1)*100000+y[i]]=c[i];
            prex[x[i]]=x[i];
            prey[y[i]]=y[i];
        }
        for(int i=1;i<=q;++i){
            if(Q[i]==1){
                f[i][0]=lower_bound(xx.begin(),xx.end(),f[i][0])-xx.begin()+1;
                f[i][1]=lower_bound(xx.begin(),xx.end(),f[i][1])-xx.begin()+1;
            }
            else if(Q[i]==2){
                f[i][0]=lower_bound(yy.begin(),yy.end(),f[i][0])-yy.begin()+1;
                f[i][1]=lower_bound(yy.begin(),yy.end(),f[i][1])-yy.begin()+1;
            }
            else{
                f[i][0]=lower_bound(xx.begin(),xx.end(),f[i][0])-xx.begin()+1;
                f[i][1]=lower_bound(yy.begin(),yy.end(),f[i][1])-yy.begin()+1;
            }
        }
        for(int i=1;i<=q;++i){
            if(Q[i]==1){
                swap(prex[f[i][0]],prex[f[i][1]]);
            }
            else if(Q[i]==2){
                swap(prey[f[i][0]],prey[f[i][1]]);
            }
            else{
                int tx=prex[f[i][0]],ty=prey[f[i][1]];
                printf("%d\n",mp[(tx-1)*100000+ty]);
            }
        }
        for(int i=1;i<=k;++i)    mp[(x[i]-1)*100000+y[i]]=0;
    }
    return 0;
}
