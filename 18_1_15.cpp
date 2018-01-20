
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

struct ListNode {
	int _data;
	ListNode* _next;

	ListNode(const int& x)
		:_data(x)
		,_next(NULL)
	{}
};

ListNode* Merge(ListNode* l1, ListNode* l2)
{
	if (l1 == NULL && l2 == NULL)
		return NULL;

	if (l1 != NULL && l2 == NULL)
		return l1;
	else if (l1 == NULL && l2 != NULL)
		return l1;
	else 
	{
		ListNode* cur = NULL;
		ListNode* head = NULL;

		if (l1->_data < l2->_data)
		{
			cur = l1;
			l1 = l1->_next;
		}
		else
		{
			cur = l2;
			l2 = l2->_next;
		}
		head = cur;
		//头选取完成，开始合并

		while (l1 != NULL && l2 != NULL)
		{
			if (l1->_data < l2->_data)
			{
				cur->_next = l1;
				l1 = l1->_next;
			}
			else
			{
				cur->_next = l2;
				l2 = l2->_next;
			}
			cur = cur->_next;
		}
		//l1,l2有一个为空
		if (l1 != NULL)
			cur->_next = l1;
		if (l2 != NULL)
			cur->_next = l2;

		return head;
	}
}

void Test1()
{
	//合并两个有序单链表，合并后依然有序
	ListNode* l1 = new ListNode(2);
	l1->_next = new ListNode(5);

	ListNode* l2 = new ListNode(3);
	l2->_next = new ListNode(7);

	ListNode* ret = Merge(l1, l2);
	for (int i = 0; i < 4; i++)
	{
		cout << ret->_data << " ";
		ret = ret->_next;
	}

	cout << endl;
}

//方法1，三目运算符
int Add(const int n)
{
	//三目运算符
	return n > 0 ? (n + Add(n - 1)) : 0;
}

//方法2，利用类的静态成员变量和new[]
class Sum {
public:
	Sum()
	{
		_num++;
		_n += _num;
	}

	int GetNum()
	{
		return _n;
	}
private:
	static int _num;
	static int _n;
};

int Sum::_num = 0;
int Sum::_n = 0;

//题目2：实现1+。。。+n；不使用乘除，for,while,if,else。。关键字
void Test2()
{
	int ret = Add(10);
	cout <<"1+2+...+10 = "<< ret << endl;
	Sum* res = new Sum[10];
	cout<<res->GetNum();
}

int main()
{
	//Test1();
	Test2();
	system("pause");
	return 0;
}