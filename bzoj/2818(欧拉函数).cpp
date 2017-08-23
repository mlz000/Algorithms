#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e7+5;
int n,tot,p[N];
long long f[N];
bool check[N];
void init(){
	for(int i=2;i<=n;++i){
		if(!check[i])	p[++tot]=i,f[i]=i-1;
		for(int j=1;j<=tot;++j){
			if(i*p[j]>n)	break;
			check[i*p[j]]=true;
			if(i%p[j]==0){
				f[i*p[j]]=f[i]*p[j];
				break;
			}
			else f[i*p[j]]=f[i]*(p[j]-1);
		}
	}
	for(int i=3;i<=n;++i)	f[i]+=f[i-1];
}		
int main(){
	cin>>n;
	init();
	long long ans=0ll;
	for(int i=1;i<=tot;++i)	ans+=(f[n/p[i]]<<1)+1;
	cout<<ans<<endl;
	return 0;
}

