/*
동전 0 분류 
 
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	39534	21009	16682	53.070%
문제
준규가 가지고 있는 동전은 총 N종류이고, 각각의 동전을 매우 많이 가지고 있다.

동전을 적절히 사용해서 그 가치의 합을 K로 만들려고 한다. 이때 필요한 동전 개수의 최솟값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 10, 1 ≤ K ≤ 100,000,000)

둘째 줄부터 N개의 줄에 동전의 가치 Ai가 오름차순으로 주어진다. (1 ≤ Ai ≤ 1,000,000, A1 = 1, i ≥ 2인 경우에 Ai는 Ai-1의 배수)

출력
첫째 줄에 K원을 만드는데 필요한 동전 개수의 최솟값을 출력한다.

예제 입력 1  복사
10 4200
1
5
10
50
100
500
1000
5000
10000
50000
예제 출력 1  복사
6
예제 입력 2  복사
10 4790
1
5
10
50
100
500
1000
5000
10000
50000
예제 출력 2  복사
12
*/

#include <stdio.h>
int arr[10];

void coin(int n, int k){

    int i = n-1;
    int count = 0;
    while(k != 0){
        if(arr[i] > k){
            i--;
        }else{
            int t = k/arr[i];
            k %= arr[i];
            count += t;
        }
    }
    printf("%d\n", count);

}

int main(int argc, char* argv[]){
    int n;
    int k;
    scanf("%d %d", &n, &k);

    for(int i = 0 ; i < n ; i++){
        scanf("%d", &arr[i]);
    }
    coin(n, k);
    return 0;
}