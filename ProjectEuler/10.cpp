#include<bits/stdc++.h>//142913828922
using namespace std;
const int N=2000001;
long long ans,p[N];
int tot;
bool check[N];
int main(){
	for(int i=2;i<N;++i){
		if(!check[i])	p[++tot]=i;
		for(int j=1;j<=tot;++j){
			if(i*p[j]>N)	break;
			check[i*p[j]]=true;
			if(i%p[j]==0){
				break;
			}
		}
	}
	for(int i=1;i<=tot;++i)	ans+=p[i];
	cout<<ans<<endl;
	return 0;
}
