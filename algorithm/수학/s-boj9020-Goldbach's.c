#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
문제
1보다 큰 자연수 중에서  1과 자기 자신을 제외한 약수가 없는 자연수를 소수라고 한다. 예를 들어, 5는 1과 5를 제외한 약수가 없기 때문에 소수이다. 하지만, 6은 6 = 2 × 3 이기 때문에 소수가 아니다.

골드바흐의 추측은 유명한 정수론의 미해결 문제로, 2보다 큰 모든 짝수는 두 소수의 합으로 나타낼 수 있다는 것이다. 이러한 수를 골드바흐 수라고 한다. 또, 짝수를 두 소수의 합으로 나타내는 표현을 그 수의 골드바흐 파티션이라고 한다. 예를 들면, 4 = 2 + 2, 6 = 3 + 3, 8 = 3 + 5, 10 = 5 + 5, 12 = 5 + 7, 14 = 3 + 11, 14 = 7 + 7이다. 10000보다 작거나 같은 모든 짝수 n에 대한 골드바흐 파티션은 존재한다.

2보다 큰 짝수 n이 주어졌을 때, n의 골드바흐 파티션을 출력하는 프로그램을 작성하시오. 만약 가능한 n의 골드바흐 파티션이 여러 가지인 경우에는 두 소수의 차이가 가장 작은 것을 출력한다.

입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고 짝수 n이 주어진다. (4 ≤ n ≤ 10,000)

출력
각 테스트 케이스에 대해서 주어진 n의 골드바흐 파티션을 출력한다. 출력하는 소수는 작은 것부터 먼저 출력하며, 공백으로 구분한다.

예제 입력 1  복사
3
8
10
16
예제 출력 1  복사
3 5
5 5
5 11
*/

int isPrime(int number)
{
    if (number == 1)
        return 0;
    for(int i = 2 ; i <= sqrt(number) ; i++ )
    {
        if((number % i) == 0)
            return 0;
    }
    return 1;
}
void gold_(int n)
{
    int a;
    int b;
    int middle = n / 2;
    int sub = n;
    for(int i = middle ; i >= 2 ; i--)
    {   
        if(middle - i > sub)
            break;
        if(isPrime(i))
        {
            for(int j = middle ; j < n ; j++)
            {
                if(j-i > sub)
                    break;
                if(isPrime(j))
                {
                    if(i + j == n)
                    {
                        a = i;
                        b = j;
                        sub = j - i;
                    }
                        
                }
            }
        }
    }
    printf("%d %d\n",a,b);
    

}
int main()
{
    int n;
    int temp[10000];

    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d",&temp[i]);
    }
    for(int i = 0 ; i < n ; i++)
    {
        gold_(temp[i]);
    }
    return 0;
}