#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
long long a,b,c,ans;

int main() {
	while (cin>>a>>b>>c) {
		if (a>b) swap(a,b);
		if (a>c) swap(a,c);
		if (b>c) swap(b,c);
		if ((a==0) && (b==0) && (c==0)) ans=0;
		if ((a==0) && (b==0) && (c>0)) {
			if (c==1) ans=0;else ans=c*2-3;
		}
		if ((a==0) && (b==1)) {
			if (c==1) ans=1;else ans=c*3-3;
		}
		if ((a==0) && (b==2)) ans=c*4-2;
		if ((a==1) && (b==1)) {
			if (c==1) ans=3;else ans=c*4-2;
		}
		if ((a==1) && (b==2)) ans=c*5;
		if (a>=2) ans=(a+b+c)*6-21;
		cout<<ans<<endl;
	}
	return 0;
}

