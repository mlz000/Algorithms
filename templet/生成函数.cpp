#include<cstdio>//五边形数定理
#include<iostream>
#include<algorithm>
#include<cstring>
const int N=100005,M=1000000007;
long long Q[N],p[N];
inline long long get(long long x){
    return (3*x*x-x)/2%M;
}
void init(){
    Q[0]=0;
    for(int i=1;i<N;++i){
        if(i&1)    Q[i]=get(i/2+1);
        else Q[i]=get(-i/2);
    }
    p[0]=p[1]=1;
    for(int i=2;i<N;++i)
        for(int j=1;j;++j){
            if(Q[j]>i)    break;
            if(j&1){
                if(((j+1)/2)&1)    p[i]+=p[i-Q[j]];
                else p[i]-=p[i-Q[j]];
            }
            else{
                if((j/2)&1)    p[i]+=p[i-Q[j]];
                else p[i]-=p[i-Q[j]];
            }
            p[i]=(p[i]+M)%M;
        }
}
long long solve(int n,int k){
    long long t=0;
    for(int i=0;;++i){
        if(Q[i]*k>n)    break;    
        if(i&1){
            if(((i+1)/2)&1)    t-=p[n-Q[i]*k];
            else t+=p[n-Q[i]*k];
        }
        else{
            if((i/2)&1)    t-=p[n-Q[i]*k];
            else t+=p[n-Q[i]*k];
        }
        t=(t+M)%M;
    }
    return t;
}
int main(){
    init();
    int T,n,k;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        printf("%I64d\n",solve(n,k));
    }
    return 0;
}

