#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int solve(int k){
    int pre;
    int tmp = k+1;
    int n = 2*k;
    while(tmp){
        if((tmp-1)%n >= k && (tmp-1)%n < 2*k){
            pre = (tmp-1)%n;
            int i;
            for(i = 2 ; i <= k ; i++){
               int x = (pre+tmp-1)%(n-i+1); 
               if(x < k || x >= 2*k)
                   break;
               else
                   pre = x;
            } 
            if(i == k+1)
                return tmp;
        }
        tmp++;
    }
}

int main(){
    int k , ans[20];
    for(int i = 1 ; i < 15 ; i++)
        ans[i] = solve(i);
    while(scanf("%d" , &k) && k)
        printf("%d\n" , ans[k]);
    return 0;
}


