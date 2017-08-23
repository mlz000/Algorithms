#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,k,A[30],B[30],C,D;
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>A[i]>>B[i];
		C+=A[i];
		D+=B[i];
	}
	if((k<C)||(k>D)){
		cout<<"NO";
		return 0;
	}
	cout<<"YES\n";
	for(int i=0;i<n;i++){
		cout<<min(B[i],k-C+A[i])<<' ';
		k-=min(B[i],k-C+A[i]);
		C-=A[i];
	}
	return 0;
}



