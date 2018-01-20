#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

struct ListNode
{
	ListNode* _next;
	int _data;

	ListNode(const int& x)
		:_data(x)
		,_next(NULL)
	{}
};

void Reverse(ListNode*& l1)
{
	if (l1 == NULL || l1->_next == NULL)
		return;

	//不断头插节点
	ListNode* NewList = NULL;
	ListNode* cur = l1;
	ListNode* tmp = NULL;
	while (cur != NULL)
	{
		tmp = cur;
		cur = cur->_next;
		tmp->_next = NewList;
		NewList = tmp;
	}
	l1 = NewList;
}

void PushFront(ListNode*& list,const int& x)
{
	ListNode* tmp = new ListNode(x);
	tmp->_next = list;
	list = tmp;
}

ListNode* BackN(ListNode* list, size_t n)
{
	// 5 4 3 2 
	ListNode* quick = list;
	ListNode* slow = list;
	
	while (n--)
		quick = quick->_next;

	while (quick != NULL)
	{
		quick = quick->_next;
		slow = slow->_next;
	}
	return slow;
}

void Test1()
{
	//翻转链表以及找倒数第K个节点
	ListNode* l1 = new ListNode(2);
	l1->_next = new ListNode(3);

	//Reverse(l1);
	PushFront(l1, 4);
	PushFront(l1, 5);

	//for (int i = 0; i < 4; i++) {
	//	cout << l1->_data << " ";
	//	l1 = l1->_next;
	//}


	// 5 4 2 3
	ListNode* ret = BackN(l1, 2);
	cout << ret->_data << endl;
}

//int Add(int num1, int num2)
//{
//	if (num2 == 0)
//		return num1;
//
//	int sum = num1 ^ num2;	//只相加不考虑进位
//	int up = (num1 & num2) << 1;//只计算进位
//	return Add(sum, up);
//}

int Add(int num1, int num2)
{
	int sum = num1 ^ num2;
	int up = (num1 & num2);
	while (up != 0)
	{
		int a = sum;
		int b = up << 1;
		int sum = a^b;
		int up = a & b;
	}
	return sum;
}
void Test2()
{
	//不使用+-*/，实现一个Add函数
	int ret = Add(1, 2);
	cout << ret << endl;
}

int main()
{
	//Test1();
	Test2();
	system("pause");
	return 0;
}
