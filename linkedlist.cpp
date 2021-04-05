#include <stdio.h>

#define MAX_NODE 100

class Node
{
public:
	int data;
	Node* prev;
	Node* next;

	Node() {
		prev = next = NULL;
		data = 0;
	}

	void DeleteSelf()
	{
		prev->next = next;
		next->prev = prev;
		delete this;
	}
};

class DoubleLinkedList
{
public:
	int size;
	Node* head;
	Node* tail;

	DoubleLinkedList() {
		this->size = 0;
		this->head = NULL;
		this->tail = NULL;
	}

	/*Linkedlist의 끝에 노드 추가*/
	void AddBack(int value)
	{
		Node *newNode = new Node();
		newNode->data = value;

		if (this->size == 0) //list is empty
			head = tail = newNode;
		else
		{
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
		this->size++;
	}

	/*Linkedlist의 앞에 노드 추가*/
	void AddFront(int value)
	{
		Node *newNode = new Node();
		newNode->data = value;

		if (this->size == 0) //list is empty
			head = tail = newNode;
		else
		{
			head->prev = newNode;
			newNode->next = head;
			head = newNode;
		}

		this->size++;
	}

	/*Linkedlist의 특정 postion에 노드 추가*/
	void Add(int position, int value)
	{
		if (this->size == 0 || position > this->size || position < 1)
			return;

		Node* newNode = new Node();
		Node* cur = head; // 비교하기위한 변수 
		int i = 0;
		while (i < position - 1)
		{
			cur = cur->next;
			i++;
		}
		newNode->prev = cur;
		newNode->next = cur->next;
		cur->next = newNode;
		cur->prev = newNode->prev;
	}

	void DeleteFront()
	{
		if (tail->prev == head)
			return;
		head->next->DeleteSelf();
		this->size--;
	}

	void DeleteEnd()
	{
		if (tail->prev == head)
			return;
		tail->prev->DeleteSelf();
		this->size--;
	}

	void Delete(int position)
	{
		if (this->size == 0 || position > this->size || position < 1)
			return;

		if (position == 1)
		{
			// if position is first
			Node* temp = head;
			head = head->next;
			head->prev = NULL;
			delete temp;
		}
		else if (position == this->size)
		{
			// if position is last
			Node* temp = tail;
			tail = tail->prev;
			tail->next = NULL;
			delete temp;
		}
		else
		{
			Node* cur = head;
			for (int i = 0; i < position - 1; i++)
			{
				cur = cur->next;
			}
			cur->DeleteSelf();
		}
		this->size--;
	}

	void ClearList()
	{
		Node* deleteNode;
		//delete all node from head to tail
		for (int i = 0; i < this->size - 1; i++)
		{
			deleteNode = head;
			if (head->next == NULL)
				break;
			head = head->next;
			delete deleteNode;
		}

		this->size = 0;
		head = tail = NULL;
	}

	void PrintAll()
	{
		Node *cur = head;
		if (head->next == NULL)
			return;
		printf("Data: ");
		while (cur != tail->next)
		{
			printf("%d ", cur->data);
			cur = cur->next;
		}
	}
};


void initNode(Node* node)
{
	node->data = 0;
	node->prev = node;
	node->next = node;
}

int main(int argc, char* argv[])
{

	int T, N;

	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; ++test_case)
	{
		DoubleLinkedList list;
		Node* node;
		int i;

		scanf("%d", &N);
		for (i = 0; i < N; i++)
		{
			int data;
			scanf("%d", &data);
			list.AddBack(data);
		}

		list.AddFront(4);
		//list.Delete(5);
		list.PrintAll();
	}
	return 0;
}