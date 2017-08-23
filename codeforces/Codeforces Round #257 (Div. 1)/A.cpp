#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,m,k;
	cin>>n>>m>>k;
	if(k>n+m-2)	puts("-1");
	else cout<<max(k<n?m*(n/(k+1)):m/(k-n+2),k<m?n*(m/(k+1)):n/(k-m+2))<<endl;
	return 0;
}
