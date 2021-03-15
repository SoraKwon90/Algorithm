#include <stdio.h>
#include <queue>
#include <iostream>
using namespace std;

#define MAX_N 100

int front;
int rear;
int q1[MAX_N];

void queueInit(void)
{
    front = 0;
    rear = 0;
}

bool queueIsEmpty(void)
{
    return (front == rear);
}

bool queueIsFull(void)
{
    if ((rear + 1) % MAX_N == front)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Enqueue(int value)
{
    if (queueIsFull())
    {
        printf("queue is full!");
        return 0;
    }
    q1[rear] = value;
    rear++;
    /*queue가 꽉 찬 경우 real index 초기화*/
    if (rear == MAX_N)
    {
        rear = 0;
    }

    return 1;
}

int Dequeue(int* value)
{
    if (queueIsEmpty())
    {
        printf("queue is empty!");
        return 0;
    }
    *value = q1[front];
    front++;
    if (front == MAX_N)
    {
        front = 0;
    }
    return 1;
}

// using STL
queue<int> q2;
void queueSTLInit()
{
    while (!q2.empty())
    {
        q2.pop();
    }
}

int main()
{
    int T;
    int N;

    scanf_s("%d", &T);

    for (int test_case = 1; test_case <= T; test_case++)
    {
        scanf_s("%d", &N);

        queueInit();
        queueSTLInit();
        
        for (int i = 0; i < N; i++)
        {
            int value;
            scanf_s("%d", &value);
            Enqueue(value);
            q2.push(value);
        }

        printf("#%d \n", test_case);

        while (!queueIsEmpty())
        {
            int value;
            if (Dequeue(&value) == 1)
            {
                printf("%d ", value);
            }
        }
        printf("\n");

        while (!q2.empty())
        {
            int value = q2.front(); // return front value
            q2.pop(); // delete front value
            printf("%d ", value);
        }
        printf("\n");
    }
    return 0;
}