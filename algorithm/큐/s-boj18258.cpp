/*
큐 2 분류 
 
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초 (하단 참고)	512 MB	15203	4513	3600	30.764%
문제
정수를 저장하는 큐를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 여섯 가지이다.

push X: 정수 X를 큐에 넣는 연산이다.
pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 큐에 들어있는 정수의 개수를 출력한다.
empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
입력
첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 2,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다.

출력
출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.

예제 입력 1  복사
15
push 1
push 2
front
back
size
empty
pop
pop
pop
size
empty
pop
push 3
empty
front
예제 출력 1  복사
1
2
2
0
1
2
-1
0
1
-1
0
3
출처
*/
#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int front;
    int rear;
    int arr[2000000];

};

bool empty(Queue* q)
{
    if(q->arr[q->front] == q->arr[q->rear]) return true;
    else return false;
}

void push(Queue* q, int m)
{
    q->arr[q->rear] = m;
    q->rear = (q->rear +1) % 2000000;
}

int pop(Queue* q)
{
    int ret;
    if(empty(q)) return -1;
    else 
    {
        ret = q->arr[q->front];
        q->front = (q->front +1) % 2000000;
        return ret;
    }
}

int size(Queue* q)
{
    if(q->front < q->rear)
    {
        return q->rear - q->front;
    }
    else if(q->front == q->rear)
    {
        return 0;
    }
    else
    {
        return 2000000 - q->front + q->rear;
    }
    
}

int front(Queue* q)
{
    if(!empty(q)) return q->arr[q->front];
    else return -1;
}

int back(Queue* q)
{
    if(!empty(q)) return q->arr[q->rear-1];
    else return -1;
}

int strcmp(char* str1, char* str2)
{
	int i = 0;
	while (str1[i] != '\0' || str2[i] != '\0') {
		if (str1[i] != str2[i])
			return str1[i] - str2[i];
		i++;
	}
	return 0;

}

int main()
{
    int n;
    Queue q;
    q.front = 0;
    q.rear = 0;
    char* str = (char*)malloc(sizeof(char)*6);
    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++)
    {
        scanf("%s", str);
        if(strcmp(str, "push") == 0 )
        {
            int a;
            scanf("%d", &a);
            push(&q, a);
        }
        else if(strcmp(str, "front") == 0)
        {
            printf("%d\n",front(&q));

        }
        else if(strcmp(str, "empty") == 0)
        {
            if(empty(&q))
            {
                printf("1\n");
            }
            else
            {
                printf("0\n");
            }
            
        }
        else if(strcmp(str, "size") == 0)
        {
            printf("%d\n",size(&q));
        }
        else if(strcmp(str, "pop") == 0)
        {
            printf("%d\n",pop(&q));
        }
        else if(strcmp(str, "back") == 0)
        {
            printf("%d\n",back(&q));
        }
        else
        {

        }
    }

    return 0;
}