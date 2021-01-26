/*
이항 계수 2 분류 
 
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	24910	9310	7294	38.497%
문제
자연수 
N
과 정수 
K
가 주어졌을 때 이항 계수 
(
N
K
)
를 10,007로 나눈 나머지를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 
N
과 
K
가 주어진다. (1 ≤ 
N
 ≤ 1,000, 0 ≤ 
K
 ≤ 
N
)

출력
 
(
N
K
)
를 10,007로 나눈 나머지를 출력한다.

예제 입력 1  복사
5 2
예제 출력 1  복사
10
*/
#include<iostream>
using namespace std;
int dp[1001][1001];
int main()
{
    //nCr==n-1Cr + n-1Cr-1
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        dp[i][1] = i;
        dp[i][i] = 1;
        dp[i][0] = 1;
    }
    for (int i = 3; i <= n; i++)
    {
        for (int j = 2; j < i; j++)
        {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
        }
    }
    cout << dp[n][k] % 10007 << endl;
    
}
