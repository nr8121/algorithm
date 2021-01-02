
/*
LCS 분류 
 
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	27138	11113	8201	40.593%
문제
LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.

예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.

입력
첫째 줄과 둘째 줄에 두 문자열이 주어진다. 문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.

출력
첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를 출력한다.

예제 입력 1  복사
ACAYKP
CAPCAK
예제 출력 1  복사
4
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//int;;;
int dp[1001][1001] = {0,};
/*
int len(char* str){
    int ret = 0;
    for(int i = 0 ; str[i] != '\0'; i++){
        ret++;
    }
    return ret;
}
*/
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

    memset(first, 0, sizeof(char)*1001);
    memset(second, 0, sizeof(char)*1001);

    scanf("%s", first);
    scanf("%s", second);
/*
    char alpha[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    for(int i = 0 ; i < 1000; i++){
        first[i] = alpha[rand()%26];
        second[i] = alpha[rand()%26];
    }
    printf("%s\n", first);
    printf("%s\n", second);
*/
    lcs(first, second);
    free(first);
    free(second);
    return 0;
}