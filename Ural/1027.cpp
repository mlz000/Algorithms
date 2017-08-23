#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
string s,tmp;
void init()
{
	while(getline(cin,tmp))	s+=tmp;
}
bool check()
{
	int l=s.length();
	bool in=false;
	int left=0;
	for(int i=0;i<l;++i)
	{
		if(s[i]!='*' && in) continue;
		if(s[i]=='(')
		{
			if(i<l-1 && s[i+1]=='*')	++i,in=true;
			else left++;
			continue;
		}
		if(s[i]=='*')
		{
			if(i<l-1 && s[i+1]==')' &&in)	++i,in=false;
			continue;
		}
        if(s[i] >= '0' && s[i] <= '9') continue;
 		if(s[i] == '=' || s[i] == '+' || s[i] == '-' || s[i] == '/')		continue;
		if(s[i]==')')	
		{
			left--;
			if(left<0) return false;
			continue;
		}
		if(left==0) continue;
		return false;
	}
	if(in || left>0) return false;
	return true;
}
int main()
{
	init();
	if(check())	printf("YES\n");
	else printf("NO\n");
	return 0;
}
