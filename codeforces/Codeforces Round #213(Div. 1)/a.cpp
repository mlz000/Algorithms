#include <iostream>
#include <cstdio>
using namespace std;
const int N=50000;
long long ans,x,n,i,j,a[N],s[N],h[N];
string ss;
int main() {
	cin >> x >> ss;
	n=ss.length();
	for (i=0;i<n;i++) {
		a[i+1]=ss[i]-'0';
		s[i+1]=s[i]+a[i+1];
	}
	for (i=1;i<=n;i++)
		for (j=0;j<i;j++)
			h[s[i]-s[j]]++;
	if (x==0) 
		for (i=0;i<=s[n];i++) ans+=h[0]*h[i];
	for (i=1;i<=s[n];i++)
		if ((x%i==0)&&(x/i<=s[n]))
			ans+=h[i]*h[x/i];
	cout << ans << endl;
	return 0;
}

