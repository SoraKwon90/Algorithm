#include <stdio.h>
#include <memory>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int int64;
typedef unsigned long long int uint64;

#define MAX_SIZE 100

int Ts;
int N, K;
int Ns[MAX_SIZE];
int Ks[MAX_SIZE];

vector<int> vNs;

struct Node
{
	int d;
	int k;
};

// 연산자 재정의
bool operator< (Node& node1, Node& node2) // a<b 
{
	return((node1.d + node1.k) < (node2.d + node2.k));
}

void Init()
{
	//using memeset in algorithm
	memset(Ns, 0, sizeof(int) * MAX_SIZE);
	memset(Ks, 0, sizeof(int) * MAX_SIZE);
}

template <typename T>
void MergeSort(T* arr, int s, int e)
{
	// 가장 작은 단위까지 분할
	if (s == e - 1)
		return;

	int m = (s + e) / 2;

	MergeSort(arr, s, m);
	MergeSort(arr, m, e);

	T* u = new T[e - s];
	int i = s, j = m, x = 0;

	while (i < m && j < e)
	{
		if (arr[i] < arr[j]) 
			u[x++] = arr[i++];
		/*
		u[x++] = arr[i];
		i++
		*/
		else                 
			u[x++] = arr[j++];
		/*
		u[x++] = arr[j];
		j++
		*/
	}

	// 다음비교할 배열로 이동
	while (i < m) 
		u[x++] = arr[i++];
	while (j < e) 
		u[x++] = arr[j++];

	for (int i = 0; i < e - s; i++)
		arr[s + i] = u[i];

	delete[] u;
}

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
	vector<int> answer;
	int tc = commands.size(); // number of testcase
	for (int n = 0; n < tc; n++)
	{
		int start = commands[n].at(0);
		int end = commands[n].at(1);
		int k = commands[n].at(2);
		vector<int> temp;
		for (int i = start - 1; i < end; i++)
		{
			temp.push_back(array.at(i));
		}
		sort(temp.begin(), temp.end()); //quick sort in stl
		answer.push_back(temp.at(k-1));
	}

	return answer;
}

void InitData()
{
	memset(Ns, 0, MAX_SIZE);
	vNs.clear();
}

int main()
{
	scanf_s("%d", &Ts);

	for (int t = 0; t < Ts; t++)
	{
		scanf_s("%d", &N);
		for (int i = 0; i < N; i++)
		{
			int input;
			scanf_s("%d", &input);
			Ns[i] = input;
			vNs.push_back(input);
		}

		MergeSort(Ns, 0, N); //input, start index, last index + 1^
		sort(vNs.begin(), vNs.end()); // QuickSort in algorithm (vector)
		printf("#%d\n", t + 1);
		printf("Merge Sort:");
		for (int i = 0; i < N; i++)
		{
			printf(" %d", Ns[i]);
		}
		printf("\nQuick Sort:");
		for (int i = 0; i < N; i++)
		{
			printf(" %d", vNs.at(i));
		}
		printf("\n");
		InitData();
	}
}
