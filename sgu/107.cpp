#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	if(n<9)	puts("0");
	else if(n==9)	puts("8");
	else{
		n-=10;
		cout<<"72";
		for(int i=1;i<=n;++i)	cout<<"0";
	}
	return 0;
}
