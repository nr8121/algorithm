/*
소수 찾기
dark
light
sublime
vim
emacs
 C++ 
문제 설명

한자리 숫자가 적힌 종이 조각이 흩어져있습니다. 흩어진 종이 조각을 붙여 소수를 몇 개 만들 수 있는지 알아내려 합니다.
각 종이 조각에 적힌 숫자가 적힌 문자열 numbers가 주어졌을 때, 종이 조각으로 만들 수 있는 소수가 몇 개인지 return 하도록 solution 함수를 완성해주세요.
제한사항
numbers는 길이 1 이상 7 이하인 문자열입니다.
numbers는 0~9까지 숫자만으로 이루어져 있습니다.
"013"은 0, 1, 3 숫자가 적힌 종이 조각이 흩어져있다는 의미입니다.
입출력 예
numbers	return
"17"	3
"011"	2
입출력 예 설명
예제 #1
[1, 7]으로는 소수 [7, 17, 71]를 만들 수 있습니다.
예제 #2
[0, 1, 1]으로는 소수 [11, 101]를 만들 수 있습니다.
11과 011은 같은 숫자로 취급합니다.
출처
*/

#include <string>
#include <vector>
#include <math.h>
#include <set>

using namespace std;

bool isPrimeNumber(string number)
{
    int numberToInt = atoi(number.c_str());
    if(numberToInt == 1 || numberToInt == 0) return false;

    for(int i = 2 ; i <= sqrt(numberToInt) ; i++)
    {
        if(numberToInt % i == 0) return false;
    }

    return true;
}

void select(string numbers, string selected, int selectedIndex, set<string>* s)
{
    if(selectedIndex != -1) numbers.erase(numbers.begin()+selectedIndex);
    if(numbers.empty()) return;
    for(int i = 0 ; i < numbers.size() ; i++)
    {
        string temp = selected+numbers[i];
        while(temp[0] == '0') temp.erase(temp.begin());
        if(isPrimeNumber(temp)) s->insert(temp);
        select(numbers, temp, i, s);
    }
}

int solution(string numbers) {
    set<string> s;
    select(numbers, "", -1, &s);

    return s.size();
}
