#include <stdio.h>
#include <algorithm> 
#include <vector>
#include <stack>
#include <queue>
using namespace std;

#define MAX_SIZE 100

int Ts;    
int M;    // # of element in array
int N;    // # of numbers to search
int arr[MAX_SIZE];

/*Binary Search*/
void binarySearch(int* arr, int low, int high, int target)
{
	int mid;
	if (low > high)
	{
		printf("-1 ");
		return;
	}

	mid = (low + high) / 2;

	if (target < arr[mid])
	{
		binarySearch(arr, low, mid - 1, target);
	}
	else if (arr[mid] < target)
	{
		binarySearch(arr, mid + 1, high, target);
	}
	else
	{
		printf("%d ", mid); // index of target value
		return;
	}
}

/*DFS*/
int S; //start node
vector<int> v[MAX_SIZE];
bool isVisited[MAX_SIZE] = {false,}; // visted 여부를 체크하는 변수 필요

void DFS(int V) { 
	if (isVisited[V]) return;
	isVisited[V] = true; 
	printf("%d ", V); 

	for (int i=0; i<v[V].size(); i++)
	{ 
		// 인접 노드끝까지 탐색
		int next = v[V][i]; 
		DFS(next);
	} 
}

stack<int> st;
void DFS2(int V) {
	st.push(V); // 루트 노드 삽입 
	while (!st.empty()) 
	{ 
		int cur = st.top(); 
		st.pop(); 
		if (isVisited[cur]) { continue; } 
		isVisited[cur] = true; 
		printf("%d ", cur); 
		
		// 숫자가 작은 노드 먼저 방문하기 위해 reverse 
		for (int i= v[cur].size()-1; i>=0; i--)
		{ 
			int next = v[cur][i];
			st.push(next); 
		} 
	} 
}

/*BFS*/
queue<int> que; 

void BFS(int V) 
{
	que.push(V); 
	while (!que.empty()) 
	{ 
		int cur = que.front(); 
		que.pop(); 
		if (isVisited[cur]) 
			continue; 
		isVisited[cur] = true; 
		printf("%d ", cur); 
		for (int i=0; i<v[cur].size(); i++)
		{ 
			// 인접 노드모두 순회
			int next = v[cur][i];
			que.push(next); 
		} 
	} 
}

int main(void)
{
	int targetValue;
	scanf("%d", &Ts);

	/*Binary Search
	for (int t = 1; t <= Ts; t++)
	{
		printf("#%d \n", t);
		scanf("%d", &N); // input size 

		for (int i = 0; i < N; i++)
		{
			scanf("%d", &arr[i]); // input value
		}
		
		scanf("%d", &targetValue); // 찾을숫자
		binarySearch(arr, 0, N-1, targetValue);
		printf("\n");
	}
	*/

	/*DFS, BFS*/
	for (int t = 1; t <= Ts; t++)
	{
		printf("#%d input number of node, edge, start node\n", t);
		scanf("%d %d %d", &N, &M, &S); // input number of node N, edge M, start node S

		for (int i = 0; i < M; i++)
		{
			int s, e;
			scanf("%d" "%d", &s, &e); // input value
			v[s].push_back(e); // make edge
			v[e].push_back(s);
		}

		fill_n(isVisited, MAX_SIZE, false);
		printf("DFS: ");
		//DFS(S);
		DFS2(S);
		printf("\n");
		printf("BFS: ");
		fill_n(isVisited, MAX_SIZE, false);
		BFS(S);
		printf("\n");
	}

	/*DFS*/
	return 0;
}
