#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
using namespace std;
const int N=15,M=256;
map<string,string>sol;
queue<string>q;
bool icy[M];
char ss[N][N],link_l[M],link_r[M],clear_l[M],clear_r[M];
int n,m,target;
void init(){
	icy['O']=icy['[']=icy[']']=icy['=']=true;
	link_l['O']=']',link_l['[']='=';
	link_r['O']='[',link_r[']']='=';
	clear_l['[']='[',clear_l[']']='O',clear_l['=']='[',clear_l['O']='O';
	clear_r['[']='O',clear_r[']']=']',clear_r['=']=']',clear_r['O']='O';
}
int h(string s){
	int a,b,x;
	x=s.find('@');
	a=x%m-target%m;
	a=abs(a);
	if(x/m>target/m)	b=x/m-target/m;
	else b=(x/m<target/m?1:0);
	return max(a,b);
}
string fall(string s){
	for(int i=n-1;i>=0;--i)
		for(int j=0,k,r;j<m;++j){
			char ch=s[i*m+j];
			if(ch=='O' || ch=='@'){
				for(k=i+1;k<n;++k)
					if(s[k*m+j]!='.')	break;
				s[i*m+j]='.';
			    s[(k-1)*m+j]=ch;
			}
			else if(ch=='['){
				for(r=j+1;r<m;++r)
					if(s[i*m+r]=='X' || s[i*m+r]==']')	break;
				if(s[i*m+r]==']'){	//down
					for(k=i+1;k<n;++k){
						bool can=true;
						for(int jj=j;jj<=r;++jj)
							if(s[k*m+jj]!='.')	{can=false;break;}
						if(!can)	break;
					}
					for(int jj=j;jj<=r;++jj)	s[i*m+jj]='.';
					for(int jj=j+1;jj<r;++jj)	s[(k-1)*m+jj]='=';
					s[(k-1)*m+j]='[',s[(k-1)*m+r]=']';
				}
				j=r;
			}
		}
	return s;
}
bool expand(string s,char op){
	string tmp=sol[s]+op;
	int x=s.find('@');
	s[x]='.';
	if(op=='<' || op=='>'){	//magic
		s[x]='@';
		int pos=(op=='<'?x+m-1:x+m+1);
		if(s[pos]=='X')	return false;
		else if(s[pos]=='.'){
			s[pos]='O';
			if(icy[s[pos-1]])	s[pos-1]=link_r[s[pos-1]];
			if(s[pos-1]!='.')	s[pos]=link_l[s[pos]];
			if(icy[s[pos+1]])	s[pos+1]=link_l[s[pos+1]];
			if(s[pos+1]!='.')	s[pos]=link_r[s[pos]];
		}
		else{
			s[pos]='.';
			if(icy[s[pos-1]])	s[pos-1]=clear_r[s[pos-1]];
			if(icy[s[pos+1]])	s[pos+1]=clear_l[s[pos+1]];
		}
	}
	else{	//move
		int pos=(op=='L'?x-1:x+1);
		if(s[pos]=='.')	s[pos]='@';
		else{
			int k;
			if(s[pos]=='O'){
				if(op=='L' && s[pos-1]=='.'){	//push left
		 			for(k=pos-1;k>0;--k)
						if(s[k-1]!='.' || s[k+m]=='.')	break;
					s[pos]='.',s[k]='O',s[x]='@';
				}
				if(op=='R' && s[pos+1]=='.'){
					for(k=pos+1;k<n*m;++k)
						if(s[k+1]!='.' || s[k+m]=='.')	break;
					s[pos]='.',s[k]='O',s[x]='@';
				}
			}
			if(s[pos]!='.'){	//go up
				if(s[pos-m]=='.' && s[x-m]=='.')	s[pos-m]='@';
				else s[x]='@';
			}
		}
	}
	s=fall(s);
	if(h(s)+tmp.length()>15)	return false;
	if(s.find('@')==target)	{printf("%s\n",tmp.c_str());return true;}
	if(!sol.count(s))	{sol[s]=tmp;q.push(s);}
	return false;
}
int main(){
	init();
	int tt=0;
	while(scanf("%d%d",&n,&m)&&n){
		string S="";
		for(int i=0;i<n;++i)	scanf("%s",ss[i]);
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j){
				if(ss[i][j]=='#')	target=i*m+j,ss[i][j]='.';
				S+=ss[i][j];
			}
		q.push(S);
		sol.clear();
		sol[S]="";
		printf("Case %d: ",++tt);
		while(q.size()){
			string t=q.front();
			q.pop();
			if(expand(t,'<'))	break;
			if(expand(t,'>'))	break;
			if(expand(t,'L'))	break;
			if(expand(t,'R'))	break;
		}
		while(q.size())	q.pop();
	}
	return 0;
}
