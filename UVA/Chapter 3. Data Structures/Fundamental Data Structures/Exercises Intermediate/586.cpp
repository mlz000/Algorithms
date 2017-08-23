#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
 
const int MAXN = 15;
 
int ans[MAXN];
char str[MAXN];
 
void getAns(vector<string>v , int x){
    int size = v.size();
    int num_n = 0;
    int num_xishu = x;
    for(int i = 0 ; i < size ; i++){
        int len = v[i].size();
        if(v[i][0] == 'n')
            num_n++;
        else{
            int sum = 0;
            for(int j = 0 ; j < len ; j++) 
                sum = sum*10 + v[i][j]-'0';
            num_xishu *= sum;
        }
    }
    ans[num_n] += num_xishu;
}
 
void solve(vector<string>v){
    int x;
    while(1){
        scanf("%s" , str);
        if(str[0] == 'L'){
            scanf("%s" , str); 
            v.push_back(str); 
            solve(v);
            v.pop_back();
        }
        else if(str[0] == 'O'){
            scanf("%d" , &x); 
            getAns(v , x);
        }
        else if(str[0] == 'E'){
            return;
        }
    }
}
 
void output(){
    printf("Runtime = ");
    bool isFirst = true;
    bool isTime = false;
    for(int i = MAXN-1 ; i >= 1 ; i--){
        if(ans[i]){
            isTime = true; 
            if(isFirst)
                isFirst = false;
            else
                printf("+");
            if(ans[i] > 1)
                printf("%d*" , ans[i]); 
            printf("n");
            if(i > 1)
                printf("^%d" , i);
        }
    }
    if(ans[0]){
        isTime = true; 
        if(!isFirst)
            printf("+");
        printf("%d" , ans[0]);
    }
    if(!isTime)
        printf("0");
    printf("\n\n");
}
 
int main(){
    int Case , cas = 1;
    vector<string>v;
    scanf("%d" , &Case);
    while(Case--){
        scanf("%s" , str); 
        memset(ans , 0 , sizeof(ans));
        printf("Program #%d\n" , cas++);
        v.clear();
        solve(v);
        output();
    } 
    return 0;
}

