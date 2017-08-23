#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
#include<algorithm> 
using namespace std;
const int N=105;
int f[N][N];
char s[N];
int path[N][N];
void dfs(int i,int j)
{
     if(i>j) return ;
     if(i==j) 
	 {
			if(s[i]=='(' || s[i]==')') printf("()");
            else  printf("[]");
	 }
	 else if(path[i][j]==-1) 
	 {
			printf("%c",s[i]);
			dfs(i+1,j-1);
	        printf("%c",s[j]);
	 }
	  else
	   {
	       dfs(i,path[i][j]);
	       dfs(path[i][j]+1,j);
	   }
}
int main()
{ 
       int i,j,k,r,l;
        while(gets(s))
	{
        l=strlen(s);
        if(l==0){
            printf("\n");
            continue;
                }
       memset(f,0,sizeof(f));
       for(i=0;i<l;++i)
       f[i][i]=1;
       for(r=1;r<l;++r)//小区间递推大区间r为区间长度 
        for(i=0;i<l-r;++i)
        {
		   j=i+r; 
		   f[i][j]=INT_MAX;
		   if((s[i]=='(' && s[j]==')')||(s[i]=='[' && s[j]==']'))
		    {
				if(f[i][j]>f[i+1][j-1])
				  {
						f[i][j]=f[i+1][j-1];
			            path[i][j]=-1;
				  }
			}
		   for(k=i;k<j;++k)
		   {
	          if(f[i][j]>f[i][k]+f[k+1][j])       
		      {
					f[i][j]=f[i][k]+f[k+1][j];
					path[i][j]=k;
			  }
		   } 
		}
       dfs(0,l-1);
       printf("\n");
	}
      // system("pause");
       return 0;
}
