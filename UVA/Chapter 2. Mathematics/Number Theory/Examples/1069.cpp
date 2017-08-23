#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstring>
using namespace std;
long long ans;
struct data{
	vector<int> a,p;	//a[i]*n^p;
	void work(string s){
		int i=0,l=s.length();
		while(i<l){
			int sign=1;
			if(s[i]=='+')	i++;
			if(s[i]=='-')	sign=-1,i++;
			int v=0;
			while(i<l && isdigit(s[i]))	v=v*10+s[i++]-'0';
			if(i==l)	a.push_back(v),p.push_back(0);	//³£ÊýÏî
			else{
				if(v==0)	v=1;
				v*=sign;
				if(s[++i]=='^'){
					a.push_back(v);
					v=0;
					i++;
					while(i<l && isdigit(s[i]))	v=v*10+s[i++]-'0';
					p.push_back(v);
				}
				else{
					a.push_back(v),p.push_back(1);
				}
			}
		}
	}
	int mod(int num,int x){
		int n=a.size();
		for(int i=0;i<n;++i){
			int k=a[i];
			for(int j=1;j<=p[i];++j)	k=(long long)k*num%x;
			ans=(ans+k)%x;
		}
		return ans;
	}
}poly;
bool check(string s){
	int pos=s.find('/');
	data poly;
	poly.work(s.substr(1,pos-2));
	int x=atoi(s.substr(pos+1).c_str());
	for(int i=1;i<=poly.p[0]+1;++i){
		if(poly.mod(i,x)!=0)	return false;
	}	
	return true;
}
int main(){
	int ca=0;
	string s;
	while(cin>>s){
		if(s[0]=='.')	break;
		ans=0;ca++;
		printf("Case %d: ",ca);
		if(check(s))	printf("Always an integer\n");
		else printf("Not always an integer\n");
	}
	return 0;
}
