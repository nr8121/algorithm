int*로 받고, 인덱스 접근
#include<stdio.h>
int* getNumbers() {
    static int arr[6] = {1,2,3,4,5,6};
    return arr;
}
int main() {
    int* nums = getNumbers();
    for(int i=0; i<6; i++) printf("%d ", nums[i]);
    // 1 2 3 4 5 6 
}
C
3 2차원 배열
int*로 받고, 포인터 접근
#include<stdio.h>
int* getNumbers2() {
    static int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    return (int*) arr;
}
int main() {
    int* nums = getNumbers2();
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) printf("%d ", *(nums+i*3+j));
        printf("| ");
    }
    // 1 2 3 | 4 5 6 | 7 8 9 | 
}
C
int*로 받고, 인덱스 접근
#include<stdio.h>
int* getNumbers2() {
    static int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    return (int*) arr;
}
int main() {
    int (*nums)[3] = (void*)getNumbers2();
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) printf("%d ", nums[i][j]);
        printf("| ");
    }
    // 1 2 3 | 4 5 6 | 7 8 9 | 
}
C
void*로 받고, 인덱스 접근
#include<stdio.h>
void* getNumbers2() {
    static int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    return (void*) arr;
}
int main() {
    int (*nums)[3] = getNumbers2();
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) printf("%d ", nums[i][j]);
        printf("| ");
    }
    // 1 2 3 | 4 5 6 | 7 8 9 | 
}


C
4 3차원 배열
int*로 받고, 포인터 접근
#include<stdio.h>
int* getNumbers3() {
    static int arr[2][2][3] = { {{1,2,3},{4,5,6}}, {{7,8,9},{10,11,12}} };
    return (int*) arr;
}
int main() {
    int *nums = getNumbers3();
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            for(int k=0; k<3; k++) printf("%d ", *(nums+6*i+3*j+k));
            printf(", ");
        }
        printf("| ");
    }
    // 1 2 3 , 4 5 6 , | 7 8 9 , 10 11 12 , | 
}
C
int*로 받고, 인덱스 접근
#include<stdio.h>
int* getNumbers3() {
    static int arr[2][2][3] = { {{1,2,3},{4,5,6}}, {{7,8,9},{10,11,12}} };
    return (int*) arr;
}
int main() {
    int (*nums)[2][3] = (void*)getNumbers3();
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            for(int k=0; k<3; k++) printf("%d ", nums[i][j][k]);
            printf(", ");
        }
        printf("| ");
    }
    // 1 2 3 , 4 5 6 , | 7 8 9 , 10 11 12 , | 
}
C
void*로 받고, 인덱스 접근
#include<stdio.h>
void* getNumbers3() {
    static int arr[2][2][3] = { {{1,2,3},{4,5,6}}, {{7,8,9},{10,11,12}} };
    return (void*) arr;
}
int main() {
    int (*nums)[2][3] = getNumbers3();
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            for(int k=0; k<3; k++) printf("%d ", nums[i][j][k]);
            printf(", ");
        }
        printf("| ");
    }
    // 1 2 3 , 4 5 6 , | 7 8 9 , 10 11 12 , | 
}


C언어 1차원 배열 파라미터로 넘기기
2 int a[3]
#include<stdio.h>
void print(int a[3]) {
    for(int i=0; i<3; i++) printf("%d ", a[i]);
}
int main() {
   int arr[] = {1, 2, 3};
   print(arr); // 1 2 3  
}
C▶
CPU 0.02s | MEM 18.3MB | 총 1.318s
1 2 3
3 int a[]
#include<stdio.h>
void print(int a[]) {
    for(int i=0; i<3; i++) printf("%d ", a[i]);
}
int main() {
   int arr[] = {1, 2, 3};
   print(arr); // 1 2 3  
}
C▶
CPU 0.02s | MEM 18.2MB | 총 1.678s
1 2 3
4 int* a
#include<stdio.h>
void print(int* a) {
    for(int i=0; i<3; i++) printf("%d ", a[i]);
}
int main() {
   int arr[] = {1, 2, 3};
   print(arr); // 1 2 3  
}
C▶
CPU 0.03s | MEM 18.2MB | 총 1.464s
1 2 3
5 void* a
#include<stdio.h>
void print(void* a) {
    for(int i=0; i<3; i++) printf("%d ", ((int*)a)[i]);
}
int main() {
   int arr[] = {1, 2, 3};
   print(arr); // 1 2 3  
}
C▶
CPU 0.02s | MEM 18.2MB | 총 1.182s
1 2 3




C언어 2차원 배열 파라미터로 넘기기
2 int a[3][3] ★★
#include<stdio.h>
void print(int a[3][3]) {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) printf("%d ", a[i][j]);
        printf("| ");
    }
}
int main() {
   int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
   print(arr); // 1 2 3 | 4 5 6 | 7 8 9 | 
}
C▶
CPU 0.02s | MEM 18.4MB | 총 0.937s
1 2 3 | 4 5 6 | 7 8 9 |
3 int a[][3] ★★
#include<stdio.h>
void print(int a[][3]) {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) printf("%d ", a[i][j]);
        printf("| ");
    }
}
int main() {
   int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
   print(arr); // 1 2 3 | 4 5 6 | 7 8 9 | 
}
C▶
CPU 0.02s | MEM 18.5MB | 총 1.540s
1 2 3 | 4 5 6 | 7 8 9 |

4 int (*a)[3] ★
#include<stdio.h>
void print(int (*a)[3]) {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) printf("%d ", a[i][j]);
        printf("| ");
    }
}
int main() {
   int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
   print(arr); // 1 2 3 | 4 5 6 | 7 8 9 | 
}
C▶
CPU 0.02s | MEM 18.4MB | 총 1.625s
1 2 3 | 4 5 6 | 7 8 9 |

5 int* a
#include<stdio.h>
void print(int* a) {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) printf("%d ", *(a+i*3+j));
        printf("| ");
    }
}
int main() {
   int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
   print((int*)arr); // 1 2 3 | 4 5 6 | 7 8 9 | 
}
C▶
CPU 0.03s | MEM 18.4MB | 총 1.316s
1 2 3 | 4 5 6 | 7 8 9 |
#include<stdio.h>
void print(int* a) {
    int (*b)[3] = (void*) a;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) printf("%d ", b[i][j]);
        printf("| ");
    }
}
int main() {
   int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
   print((int*)arr); // 1 2 3 | 4 5 6 | 7 8 9 | 
}
C▶
CPU 0.02s | MEM 18.4MB | 총 1.558s
1 2 3 | 4 5 6 | 7 8 9 |
6 void* a ★★
#include<stdio.h>
void print(void* a) {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) printf("%d ", *((int*)a+i*3+j));
        printf("| ");
    }
}
int main() {
   int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
   print((void*)arr); // 1 2 3 | 4 5 6 | 7 8 9 | 
}
C▶
CPU 0.03s | MEM 18.4MB | 총 1.094s
1 2 3 | 4 5 6 | 7 8 9 |
#include<stdio.h>
void print(void* a) {
    int (*b)[3] = a;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) printf("%d ", b[i][j]);
        printf("| ");
    }
}
int main() {
   int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
   print((void*)arr); // 1 2 3 | 4 5 6 | 7 8 9 | 
}
C▶
CPU 0.02s | MEM 18.4MB | 총 1.056s
1 2 3 | 4 5 6 | 7 8 9 |



C언어 3차원 배열 파라미터로 넘기기
2 int a[2][2][3] ★★
#include<stdio.h>
void print(int a[2][2][3]) {
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            for(int k=0; k<3; k++) printf("%d ", a[i][j][k]);
            printf(", ");
        }
        printf("| ");
    }
}
int main() {
   int arr[2][2][3] = { {{1,2,3},{4,5,6}}, {{7,8,9},{10,11,12}} };
   print(arr); // 1 2 3 , 4 5 6 , | 7 8 9 , 10 11 12 , | 
}
C▶
CPU 0.03s | MEM 18.5MB | 총 1.253s
1 2 3 , 4 5 6 , | 7 8 9 , 10 11 12 , |
3 int a[][2][3] ★★
#include<stdio.h>
void print(int a[][2][3]) {
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            for(int k=0; k<3; k++) printf("%d ", a[i][j][k]);
            printf(", ");
        }
        printf("| ");
    }
}
int main() {
   int arr[2][2][3] = { {{1,2,3},{4,5,6}}, {{7,8,9},{10,11,12}} };
   print(arr); // 1 2 3 , 4 5 6 , | 7 8 9 , 10 11 12 , | 
}
C▶
CPU 0.02s | MEM 18.5MB | 총 1.625s
1 2 3 , 4 5 6 , | 7 8 9 , 10 11 12 , |
4 int (*a)[2][3]
#include<stdio.h>
void print(int (*a)[2][3]) {
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            for(int k=0; k<3; k++) printf("%d ", a[i][j][k]);
            printf(", ");
        }
        printf("| ");
    }
}
int main() {
   int arr[2][2][3] = { {{1,2,3},{4,5,6}}, {{7,8,9},{10,11,12}} };
   print(arr); // 1 2 3 , 4 5 6 , | 7 8 9 , 10 11 12 , | 
}
C▶
CPU 0.02s | MEM 18.6MB | 총 1.530s
1 2 3 , 4 5 6 , | 7 8 9 , 10 11 12 , |
5 int* a
#include<stdio.h>
void print(int *a) {
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            for(int k=0; k<3; k++) printf("%d ", *(a+6*i+3*j+k));
            printf(", ");
        }
        printf("| ");
    }
}
int main() {
   int arr[2][2][3] = { {{1,2,3},{4,5,6}}, {{7,8,9},{10,11,12}} };
   print((int*)arr); // 1 2 3 , 4 5 6 , | 7 8 9 , 10 11 12 , | 
}
C▶
CPU 0.03s | MEM 18.5MB | 총 1.519s
1 2 3 , 4 5 6 , | 7 8 9 , 10 11 12 , |
#include<stdio.h>
void print(int *a) {
    int (*b)[2][3] = (void*)a;
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            for(int k=0; k<3; k++) printf("%d ", b[i][j][k]);
            printf(", ");
        }
        printf("| ");
    }
}
int main() {
   int arr[2][2][3] = { {{1,2,3},{4,5,6}}, {{7,8,9},{10,11,12}} };
   print((int*)arr); // 1 2 3 , 4 5 6 , | 7 8 9 , 10 11 12 , | 
}
C▶
CPU 0.02s | MEM 18.5MB | 총 1.538s
1 2 3 , 4 5 6 , | 7 8 9 , 10 11 12 , |
6 void* a ★★
#include<stdio.h>
void print(void *a) {
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            for(int k=0; k<3; k++) printf("%d ", *((int*)a+6*i+3*j+k));
            printf(", ");
        }
        printf("| ");
    }
}
int main() {
   int arr[2][2][3] = { {{1,2,3},{4,5,6}}, {{7,8,9},{10,11,12}} };
   print((int*)arr); // 1 2 3 , 4 5 6 , | 7 8 9 , 10 11 12 , | 
}
C▶
CPU 0.02s | MEM 18.5MB | 총 1.572s
1 2 3 , 4 5 6 , | 7 8 9 , 10 11 12 , |
#include<stdio.h>
void print(void *a) {
    int (*b)[2][3] = a;
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            for(int k=0; k<3; k++) printf("%d ", b[i][j][k]);
            printf(", ");
        }
        printf("| ");
    }
}
int main() {
   int arr[2][2][3] = { {{1,2,3},{4,5,6}}, {{7,8,9},{10,11,12}} };
   print((int*)arr); // 1 2 3 , 4 5 6 , | 7 8 9 , 10 11 12 , | 
}
C▶
CPU 0.02s | MEM 18.5MB | 총 1.262s
1 2 3 , 4 5 6 , | 7 8 9 , 10 11 12 , |