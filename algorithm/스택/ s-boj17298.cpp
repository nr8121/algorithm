/*
오큰수 분류 
 
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	512 MB	9074	3065	2255	34.501%
문제
크기가 N인 수열 A = A1, A2, ..., AN이 있다. 수열의 각 원소 Ai에 대해서 오큰수 NGE(i)를 구하려고 한다. Ai의 오큰수는 오른쪽에 있으면서 Ai보다 큰 수 중에서 가장 왼쪽에 있는 수를 의미한다. 그러한 수가 없는 경우에 오큰수는 -1이다.

예를 들어, A = [3, 5, 2, 7]인 경우 NGE(1) = 5, NGE(2) = 7, NGE(3) = 7, NGE(4) = -1이다. A = [9, 5, 4, 8]인 경우에는 NGE(1) = -1, NGE(2) = 8, NGE(3) = 8, NGE(4) = -1이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다. 둘째에 수열 A의 원소 A1, A2, ..., AN (1 ≤ Ai ≤ 1,000,000)이 주어진다.

출력
총 N개의 수 NGE(1), NGE(2), ..., NGE(N)을 공백으로 구분해 출력한다.

예제 입력 1  복사
4
3 5 2 7
예제 출력 1  복사
5 7 7 -1
예제 입력 2  복사
4
9 5 4 8
예제 출력 2  복사
-1 8 8 -1
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    vector<int> vi;
    stack<int> s;


    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        int m;
        cin >> m;
        vi.push_back(m);
    }
    vector<int> ans(n, -1);

    for (int i = 0; i < vi.size(); i++) 
    { 
		while (!s.empty() && vi[s.top()] < vi[i]) 
        { 
			ans[s.top()] = vi[i]; 
			s.pop(); 
		} 
		s.push(i); 
	} 

    for(int x : ans)
    {
        cout << x << " ";
    }
    cout << "\n";



}