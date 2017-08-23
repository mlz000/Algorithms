#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std ;
typedef long long LL ;
const int N=1000;
const double eps = 1e-8;
bool rev[N],a[N];
int f[N][2];
class FlippingBitsDiv1{
	public:
	int getmin(vector <string> S, int m){
		int n=S.size();
		string s;
		for(int i=0;i<n;++i)	s+=S[i];
		n=s.size();
		int k=n/m;
		int ans=n;
		if(k<=17){//k is small m is big
			for(int i=0;i<(1<<k);++i){
				memset(rev,0,sizeof(rev));
				int cnt=0;
				for(int j=0;j<k;++j)	
					if(i&(1<<j))	rev[min((j+1)*m-1,n-1)]=true,cnt++;
				for(int j=0;j<n;++j)	a[j]=s[j]-'0';
				bool f=false;
				for(int j=n-1;j>=0;--j){
					f^=rev[j];
					a[j]^=f;
				}
				for(int j=0;j<m;++j){
					int cnt1=0,cnt2=0;
					for(int k=j;k<n;k+=m){
						if(a[k])	cnt1++;
						else cnt2++;
					}
					cnt+=min(cnt1,cnt2);
				}
				ans=min(ans,cnt);
			}
		}
		else{//k is big m is small
			for(int i=0;i<n;++i)	a[i]=s[i]-'0';
			for(int i=0,j,k;i<(1<<m);++i){
				for(j=0;j<n;j+=m){
					int cnt1=0,cnt2=0;
					for(k=0;k<m && j+k<n;++k){
						if(a[j+k]!=((i>>k)&1))	cnt1++;//different from the final string
						else cnt2++;
					}
					f[j+m][0]=min(f[j][0]+cnt1,f[j][1]+cnt2+1);//first string is similar to final string
					f[j+m][1]=min(f[j][0]+cnt1+1,f[j][1]+cnt2);//firsr string is as opposed to final string	
				}
				ans=min(ans,f[j][0]);
			}
		}
		return ans;
	}
};
