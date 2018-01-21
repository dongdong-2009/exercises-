#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

struct ListNode
{
	ListNode* _next;
	int _data;

	ListNode(const int& x)
		:_data(x)
		, _next(NULL)
	{}
};

void PushFront(ListNode*& list, const int& x)
{
	ListNode* tmp = new ListNode(x);
	tmp->_next = list;
	list = tmp;
}

void TailToHead(ListNode* head)
{
	if (head == NULL)
		return;
	
	TailToHead(head->_next);
	cout << head->_data << " ";
}


void Test1()
{
	//1、删除一个无头单链表的非尾节点
	ListNode* newList = NULL;
	PushFront(newList, 2);
	PushFront(newList, 4);
	PushFront(newList, 1);
	PushFront(newList, 3);
	PushFront(newList, 5);
	//5 3 1 4 2
	
	//删除1
	ListNode* delNode = newList->_next->_next;
	ListNode* del = delNode->_next;
	swap(delNode->_data, del->_data);
	delNode->_next = del->_next;
	delete del;
	del = NULL;

	//2、从尾到头打印单链表
	TailToHead(newList);
	cout << endl;

}

struct ComplexNode {
	int _data;
	ComplexNode* _next;
	ComplexNode* _random;

	ComplexNode(const int& x)
		:_data(x)
		,_next(NULL)
		,_random(NULL)
	{}
};

ComplexNode* Copy(ComplexNode* head)
{
	if (head == NULL)
		return NULL;

	//1、在每个不为空的节点后插入一个
	ComplexNode* cur = head;
	while (cur != NULL)
	{
		ComplexNode* newNode = new ComplexNode(cur->_data);
		ComplexNode* next = cur->_next;
		newNode->_next = next;
		cur->_next = newNode;
		cur = cur->_next->_next;
	}

	//2、使得每个新拷贝节点都赋值前一个节点的random
	cur = head;
	while (cur != NULL)
	{
		ComplexNode* copyNode = cur->_next;
		if (cur->_random != NULL)
			copyNode->_random = cur->_random->_next;

		cur = copyNode->_next;
	}

	ComplexNode* ret = head->_next;
	ComplexNode* tmp = head;
	while (tmp && tmp->_next != NULL)
	{
		tmp->_next = tmp->_next->_next;
		tmp = tmp->_next;
	}

	return ret;
}

void Test2()
{
	ComplexNode* newList = NULL;
	ComplexNode* first = new ComplexNode(2);
	ComplexNode* second = new ComplexNode(5);
	ComplexNode* third = new ComplexNode(6);

	first->_next = second;
	second->_next = third;
	first->_random = third;
	second->_random = first;
	third->_random = second;
	newList = first;

	ComplexNode* ret = Copy(newList);
}

int main()
{
	//Test1();
	Test2();
	system("pause");
	return 0;
}