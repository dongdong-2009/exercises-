#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <queue>
#include <string>
using namespace std;

//给定一个整数N，求N的阶乘末尾0的个数
//思路：问题转化为查找因子2、5的出现次数，然后取二者中最小值
//由于因子2出现的频率高于因子5，最终问题变成求解因子5的出现次数。
//

size_t GetZeroCount(int num)
{
	size_t count = 0;
	int tmp;
	for (int i = 5; i <= num; i = i + 5) 
	{
		tmp = i;
		while (tmp % 5 == 0) 
		{
			count++;
			tmp /= 5;
		}
	}
	return count;

}

void Test2()
{
	int num = 0;
	cin >> num;
	size_t count = GetZeroCount(num);
	cout << count << endl;
}


struct TreeNode
{
	int _data;
	TreeNode* _left;
	TreeNode* _right;

	TreeNode(const int& x)
		:_data(x)
		,_left(NULL)
		,_right(NULL)
	{}
};


void LevelOrder(TreeNode* root)
{
	typedef TreeNode Node;
	if (root == NULL)
		return;
	queue<Node*> q;
	q.push(root);
	while (!q.empty())
	{
		Node* top = q.front();
		q.pop();
		cout << top->_data << endl;

		if (top->_left != NULL)
			q.push(top->_left);
		if (top->_right != NULL)
			q.push(top->_right);
	}
}

//实现二叉树的层序遍历
void Test1()
{
	TreeNode* root = new TreeNode(1);
	root->_left = new TreeNode(2);
	root->_left->_left = new TreeNode(3);
	root->_right = new TreeNode(4);
	//     1
	//  2    4
	//3
	LevelOrder(root);
}



int main()
{
	Test2();
	system("pause");
	return 0;
}