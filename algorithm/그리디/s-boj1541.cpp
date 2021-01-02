/*
잃어버린 괄호 분류 
 
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	18631	8889	7244	48.329%
문제
세준이는 양수와 +, -, 그리고 괄호를 가지고 식을 만들었다. 그리고 나서 세준이는 괄호를 모두 지웠다.

그리고 나서 세준이는 괄호를 적절히 쳐서 이 식의 값을 최소로 만들려고 한다.

괄호를 적절히 쳐서 이 식의 값을 최소로 만드는 프로그램을 작성하시오.

입력
첫째 줄에 식이 주어진다. 식은 ‘0’~‘9’, ‘+’, 그리고 ‘-’만으로 이루어져 있고, 가장 처음과 마지막 문자는 숫자이다. 그리고 연속해서 두 개 이상의 연산자가 나타나지 않고, 5자리보다 많이 연속되는 숫자는 없다. 수는 0으로 시작할 수 있다. 입력으로 주어지는 식의 길이는 50보다 작거나 같다.
출력
첫째 줄에 정답을 출력한다.

예제 입력 1  복사
55-50+40
예제 출력 1  복사
-35
출처
*/
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

int compare(std::string a, std::string b){
    return a < b;
}
int stringtoint(std::string a){
    int ret = 0;
    int ten = 1;
    for(int i = a.length()-1 ; i >= 0 ; i--){
        int temp = (a[i]-48)*ten;
        ten *= 10;
        ret += temp;
    }
    return ret;
}
int main(int argc, char* argv[]){
    std::string str;
    int ret;
    int arr[25] = {0,};


    std::cin >> str;
    
    std::string temp;
    int s = 0;
    int t = 0;
    int j = 0;
    for(int i = 0 ; i < str.length(); i++){
        if(str[i] == '+'){
            s += t;
            t = 0;
        }else if(str[i] == '-'){
            s += t;
            arr[j] = s;
            j++;
            t = 0;
            s = 0;

        }else{
            t *= 10;
            t += (str[i] -'0');
        }
    }
    s += t;
    arr[j] = s;
    ret = arr[0];
    for(int i = 1 ; arr[i] != 0; i++){
        ret -= arr[i];
    }
    
    std::cout << ret << std::endl;

}