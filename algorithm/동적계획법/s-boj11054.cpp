#include <iostream>
/*
가장 긴 바이토닉 부분 수열 분류 
 
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	18137	9506	7559	52.617%
문제
수열 S가 어떤 수 Sk를 기준으로 S1 < S2 < ... Sk-1 < Sk > Sk+1 > ... SN-1 > SN을 만족한다면, 그 수열을 바이토닉 수열이라고 한다.

예를 들어, {10, 20, 30, 25, 20}과 {10, 20, 30, 40}, {50, 40, 25, 10} 은 바이토닉 수열이지만,  {1, 2, 3, 2, 1, 2, 3, 2, 1}과 {10, 20, 30, 40, 20, 30} 은 바이토닉 수열이 아니다.

수열 A가 주어졌을 때, 그 수열의 부분 수열 중 바이토닉 수열이면서 가장 긴 수열의 길이를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 수열 A의 크기 N이 주어지고, 둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ N ≤ 1,000, 1 ≤ Ai ≤ 1,000)

출력
첫째 줄에 수열 A의 부분 수열 중에서 가장 긴 바이토닉 수열의 길이를 출력한다.

예제 입력 1  복사
10
1 5 2 1 4 3 4 5 2 1
예제 출력 1  복사
7
힌트
예제의 경우 {1 5 2 1 4 3 4 5 2 1}이 가장 긴 바이토닉 부분 수열이다.

출처
*/
int arr[1000];
int r_lis[1000];
int l_lis[1000];

int max(int a, int b){ return a > b ? a: b;}

void left(int n){
    for(int i = 0 ; i < n; i ++){
        l_lis[i] = 1;
        for(int j = 0; j < i ; j++){
            if(arr[i] > arr[j]){
                int temp = l_lis[j] + 1;
                l_lis[i] = max(temp, l_lis[i]);
            }
            
        }
    }
}

void right(int n){
    for(int i = n-1 ; i >= 0; i --){
        r_lis[i] = 1;
        for(int j = n-1 ; j >= i ; j--){
            if(arr[i] > arr[j]){
                int temp = r_lis[j] + 1;
                r_lis[i] = max(temp, r_lis[i]);
            }
            
        }
    }
}



void bitonic(int n){
    int ret = 0;// 0초기화 중요했다.
    
    right(n);
    left(n);
    for(int i = 0 ; i < n ; i ++){
        ret = max(ret, r_lis[i]+l_lis[i]-1);
    }
    
    
    for(int i = 0 ; i < n ; i++){
        printf("%d ", l_lis[i]);
    }
    printf("\n");
    for(int i = 0 ; i < n ; i++){
        printf("%d ", r_lis[i]);
    }
    printf("\n");
    
    printf("%d\n", ret);
}

int main(int argc, char* argv[]){
    int n;
    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        scanf("%d", &arr[i]);
    }

    bitonic(n);

}