#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const int N=100005;
int n,k,a[N],b[N],c[N];
void add(int x){
    for(;x<=n;x+=x&-x)    c[x]++;
}
long long ask(int x){
    long long tmp=0ll;
    for(;x;x-=x&-x)    tmp+=c[x];
    return tmp;
}
int main(){
    while(~scanf("%d%d",&n,&k)){
        memset(c,0,sizeof(c));
		vector<int>v;
        for(int i=1;i<=n;++i)	scanf("%d",&a[i]),v.push_back(a[i]);
		sort(v.begin(),v.end());
        unique(v.begin(),v.end());
		for(int i=1;i<=n;++i)    b[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
        long long sum=0ll;
        for(int i=1;i<=n;++i)    add(b[i]),sum+=i-ask(b[i]);
        sum-=k;
        if(sum<0)    sum=0;
        printf("%I64d\n",sum);
    }
    return 0;
}
