/*
스택 수열 분류 
 
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	45874	15021	10889	32.914%
문제
스택 (stack)은 기본적인 자료구조 중 하나로, 컴퓨터 프로그램을 작성할 때 자주 이용되는 개념이다. 스택은 자료를 넣는 (push) 입구와 자료를 뽑는 (pop) 입구가 같아 제일 나중에 들어간 자료가 제일 먼저 나오는 (LIFO, Last in First out) 특성을 가지고 있다.

1부터 n까지의 수를 스택에 넣었다가 뽑아 늘어놓음으로써, 하나의 수열을 만들 수 있다. 이때, 스택에 push하는 순서는 반드시 오름차순을 지키도록 한다고 하자. 임의의 수열이 주어졌을 때 스택을 이용해 그 수열을 만들 수 있는지 없는지, 있다면 어떤 순서로 push와 pop 연산을 수행해야 하는지를 알아낼 수 있다. 이를 계산하는 프로그램을 작성하라.

입력
첫 줄에 n (1 ≤ n ≤ 100,000)이 주어진다. 둘째 줄부터 n개의 줄에는 수열을 이루는 1이상 n이하의 정수가 하나씩 순서대로 주어진다. 물론 같은 정수가 두 번 나오는 일은 없다.

출력
입력된 수열을 만들기 위해 필요한 연산을 한 줄에 한 개씩 출력한다. push연산은 +로, pop 연산은 -로 표현하도록 한다. 불가능한 경우 NO를 출력한다.

예제 입력 1  복사
8
4
3
6
8
7
5
2
1
예제 출력 1  복사
+
+
+
+
-
-
+
+
-
+
+
-
-
-
-
-
예제 입력 2  복사
5
1
2
5
3
4
예제 출력 2  복사
NO
*/

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    stack<int> s;
    queue<int> q;
    vector<char> v;
    int n;
    int m;
    bool flag = false;


    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> m;
        q.push(m);
        
    }
    int i = 1;
    while(q.size())
    {
        m = q.front();
        if(i <= m)
        {
            s.push(i);
            v.push_back('+');
            i++;
        }
        else
        {
            if(s.empty())
            {
                flag = true;
                break;
            }
            while(s.top() > m)
            {
                s.pop();
                v.push_back('-');
            }
            if(s.top() == m)
            {
                s.pop();
                q.pop();
                v.push_back('-');
            }
            else
            {
                flag = true;
                break;
            }
            
        }
        
    }
    
    if(flag) cout << "NO\n";
    else
    {
        for(int i = 0 ; i < v.size(); i++)
        {
            cout << v.at(i) << "\n";
        }
    }

    
}