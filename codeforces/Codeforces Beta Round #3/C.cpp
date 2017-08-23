#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
char map[5][5];
bool judge(char c)
{
	for(int i=1;i<=3;i++)
	{
		if(map[i][1]==c&&map[i][2]==c&&map[i][3]==c)
			return true;
	}
	for(int i=1;i<=3;i++)
	{
		if(map[1][i]==c&&map[2][i]==c&&map[3][i]==c)
			return true;
	}
	if(map[1][1]==c&&map[2][2]==c&&map[3][3]==c)
		return true;
	else if(map[1][3]==c&&map[2][2]==c&&map[3][1]==c)
		return true;
	return false;
}

int main()
{
	char now;
	int x(0),o(0),dot(0);
	for(int i=1;i<=3;i++,getchar())
	{
		for(int j=1;j<=3;j++)
		{
			now=getchar();
			map[i][j]=now;
			if(now=='X') x++;
			else if(now=='0') o++;
			else if(now=='.') dot++;
		}
	}
	if(abs(x-o)>1 || o-x>0 ||(judge('X')&&judge('0')) || (judge('X')&&x-o!=1)||(judge('0')&&x!=o))
	{
		printf("illegal\n");
	}
	else if(judge('X'))
	{
		printf("the first player won\n");
	}
	else if(judge('0'))
	{
		printf("the second player won\n");
	}
	else if( dot==0 )
	{
		printf("draw\n");
	}
	else
	{		
		if( (x-o)==1 ) printf("second\n");
		else if( x==o ) printf("first\n");
	}
	return 0;
}

