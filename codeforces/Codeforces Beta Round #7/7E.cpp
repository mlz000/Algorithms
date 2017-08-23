#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
map<string,int>mp;
string s,t;
char tmp[105];
int get(int l,int r){
	int L,R,b=0;
	for(int i=r-1;i>=l;--i){
		b+=(t[i]=='(')-(t[i]==')');
		if(!b && (t[i]=='+' || t[i]=='-')){
			L=get(l,i),R=get(i+1,r);
			return L && R && (t[i]=='+' || R>1);
		}
	}
	for(int i=r-1;i>=l;--i){
		b+=(t[i]=='(')-(t[i]==')');
		if(!b && (t[i]=='*' || t[i]=='/')){
			L=get(l,i),R=get(i+1,r);
			return L>1 && R>1 && (t[i]=='*' || R==3)?2:0;
		}
	}
	if(t[l]=='(')	return get(l+1,r-1)?3:0;
	string x=t.substr(l,r-l);
	return mp.count(x)?mp[x]:3;
}
int work(){
	gets(tmp);
	int l=strlen(tmp);
	t="";
	for(int i=0;i<l;i++)	if(tmp[i]!=' ') t+=tmp[i];
	return get(0,t.size());
}
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		scanf(" #%*s"),cin>>s;
		mp[s]=work();
	}
	puts(work()?"OK":"Suspicious");
	return 0;
}
