#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<stack>
using namespace std;
const int N=1000005;
char s[N];
int main()
{
	scanf("%s",s);
	int l=strlen(s);
	stack<int> st;
	int len=0,num=1,pos=-1;
	for(int i=0;i<l;++i)
	{
		if(s[i]=='(')	st.push(i);
		else 
		{
			if(st.empty())	pos=i;
			else 
			{
				st.pop();
				int tmp=i-(st.empty()?pos:st.top());
				if(tmp>len)	{len=tmp,num=1;}
				else if(tmp==len)	++num;
			}
		}
	}
	printf("%d %d\n",len,num);
	return 0;
}
