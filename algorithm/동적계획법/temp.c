#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char dp[1001][1001] = {0,};
int max(int a, int b){ return a > b ? a : b; }
void lcs(char* a, char* b){
    for(int i = 1; i <= strlen(a); i++){
        for(int j = 1; j <= strlen(b); j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    printf("%d\n", dp[strlen(a)][strlen(b)]);
}

int main(int argc, char* argv[]){
    char* first = (char*)malloc(sizeof(char)*1001);
    char* second = (char*)malloc(sizeof(char)*1001);

    //memset(first, 0, sizeof(char)*1001);
    //memset(second, 0, sizeof(char)*1001);
    scanf("%s", first);
    scanf("%s", second);
    lcs(first, second);
    return 0;
}