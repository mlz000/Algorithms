#include<stdio.h>
#include<string.h>
int i,n,cnt;
char s[81];
int main()
{
    while(scanf("%s",s)!=EOF)
    {
        if(strcmp(s,"<br>")==0)
        {
            printf("\n");
            cnt=0;
        }
        else if(strcmp(s,"<hr>")==0)
        {
            if(cnt!=0) {printf("\n");cnt=0;}
            if(cnt==0)
            {
                for(i=1;i<=80;i++)
                {
                     printf("-");
                }
                printf("\n");
                cnt=0;
            }
        }
        else
        {
            if(cnt+strlen(s)+(cnt==0?0:1)>80)//加一位空格
            {
              printf("\n%s",s);
              cnt=strlen(s);
            }
            else{
                if(cnt!=0) printf(" ");
                printf("%s",s);
                cnt=cnt+strlen(s)+1;//加空格
            }
        }
    }
    printf("\n");
    return 0;
}
