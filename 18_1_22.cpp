#define _CRT_SECURE_NO_WARNINGS 1
#include <stack>
#include <string>
#include <vector>
#include <iostream>
#include <assert.h>
using namespace std;

//1、使用两个栈实现一个队列
template<class T>
class Queue
{
public:
	void Push(const T& x)
	{
		_s1.push(x);
	}

	void Pop()
	{
		if (_s2.size() == 0)
		{
			while (!_s1.empty())
			{
				_s2.push(_s1.top());
				_s1.pop();
			}
		}
		_s2.pop();
	}

	const T& front()
	{
		assert(!(_s1.empty() && _s2.empty()));
		while (!_s1.empty())
		{
			_s2.push(_s1.top());
			_s1.pop();
		}
		return _s2.top();
	}

	bool Empty()
	{
		return _s1.empty() && _s2.empty();
	}

	size_t Size()
	{
		return _s1.size() + _s2.size();
	}

protected:
	stack<T> _s1;
	stack<T> _s2; //用来删除
};

void TestQueue()
{
	Queue<int> q;
	q.Push(2);
	//q.Push(4);
	//q.Push(5);
	q.Pop();
	cout << q.front() << endl;
}


//2、替换字符串中的空格为$$$,要求时间复杂度为O(N)
//例如："talk is cheap show me the code"
//"talk$$$is$$$cheap$$$show$$$me$$$the$$$code"


string Replace(string& s)
{
	string tmp;
	for (string::iterator it = s.begin(); it != s.end(); ++it)
	{
		if (*it == ' ')
		{
			int count = 3;
			while (count--)
			{
				tmp.push_back('$');
			}
		}
		else
			tmp.push_back(*it);
	}
	return tmp;
}

char* replace(char* str, size_t n)
{
	size_t count = 0;
	for (size_t i = 0; i < n; i++)
	{
		if (str[i] == ' ')
			count++;
	}

	size_t newCount = n + count*3-count;
	char* tmp = new char[newCount];
	newCount--; //调整到下标
	tmp[newCount--] = '\0';
	for (int i = n-2; i >= 0; --i)
	{
		if (str[i] == ' ')
		{
			int count = 3;
			while (count--)
				tmp[newCount--] = '$';
		}
		else
		{
			tmp[newCount--] = str[i];
		}
	}
	return tmp;
}

void TestReplace()
{
	//string s1("talk is cheap");
	//string ret = Replace(s1);
	//printf("%s\n", ret.c_str());
	char arr[] = "talk is cheap show me the code";
	char* tmp = replace(arr,sizeof(arr)/sizeof(arr[0]));
	printf("%s\n", tmp);

}

int main()
{
	//TestQueue();
	TestReplace();
	system("pause");
	return 0;
}