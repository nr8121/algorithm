/*
숫자 카드 2 분류 
 
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	28298	9844	7009	35.340%
문제
숫자 카드는 정수 하나가 적혀져 있는 카드이다. 상근이는 숫자 카드 N개를 가지고 있다. 정수 M개가 주어졌을 때, 이 수가 적혀있는 숫자 카드를 상근이가 몇 개 가지고 있는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 상근이가 가지고 있는 숫자 카드의 개수 N(1 ≤ N ≤ 500,000)이 주어진다. 둘째 줄에는 숫자 카드에 적혀있는 정수가 주어진다. 숫자 카드에 적혀있는 수는 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다.

셋째 줄에는 M(1 ≤ M ≤ 500,000)이 주어진다. 넷째 줄에는 상근이가 몇 개 가지고 있는 숫자 카드인지 구해야 할 M개의 정수가 주어지며, 이 수는 공백으로 구분되어져 있다. 이 수도 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다.

출력
첫째 줄에 입력으로 주어진 M개의 수에 대해서, 각 수가 적힌 숫자 카드를 상근이가 몇 개 가지고 있는지를 공백으로 구분해 출력한다.

예제 입력 1  복사
10
6 3 2 10 10 10 -10 -10 7 3
8
10 9 -5 2 3 4 5 -10
예제 출력 1  복사
3 0 0 1 2 0 0 2
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//a = arr c = compare

/* 시간초과 -> 모두 같은 경우는 n만큼 시간 걸려서인듯.
int find2(vector<int>* arr, int index)
{
    if(index == -1) return 0;

    int count = 1;
    int temp =  arr->at(index);
    for(int i = index-1; i >= 0; i--)
    {
        if(arr->at(i) != temp) break;
        count++;
    }
    for(int i = index+1; i < arr->size(); i++)
    {
        if(arr->at(i) != temp) break;
        count++;
    }
    return count;
}

int find(vector<int>* arr, int start, int end, int n)
{
    if(start > end) return -1;

    int mid = (start+end)/2;
    if(arr->at(mid) > n) return find(arr, start, mid-1, n);
    else if(arr->at(mid) < n) return find(arr, mid+1, end, n);
    else return mid;
    // else
    // {
    //     cout << "mid = " << mid << "\n";
    //     return mid;
    // }

}
*/
int main()
{
    int n, m;

    cin >> n;

    vector<int> a(n);

    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
    }

    cin >> m;

    vector<int> c(m);

    for(int i = 0 ; i < m ; i++)
    {
        cin >> c[i];
    }

    sort(a.begin(), a.end());

    for(int i = 0 ; i < m ; i++)
    {
        cout << find2(&a, find(&a, 0, n-1, c[i])) << " ";
    }
    cout << "\n";
    
}