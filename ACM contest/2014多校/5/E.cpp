#include<iostream>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<algorithm>
using namespace std;
const int N=1000005;
int l;
char s[N];
bool check(){
	int x=0;
	for(int i=0;i<l;++i){
		if(s[i]=='(')	x++;
		else x--;
		if(x<0)	return false;
	}
	return x==0;
}
int main(){
	while(~scanf("%s",s)){
		l=strlen(s);
		int L,R,p1,p2;
		L=R=0,p1=p2=-1;
		for(int i=0;i<l;++i){
			if(s[i]=='(')	L++;
			else if(s[i]==')')	R++;
		}
		if(l%2==1){
			printf("None\n");
			continue;
		}
		for(int i=0;i<l;++i){
			if(s[i]=='?' && L*2<l){
				s[i]='(';
				L++;
				p1=i;
			}
		}
		for(int i=l-1;i>=0;--i){
			if(s[i]=='?' && R*2<l){
				s[i]=')';
				R++;
				p2=i;
			}
		}
		if(L!=R){
			printf("None\n");
			continue;
		}
		if(check()){
			s[p1]=')';
			s[p2]='(';
			if(check())	printf("Many\n");
			else printf("Unique\n");
		}
		else printf("None\n");
	}
	return 0;
}
