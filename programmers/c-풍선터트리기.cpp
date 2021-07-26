/*
풍선 터트리기
dark
light
sublime
vim
emacs
 C++ 
문제 설명

일렬로 나열된 n개의 풍선이 있습니다. 모든 풍선에는 서로 다른 숫자가 써져 있습니다. 당신은 다음 과정을 반복하면서 풍선들을 단 1개만 남을 때까지 계속 터트리려고 합니다.
임의의 인접한 두 풍선을 고른 뒤, 두 풍선 중 하나를 터트립니다.
터진 풍선으로 인해 풍선들 사이에 빈 공간이 생겼다면, 빈 공간이 없도록 풍선들을 중앙으로 밀착시킵니다.
여기서 조건이 있습니다. 인접한 두 풍선 중에서 번호가 더 작은 풍선을 터트리는 행위는 최대 1번만 할 수 있습니다. 즉, 어떤 시점에서 인접한 두 풍선 중 번호가 더 작은 풍선을 터트렸다면, 그 이후에는 인접한 두 풍선을 고른 뒤 번호가 더 큰 풍선만을 터트릴 수 있습니다.
당신은 어떤 풍선이 최후까지 남을 수 있는지 알아보고 싶습니다. 위에 서술된 조건대로 풍선을 터트리다 보면, 어떤 풍선은 최후까지 남을 수도 있지만, 어떤 풍선은 무슨 수를 쓰더라도 마지막까지 남기는 것이 불가능할 수도 있습니다.
일렬로 나열된 풍선들의 번호가 담긴 배열 a가 주어집니다. 위에 서술된 규칙대로 풍선들을 1개만 남을 때까지 터트렸을 때 최후까지 남기는 것이 가능한 풍선들의 개수를 return 하도록 solution 함수를 완성해주세요.
제한 사항
a의 길이는 1 이상 1,000,000 이하입니다.
a[i]는 i+1 번째 풍선에 써진 숫자를 의미합니다.
a의 모든 수는 -1,000,000,000 이상 1,000,000,000 이하인 정수입니다.
a의 모든 수는 서로 다릅니다.
입출력 예
a	result
[9,-1,-5]	3
[-16,27,65,-2,58,-92,-71,-68,-61,-33]	6
입출력 예 설명
입출력 예 #1
첫 번째 풍선(9가 써진 풍선)을 최후까지 남기는 방법은 다음과 같습니다.
[9, -1, -5] 에서 -1, -5가 써진 풍선을 고른 뒤, -1이 써진 풍선(번호가 더 큰 것)을 터트립니다.
[9, -5] 에서 9, -5가 써진 풍선을 고른 뒤, -5가 써진 풍선(번호가 더 작은 것)을 터트립니다.
두 번째 풍선(-1이 써진 풍선)을 최후까지 남기는 방법은 다음과 같습니다.
[9, -1, -5] 에서 9, -1이 써진 풍선을 고른 뒤, 9가 써진 풍선(번호가 더 큰 것)을 터트립니다.
[-1, -5] 에서 -1, -5가 써진 풍선을 고른 뒤, -5가 써진 풍선(번호가 더 작은 것)을 터트립니다.
세 번째 풍선(-5가 써진 풍선)을 최후까지 남기는 방법은 다음과 같습니다.
[9, -1, -5] 에서 9, -1이 써진 풍선을 고른 뒤, 9가 써진 풍선(번호가 더 큰 것)을 터트립니다.
[-1, -5] 에서 -1, -5가 써진 풍선을 고른 뒤, -1이 써진 풍선(번호가 더 큰 것)을 터트립니다.
3개의 풍선이 최후까지 남을 수 있으므로, 3을 return 해야 합니다.
입출력 예 #2
최후까지 남을 수 있는 풍선은 -16, -92, -71, -68, -61, -33이 써진 풍선으로 모두 6개입니다.
*/

#include <string>
#include <vector>
#include <set>

using namespace std;

set<int> result;


void dfs(vector<int> input, vector<bool> visited, bool chance, int visit)
{
    if(visit != -1) visited[visit] = true;

    printf("%d->", visit);
    for(int i = 0; i < input.size(); i++)
    {
        if(visited[i]) continue;
        int left = i-1;
        int right = i+1;
        while(left >= 0 && visited[left]) left--;
        while(right < input.size() && visited[right]) right++;
        
        if(left >= 0)
        {
            if(input[i] > input[left])
            {
                if(chance)
                {
                    dfs(input, visited, false, left);
                }
                dfs(input, visited, chance, i);
            }
            else
            {
                if(chance)
                {
                    dfs(input, visited, false, i);
                }
                dfs(input, visited, chance, left);
            }
        }
        if(right < input.size())
        {
            if(input[i] > input[right])
            {
                if(chance)
                {
                    dfs(input, visited, false, right);
                }
                dfs(input, visited, chance, i);
            }
            else
            {
                if(chance)
                {
                    dfs(input, visited, false, i);
                }
                dfs(input, visited, chance, right);
            }
        }

        if(left < 0 && right >= input.size()) 
        {
            result.insert(i);
            printf("%d\n", i);
        }
        
    }
}

int solve(vector<int> a)
{
    vector<bool> visited(a.size(), false);
    dfs(a, visited, true, -1);
}

int solution(vector<int> a) {
    int answer = 0;
    solve(a);
    answer = result.size();
    return answer;
}

int main()
{
    vector<int> a = {9, -1, -5};
    printf("%d\n", solution(a));
}