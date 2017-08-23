#include<cstdio> 
#include<iostream> 
using namespace std; 
char num[4][10][5] = 
{     
	{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},     
	{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},     
	{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},     
	{"", "M", "MM", "MMM"}
}; 
char name[7]={'I','V','X','L','C','D','M'}; 
int ans[7];
int cnt(char p)
{
     switch(p)
	 {
	  case 'I':return 0;
	  case 'V':return 1;
	  case 'X':return 2;
	  case 'L':return 3;
	  case 'C':return 4;
	  case 'D':return 5;
	  case 'M':return 6; 
	 } 
} 
void add(int a,int b)
{
   int j;
   for(j=0;num[a][b][j]!='\0';++j)
    ans[cnt(num[a][b][j])]++; 
} 
void dfs(int x)
{
    int i=0;//Î»Êý 
	while(x!=0) 
    {
	 add(i,x%10);
	 x=x/10;
	 i++; 
	} 
}  
int main()
{
	int i,j,n;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	 dfs(i); 
	for(i=0;i<=6;++i)
	 {
			if(ans[i]!=0) 
			printf("%c %d\n",name[i],ans[i]);
	 } 
    //system("pause");
	return 0;	
}	
