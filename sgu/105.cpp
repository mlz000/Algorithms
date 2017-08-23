#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	cin>>n;
	int l=n%3;
	n/=3;
	if(l==2)	cout<<n*2+1<<endl;
	else cout<<n*2<<endl;
	return 0;
}
