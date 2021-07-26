/*
N으로 표현
dark
light
sublime
vim
emacs
 C++ 
문제 설명

아래와 같이 5와 사칙연산만으로 12를 표현할 수 있습니다.
12 = 5 + 5 + (5 / 5) + (5 / 5)
12 = 55 / 5 + 5 / 5
12 = (55 + 5) / 5
5를 사용한 횟수는 각각 6,5,4 입니다. 그리고 이중 가장 작은 경우는 4입니다.
이처럼 숫자 N과 number가 주어질 때, N과 사칙연산만 사용해서 표현 할 수 있는 방법 중 N 사용횟수의 최솟값을 return 하도록 solution 함수를 작성하세요.
제한사항
N은 1 이상 9 이하입니다.
number는 1 이상 32,000 이하입니다.
수식에는 괄호와 사칙연산만 가능하며 나누기 연산에서 나머지는 무시합니다.
최솟값이 8보다 크면 -1을 return 합니다.
입출력 예
N	number	return
5	12	4
2	11	3
입출력 예 설명
예제 #1
문제에 나온 예와 같습니다.
예제 #2
11 = 22 / 2와 같이 2를 3번만 사용하여 표현할 수 있습니다.
출처
※ 공지 - 2020년 9월 3일 테스트케이스가 추가되었습니다.
*/
#include <string>
#include <vector>
#include <set>
#include <math.h>
using namespace std;
int MAX = 8;
vector<set<int>> dp = vector<set<int>>(9);

int solve(int N, int number)
{
    //n*i;
    int temp = 0;
    for(int i = 1; i <= MAX; i++)
    {
        temp += N*pow(10, i-1);
        dp[i].insert(temp);
    }

    for(int i = 1; i <= MAX; i++)
    {
        for(int j = 1; j < i; j++)
        {
            for(int item1 : dp[j])
            {
                for(int item2 : dp[i-j])
                {
                    dp[i].insert(item1*item2);
                    dp[i].insert(item1+item2);
                    dp[i].insert(item1-item2);
                    if(item2 != 0)
                        dp[i].insert(item1/item2);
                }
            }
        }

        if(dp[i].find(number) != dp[i].end())
            return i;
    }
    return -1;
}
int solution(int N, int number) {
    int answer = 0;
    answer = solve(N, number);
    return answer;
}