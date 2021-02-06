/*
K번째 수 분류 
 
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	12102	4270	3134	37.901%
문제
세준이는 크기가 N×N인 배열 A를 만들었다. 배열에 들어있는 수 A[i][j] = i×j 이다. 이 수를 일차원 배열 B에 넣으면 B의 크기는 N×N이 된다. B를 오름차순 정렬했을 때, B[k]를 구해보자.

배열 A와 B의 인덱스는 1부터 시작한다.

입력
첫째 줄에 배열의 크기 N이 주어진다. N은 10^5보다 작거나 같은 자연수이다. 둘째 줄에 k가 주어진다. k는 min(10^9, N^2)보다 작거나 같은 자연수이다.

출력
B[k]를 출력한다.

예제 입력 1  복사
3
7
예제 출력 1  복사
6
*/

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;


int bSearch(int n)
{
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;

    cin >> n;
    cin >> m;



}




/*
메모리 초과

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;

    cin >> n;
    cin >> m;


    vector<int> a(pow(n, 2));
    
    int k = 0;
    for(int i = 1 ; i <= n ; i ++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            a[k] = i*j;
            k++;
        }
    }
    sort(a.begin(), a.end());
    for(int i = 0 ; i < pow(n, 2); i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
    cout << a[m-1] << "\n";


}
*/