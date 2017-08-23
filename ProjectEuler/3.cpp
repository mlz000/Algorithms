#include<bits/stdc++.h>//6857
using namespace std;
int main(){
	long long x=600851475143;
	int ans;
	for(int i=sqrt(x)+1;i>=2;--i){
		int f=1;
		if(x%i)	continue;
		for(int j=2;j*j<=i;++j)
			if(i%j==0){
				f=0;
				break;
			}
		if(f){
			ans=i;
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}
