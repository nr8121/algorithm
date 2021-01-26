/*
이항 계수 1 분류 
 
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	17041	10872	9415	64.668%
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
를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 
N
과 
K
가 주어진다. (1 ≤ 
N
 ≤ 10, 0 ≤ 
K
 ≤ 
N
)

출력
 
(
N
K
)
를 출력한다.

예제 입력 1  복사
5 2
예제 출력 1  복사
10
*/
#include <stdio.h>
int factorial(int n){
    int ret = 1;
    for(int i = 2 ; i <= n ; i ++){
        ret *=  i;
    }
    return ret;
}
int main(){
    int n,k;

    scanf("%d %d", &n, &k);

    printf("%d\n",factorial(n)/factorial(n-k)/factorial(k));
    
}