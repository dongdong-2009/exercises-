#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
using namespace std;

typedef struct TreeNode
{
	int _data;
	TreeNode* _left;
	TreeNode* _right;

	TreeNode(const int& x)
		:_data(x)
		,_left(NULL)
		,_right(NULL)
	{}
}Node;

int GetHeight(Node* root)
{
	if (root == NULL)
		return NULL;

	int leftHeight = GetHeight(root->_left);
	int rightHeight = GetHeight(root->_right);
	
	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

bool IsBalanceTree(Node* root)
{
	if (root == NULL)
		return true;

	int leftHeight = GetHeight(root->_left);
	int rightHeight= GetHeight(root->_right);

	if (abs(leftHeight > rightHeight) > 1)
		return false;
	else
		return IsBalanceTree(root->_left) && IsBalanceTree(root->_right);
}


//1、判断一个二叉树是否是平衡二叉树
//对于每一个树，左右高度差小于1
void Test1()
{
	TreeNode* root = new TreeNode(1);
	root->_left = new TreeNode(2);
	root->_left->_left = new TreeNode(3);
	root->_right = new TreeNode(4);
	//     1
	//  2    4
	//3
	bool ret = IsBalanceTree(root);
	cout << ret << endl;
}

bool Find(int arr[][4], int rows, int cols, int num)
{
	assert(arr);
	bool ret = false;
	if (rows > 0 && cols > 0)
	{
		int row = 0;
		int col = cols - 1;
		while (row < rows && col >= 0)
		{
			if (arr[row][col] == num)
			{
				ret = true;
				break;
			}
			else if (arr[row][col] > num)
				--col;
			else
				++row;
		}
	}
	return ret;
}

//二维数组中的查找
void Test2()
{
	int arr[4][4] = { {1,2,8,9},
					{2,4,9,12},
					{4,7,10,13},
					{6,8,11,15} };
	bool ret = Find(arr, 4, 4, 8);
	cout << ret << endl;
}


int main()
{
	//Test1();
	Test2();
	system("pause");
	return 0;
}