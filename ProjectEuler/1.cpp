#include<bits/stdc++.h>//233168
using namespace std;
int main(){
	int ans=0;
	for(int i=3;i<1000;++i)
		if(i%3==0 || i%5==0)	ans+=i;
	cout<<ans<<endl;
	return 0;
}
