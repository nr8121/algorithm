/*
소인수분해 분류 
 
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	18302	9895	7779	53.560%
문제
정수 N이 주어졌을 때, 소인수분해하는 프로그램을 작성하시오.

입력
첫째 줄에 정수 N (1 ≤ N ≤ 10,000,000)이 주어진다.

출력
N의 소인수분해 결과를 한 줄에 하나씩 오름차순으로 출력한다. N이 1인 경우 아무것도 출력하지 않는다.

예제 입력 1  복사
72
예제 출력 1  복사
2
2
2
3
3
예제 입력 2  복사
3
예제 출력 2  복사
3
예제 입력 3  복사
6
예제 출력 3  복사
2
3
예제 입력 4  복사
2
예제 출력 4  복사
2
예제 입력 5  복사
9991
예제 출력 5  복사
97
103
*/

#include <iostream>

/*
int main(){
    int n;
    int i = 2;
    std::cin >> n;
    
    if(n == 1) return 0;
    while(1){
        if(n % i == 0){
            n = n/i;
            std::cout << i << std::endl;
            i = 2;
        }else if(n == 1){
            break;
        }else{
            i++;
        }
    }
}
*/
int main(){
    int n;
    std::cin >> n;
    
    if(n == 1) return 0;
    for(int i = 2; i*i <= n; i++){
        while(1){
            if(n % i == 0){
                n = n/i;
                std::cout << i << std::endl;
            }else{
                break;
            }
        }
    }
    if(n > 1)
        std::cout << n << std::endl;
}