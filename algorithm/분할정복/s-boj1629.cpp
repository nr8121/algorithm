/*
곱셈 분류 
 
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
0.5 초 (추가 시간 없음)	128 MB	32460	8182	6036	25.267%
문제
자연수 A를 B번 곱한 수를 알고 싶다. 단 구하려는 수가 매우 커질 수 있으므로 이를 C로 나눈 나머지를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 A, B, C가 빈 칸을 사이에 두고 순서대로 주어진다. A, B, C는 모두 2,147,483,647 이하의 자연수이다.

출력
첫째 줄에 A를 B번 곱한 수를 C로 나눈 나머지를 출력한다.

예제 입력 1  복사
10 11 12
예제 출력 1  복사
4
*/
#include <iostream>
using namespace std;

long long c;

long long power(long long  a, long long b)
{
    long long ret;
    if(b == 0)
    {
        return 1;
    }
    long long temp;
    temp = power(a, b/2);
    /*
    if(b % 2 == 0)
    {   
        ret = temp * temp %c;
    }
    else
    {
        ret= (temp * temp % c) * a % c;
    }
    */
    if(b % 2 == 0)
    {   
        ret = ((temp%c) * (temp%c)) %c;
    }
    else
    {
        ret= (((temp%c) * (temp%c)) %c) * a % c;
    }

    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long a, b;

    cin >> a >> b >> c;

    cout << power(a, b) << "\n";



    return 0;
}