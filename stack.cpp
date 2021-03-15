#include <stdio.h> // for using scanf_s(), printf_s()
#include <stack>  // for using stl stack
#include <iostream>
using namespace std;

#define MAX_N 100

int top;
int s1[MAX_N];

void stackInit(void)
{
	top = 0;
}

bool stackIsEmpty(void)
{
	return (top == 0);
}

bool stackIsFull(void)
{
	return (top == MAX_N);
}

bool stackPush(int value)
{
	if (stackIsFull())
	{
		printf("Stack overflow!");
		return false;
	}
	s1[top] = value;
	top++;

	return true;
}

bool stackPop(int *value)
{
	if (stackIsEmpty())
	{
		printf("Stack overflow!");
		return false;
	}
	top--; // 먼저 감소
	*value = s1[top];

	return true;
}

// using STL
stack<int> s2;
void stackSTLInit()
{
	while (!s2.empty())
	{
		s2.pop();
	}
}

int main()
{
	int T, N;

	scanf_s("%d", &T); 	// number of testcase

	for (int test_case = 1; test_case <= T; test_case++)
	{
		scanf_s("%d", &N);// number of data
		stackInit();
		stackSTLInit();
		for (int i = 0; i < N; i++)
		{
			int value;
			scanf_s("%d", &value);
			stackPush(value);
			s2.push(value);
		}

		printf("#%d \n", test_case);

		while (!stackIsEmpty())
		{
			int value;
			if (stackPop(&value))
			{
				printf("%d ", value);
			}
		}
		printf("\n");

		while (!s2.empty())
		{
			int value = s2.top(); // return top value
			s2.pop(); // delete top value
			printf("%d ", value);
		}
		printf("\n");
	}
	return 0;
}

