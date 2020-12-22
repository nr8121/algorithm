#include <iostream>

/*
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	60290	22980	15197	36.739%
문제
수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

출력
첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.

예제 입력 1  복사
6
10 20 10 30 20 50
예제 출력 1  복사
4
출처
*/

int arr[1001];
int dp[1001];

int max(int a, int b){ return a > b ? a: b;}

void lis(int n){
    dp[1] = 1;
    for(int i = 2 ; i <= n; i ++){
        if(dp[i]==0)dp[i] = 1;
        for(int j = 1; j <= i-1 ; j++){
            if(arr[i] > arr[j]){
                int temp = dp[j] + 1;
                dp[i] = max(temp, dp[i]);
            }
            
        }
    }
    int ret = 0;
    for(int i = 1 ; i <= n ; i ++){
        ret = max(ret, dp[i]);
    }
    printf("%d\n", ret);
}

int main(int argc, char* argv[]){
    int n;
    scanf("%d", &n);

    for(int i = 1 ; i <= n ; i++){
        scanf("%d", &arr[i]);
    }

    lis(n);

}