
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
		//ͷѡȡ��ɣ���ʼ�ϲ�

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
		//l1,l2��һ��Ϊ��
		if (l1 != NULL)
			cur->_next = l1;
		if (l2 != NULL)
			cur->_next = l2;

		return head;
	}
}

void Test1()
{
	//�ϲ��������������ϲ�����Ȼ����
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

//����1����Ŀ�����
int Add(const int n)
{
	//��Ŀ�����
	return n > 0 ? (n + Add(n - 1)) : 0;
}

//����2��������ľ�̬��Ա������new[]
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

//��Ŀ2��ʵ��1+������+n����ʹ�ó˳���for,while,if,else�����ؼ���
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