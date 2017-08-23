#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<map>
#include<string>
using namespace std;
map<string,int>m;
int main()
{
	int n;
	string s;
	scanf("%d",&n);
	while(n--)
	{
		cin>>s;
		if(!m.count(s))
		{
			m.insert(make_pair(s,1));
			cout<<"OK"<<endl;
		}
		else
		{
			m[s]++;
			cout<<s<<m[s]-1<<endl;
		}
	}
	return 0;
}

