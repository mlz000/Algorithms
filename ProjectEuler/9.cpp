#include<bits/stdc++.h>//31875000
using namespace std;
int main(){
	for(int i=1;i<=333;++i)
		for(int j=i+1;j<=500;++j)
			for(int k=j+1;k<=1000;++k)
				if(i+j+k==1000 && i*i+j*j==k*k){
					cout<<i*j*k<<endl;
				}
	return 0;
}
