#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stack>
#include <vector>
#include <math.h>
using namespace std;


int GetOneCount(int& n)
{
	size_t count = 0;
	for (size_t i = 0; i < 32; i++)
	{
		if (n >> i & 1 == 1)
			count++;
	}
	return count;
}

//计算一个整数二进制位中1的个数（能正确求正数和负数中的个数）
void Test2()
{
	int num = 0;
	cin >> num;
	int count = GetOneCount(num);
	cout << count;
}


//判断元素入栈、出栈顺序的合法性
//思路：利用一个临时栈来模拟出栈入栈

bool IsLegal(vector<int>& Input, vector<int>& Output)
{
	//如果两个序列长度不同则直接返回
	if (Input.size() != Output.size())
		return false;

	stack<int> s;
	size_t OutputIndex = 0;

	for (size_t i = 0; i < Input.size(); ++i)
	{
		s.push(Input[i]);
		while (s.size()>0 && s.top() == Output[OutputIndex]	)
		{
			s.pop();
			OutputIndex++;
		}
	}

	return s.empty() ? true : false;
}

void Test1()
{
	vector<int> Input;
	vector<int> Output;
	Input.push_back(1);
	Input.push_back(2);
	Input.push_back(3);
	Input.push_back(4);
	Input.push_back(5);
	Output.push_back(4);
	Output.push_back(5);
	Output.push_back(3);
	Output.push_back(2);
	Output.push_back(1);
	bool ret = IsLegal(Input, Output);
	cout << ret << endl;
}



int main()
{
	//Test1();
	Test2();
	system("pause");
	return 0;
}