#define _CRT_SECURE_NO_WARNINGS 1
#include <stack>
#include <iostream>
using namespace std;

class my_stack
{
protected:
	stack<int> push_stack;
	stack<int> min_stack;

public:
	my_stack()
	{}

	void Push(const int& x)
	{
		push_stack.push(x);
		if (min_stack.size() > 0)
		{
			if (x < min_stack.top())
				min_stack.push(x);
			else
				min_stack.push(min_stack.top());
		}
		else
		{
			min_stack.push(x);
		}
		
	}

	void Pop()
	{
		push_stack.pop();
		min_stack.pop();
	}

	int& Top()
	{
		return min_stack.top();
	}

};

//实现一个栈，push,pop,MIn时间复杂度为O(1)
void Test1()
{
	my_stack s1;
	s1.Push(2);
	s1.Push(1);
	s1.Push(3);
	s1.Pop();
}

char GetFirstTwice(const char* str)
{
	char buf[256] = { 0 };
	const char* cur = str;
	while (*cur != '\0')
	{
		buf[*cur]++;
		if (buf[*cur] == 2)
			break;
		cur++;
	}
	if (*cur == '\0')
		return NULL;
	else
		return *cur;
}

//查找一个字符串中第一个只出现两次的字符
void Test2()
{
	char* str = "abcdefabc";
	char ret = GetFirstTwice(str);
	cout << ret << endl;
}


int main()
{
	//Test1();
	Test2();
	system("pause");
	return 0;
}