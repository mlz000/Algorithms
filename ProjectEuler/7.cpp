#include<bits/stdc++.h>//104743
using namespace std;
int tot;
long long p[10005];
bool check[(int)1e7];
int main(){
	for(int i=2;;++i){
		if(!check[i])	p[++tot]=i;
		if(tot==10001)	break;
		for(int j=1;j<=tot;++j){
			if(i*p[j]>1e7)	break;
			check[i*p[j]]=true;
			if(i%p[j]==0){
				break;
			}
		}
	}
	cout<<p[10001]<<endl;
	return 0;
}
