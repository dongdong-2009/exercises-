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

//����һ������������λ��1�ĸ���������ȷ�������͸����еĸ�����
void Test2()
{
	int num = 0;
	cin >> num;
	int count = GetOneCount(num);
	cout << count;
}


//�ж�Ԫ����ջ����ջ˳��ĺϷ���
//˼·������һ����ʱջ��ģ���ջ��ջ

bool IsLegal(vector<int>& Input, vector<int>& Output)
{
	//����������г��Ȳ�ͬ��ֱ�ӷ���
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