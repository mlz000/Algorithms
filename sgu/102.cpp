#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int tot,n,f[N],p[N];
bool check[N];
int main(){
	f[1]=1;
	for(int i=2;i<N;++i){
		if(!check[i])	p[++tot]=i,f[i]=i-1;
		for(int j=1;j<=tot;++j){
			if(i*p[j]>=N)	break;
			check[i*p[j]]=true;
			if(i%p[j]==0)	f[i*p[j]]=f[i]*p[j];
			else f[i*p[j]]=f[i]*(p[j]-1);
		}
	}
	cin>>n;
	cout<<f[n]<<endl;
	return 0;
}
