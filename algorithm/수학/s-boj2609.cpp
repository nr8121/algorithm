/*
최대공약수와 최소공배수 출처분류 
 
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	32111	19064	15659	63.151%
문제
두 개의 자연수를 입력받아 최대 공약수와 최소 공배수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에는 두 개의 자연수가 주어진다. 이 둘은 10,000이하의 자연수이며 사이에 한 칸의 공백이 주어진다.

출력
첫째 줄에는 입력으로 주어진 두 수의 최대공약수를, 둘째 줄에는 입력으로 주어진 두 수의 최소 공배수를 출력한다.

예제 입력 1  복사
24 18
예제 출력 1  복사
6
72

*/
#include <iostream>
int max(int a, int b){return a>b? a:b;}
int min(int a, int b){return a<b? a:b;}
//유클리드
int lcm(int a, int b, int gcd){ return (a*b)/gcd;}

int gcd(int a, int b){
    int first = max(a,b);
    int second = min(a,b);

    int remainder = first % second;
    if(remainder == 0 ) return second;
    return gcd(second, remainder);
}
/* 비효율 . 성공
int lcm(int first, int second){
    int i = 1;
    int j = 1;
    while(first*i != second*j){
        if(first*i > second*j) j++;
        else i++;
    }
    return first*i;
}
int gcd(int first, int second){
    int lager = max(first, second);
    int smaller = min(first, second);
    int ret = 0;
    for(int i = 1 ; i*i <= smaller*smaller; i++){
        if(lager%i == 0 && smaller%i == 0) ret = i;
    }
    return ret;
}
*/

int main(){
    int f;
    int s;

    std::cin >> f >> s;

    
    int n = gcd(f, s);
    int m = lcm(f, s, n);

    std::cout << n << std::endl;
    std::cout << m << std::endl;
    
}