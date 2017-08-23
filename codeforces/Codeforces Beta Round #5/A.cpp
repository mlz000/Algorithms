#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
string s;
int main()
{
	int ans=0,t=0;
	while(getline(cin,s))
	{
		if(s[0]=='+')
			t++;
		else if(s[0]=='-')
			t--;
		else{
			int w=0;
			while(s[w]!=':')
				w++;
			ans+=t*(s.length()-w-1);
			}
	}
	printf("%d",ans);
	return 0;
}


