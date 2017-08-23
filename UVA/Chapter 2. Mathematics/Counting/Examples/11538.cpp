#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef unsigned long long Ull;
Ull n,m;
int main(){
	while((cin>>n>>m)&&n&&m){
		if(n>m)	swap(n,m);
		cout<<n*m*(m+n-2)+2*n*(n-1)*(3*m-n-1)/3<<endl;
	}
	return 0;
}
		
