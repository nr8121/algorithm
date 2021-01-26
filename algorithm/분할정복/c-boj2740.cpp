/*
행렬 곱셈 분류 
 
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	6283	4352	3799	71.801%
문제
N*M크기의 행렬 A와 M*K크기의 행렬 B가 주어졌을 때, 두 행렬을 곱하는 프로그램을 작성하시오.

입력
첫째 줄에 행렬 A의 크기 N 과 M이 주어진다. 둘째 줄부터 N개의 줄에 행렬 A의 원소 M개가 순서대로 주어진다. 그 다음 줄에는 행렬 B의 크기 M과 K가 주어진다. 이어서 M개의 줄에 행렬 B의 원소 K개가 차례대로 주어진다. N과 M, 그리고 K는 100보다 작거나 같고, 행렬의 원소는 절댓값이 100보다 작거나 같은 정수이다.

출력
첫째 줄부터 N개의 줄에 행렬 A와 B를 곱한 행렬을 출력한다. 행렬의 각 원소는 공백으로 구분한다.

예제 입력 1  복사
3 2
1 2
3 4
5 6
2 3
-1 -2 0
0 0 3
예제 출력 1  복사
-1 -2 6
-3 -6 12
-5 -10 18
*/

#include <iostream>

using namespace std;
int matrixA[100][100];
int matrixB[100][100];
int matrixResult[100][100];
int am, an, bm, bn;

void matrixM()
{
    for(int column = 0; column < am; column++)
    {
        for(int row = 0 ; row < bn; row++)
        {
            for(int i = 0; i < an; i++)
            {
                matrixResult[column][row] += matrixA[column][i] * matrixB[i][row];
            }
        }
    }
}
void printMatrix(int arr[100][100], int column, int row)
{
    for(int i = 0 ; i < column; i++)
    {
        for(int j = 0 ; j < row; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> am >> an;

    for(int column = 0 ; column < am; column++)
    {
        for(int row = 0 ; row < an; row++)
        {
            cin >> matrixA[column][row];
        }
    }

    cin >> bm >> bn;

    for(int column = 0 ; column < bm; column++)
    {
        for(int row = 0 ; row < bn; row++)
        {
            cin >> matrixB[column][row];
        }
    }
    matrixM();
    printMatrix(matrixResult, am, bn);
}