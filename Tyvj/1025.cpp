#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
char s[65];
int main()
{
    int i,l,n;
    scanf("%d",&n);
    while(n--)
    {
       scanf("%s",s);
       l=strlen(s);
       if((s[l-1]-'0')%2==0) printf("even\n");
       else printf("odd\n");
    }
   // system("pause");
    return 0;
}
