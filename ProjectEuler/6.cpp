#include<bits/stdc++.h>//25164150
using namespace std;
int main(){
	long long t1=0,t2=0;
	for(int i=1;i<=100;++i)	t1+=i*i;
	for(int i=1;i<=100;++i)	t2+=i;
	cout<<t2*t2-t1<<endl;
	return 0;
}
