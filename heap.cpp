#include <stdio.h>
#include <queue>
using namespace std;
#define MAX_SIZE 100


int minHeap[MAX_SIZE];
int maxHeap[MAX_SIZE];
int minHeapSize = 0;
int maxHeapSize = 0;

void heapInit(void)
{
	minHeapSize = 0;
	maxHeapSize = 0;
}

int minHeapPush(int value) 
{
	if (minHeapSize + 1 > MAX_SIZE)
	{
		printf("queue is full!");
		return 0;
	}

	minHeap[minHeapSize] = value;
	int current = minHeapSize;

	// check parent node = (current-1)/2 
	while (current > 0 && minHeap[current] < minHeap[(current - 1) / 2])
	{
		int temp = minHeap[(current - 1) / 2];
		minHeap[(current - 1) / 2] = minHeap[current];
		minHeap[current] = temp;
		current = (current - 1) / 2; // current index <- parent index
	}

	minHeapSize = minHeapSize + 1;
	return 1;
}

int maxHeapPush(int value)
{
	if (maxHeapSize + 1 > MAX_SIZE)
	{
		printf("queue is full");
		return 0;
	}

	maxHeap[maxHeapSize] = value;
	int current = maxHeapSize;

	while (current > 0 && maxHeap[current] > maxHeap[(current - 1) / 2])
	{
		int temp = maxHeap[(current - 1) / 2];
		maxHeap[(current - 1) / 2] = maxHeap[current];
		maxHeap[current] = temp;
		current = (current - 1) / 2;
	}

	maxHeapSize = maxHeapSize + 1;
	return 1;
}

int minHeapPop(int *value)
{
	if (maxHeapSize <= 0)
	{
		return -1;
	}

	*value = minHeap[0];
	minHeapSize = minHeapSize - 1;

	minHeap[0] = minHeap[minHeapSize];

	int current = 0;
	// check both child (current * 2 + 1, current * 2 + 2)
	while (current * 2 + 1 < minHeapSize)
	{
		int child;
		if (current * 2 + 2 == minHeapSize)
		{
			child = current * 2 + 1;
		}
		else
		{
			//child 2개 비교해서 min값으로
			child = minHeap[current * 2 + 1] < minHeap[current * 2 + 2] ? current * 2 + 1 : current * 2 + 2;
		}

		if (minHeap[current] < minHeap[child])
		{
			break;
		}

		int temp = minHeap[current];
		minHeap[current] = minHeap[child];
		minHeap[child] = temp;

		current = child;
	}
	return 1;
}

int maxHeapPop(int *value)
{
	if (maxHeapSize <= 0)
	{
		return -1;
	}

	*value = maxHeap[0];
	maxHeapSize = maxHeapSize - 1;

	maxHeap[0] = maxHeap[maxHeapSize];

	int current = 0;
	// check both child (current * 2 + 1, current * 2 + 2)
	while (current * 2 + 1 < maxHeapSize)
	{
		int child;
		if (current * 2 + 2 == maxHeapSize)
		{
			child = current * 2 + 1;
		}
		else
		{
			//child 2개 비교해서 min값으로
			child = maxHeap[current * 2 + 1] > maxHeap[current * 2 + 2] ? current * 2 + 1 : current * 2 + 2;
		}

		if (maxHeap[current] > maxHeap[child])
		{
			break;
		}

		int temp = maxHeap[current];
		maxHeap[current] = maxHeap[child];
		maxHeap[child] = temp;

		current = child;
	}
	return 1;
}

// using priority queue STL
priority_queue<int> minHip;
priority_queue<int> maxHip;

int main()
{
	int T, N;

	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++)
	{
		scanf("%d", &N);

		heapInit();

		for (int i = 0; i < N; i++)
		{
			int value;
			scanf("%d", &value);
			minHeapPush(value);
			maxHeapPush(value);
		}

		printf("#%d\n", test_case);

		for (int i = 0; i < N; i++)
		{
			int value;
			minHeapPop(&value);
			printf("%d ", value);
		}
		printf("\n");

		for (int i = 0; i < N; i++)
		{
 			int value2;
			maxHeapPop(&value2);
			printf("%d ", value2);
		}
		printf("\n");
	}
	return 0;
}