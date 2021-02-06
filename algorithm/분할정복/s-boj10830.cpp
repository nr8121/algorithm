/*
행렬 제곱 분류 
 
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	8329	2862	2327	34.628%
문제
크기가 N*N인 행렬 A가 주어진다. 이때, A의 B제곱을 구하는 프로그램을 작성하시오. 수가 매우 커질 수 있으니, A^B의 각 원소를 1,000으로 나눈 나머지를 출력한다.

입력
첫째 줄에 행렬의 크기 N과 B가 주어진다. (2 ≤ N ≤  5, 1 ≤ B ≤ 100,000,000,000)

둘째 줄부터 N개의 줄에 행렬의 각 원소가 주어진다. 행렬의 각 원소는 1,000보다 작거나 같은 자연수 또는 0이다.

출력
첫째 줄부터 N개의 줄에 걸쳐 행렬 A를 B제곱한 결과를 출력한다.

예제 입력 1  복사
2 5
1 2
3 4
예제 출력 1  복사
69 558
337 406
예제 입력 2  복사
3 3
1 2 3
4 5 6
7 8 9
예제 출력 2  복사
468 576 684
62 305 548
656 34 412
예제 입력 3  복사
5 10
1 0 0 0 1
1 0 0 0 1
1 0 0 0 1
1 0 0 0 1
1 0 0 0 1
예제 출력 3  복사
512 0 0 0 512
512 0 0 0 512
512 0 0 0 512
512 0 0 0 512
512 0 0 0 512
*/
#include <iostream>
#include <vector>

using namespace std;
typedef vector<vector<int> > vvi;

void printMatrix(vvi matrix, int size)
{
    for(int column = 0; column < size; column++)
    {
        for(int row = 0; row < size; row++)
        {
            cout << matrix[column][row] << " ";
        }
        cout << "\n";
    }             
}

vvi matrixMulti(vvi a, vvi b, int size)
{
    vvi ret(size, vector<int>(size));
    for(int column = 0; column < size; column++)
    {
        for(int row = 0; row < size; row++)
        {
            for(int i = 0; i < size; i++)
            {
                ret[column][row] += a[column][i] * b[i][row];
                ret[column][row] %= 1000;

            }
        }
    }
    return ret;
}

vvi matrixPow(vvi matrix, int size)
{
    vvi ret(size, vector<int>(size));
    for(int column = 0; column < size; column++)
    {
        for(int row = 0; row < size; row++)
        {
            for(int i = 0; i < size; i++)
            {
                ret[column][row] += matrix[column][i] * matrix[i][row];
                ret[column][row] %= 1000;
            }
        }
    }
    return ret;
}

vvi matrixNPow(vvi matrix, int size, long long n)
{
    if(n == 1)
        return matrix;
    
    vvi temp = matrixNPow(matrix, size, n/2);
    if(n % 2 == 0)
        return matrixPow(temp, size);
    else
        return matrixMulti(matrixPow(temp, size), matrix, size);

}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long recur;
    int size;
    cin >> size >> recur;
    vvi matrix(size, vector<int>(size));

    for(int column = 0; column < size; column++)
    {
        for(int row = 0; row < size; row++)
        {
            cin >> matrix[column][row];
            matrix[column][row]%=1000;
            /*
            2 1
            1000 1000
            1000 1000 중요했음.
            */
        }
    }
    printMatrix(matrixNPow(matrix, size, recur), size);
}