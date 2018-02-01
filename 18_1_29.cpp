#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
//struct TreeNode
//{
//	int _data;
//	TreeNode* _left;
//	TreeNode* _right;
//
//	TreeNode(const int& x)
//		:_data(x)
//		,_left(NULL)
//		,_right(NULL)
//	{}
//};
//
//typedef TreeNode Node;
//
//size_t GetHeight(Node* root)
//{
//	if (root == NULL)
//		return 0;
//
//	int leftHeight = GetHeight(root->_left);
//	int rightHeight = GetHeight(root->_right);
//
//	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
//}
//
//void Destroy(Node*& root)
//{
//	后序遍历删除
//	if (root == NULL)
//		return;
//
//	Destroy(root->_left);
//	Destroy(root->_right);
//	delete root;
//}
//
//求二叉树的高度/销毁一个二叉树
//void Test1()
//{
//	TreeNode* root = new TreeNode(1);
//	root->_left = new TreeNode(2);
//	root->_left->_left = new TreeNode(3);
//	root->_right = new TreeNode(4);
//	     1
//	  2    4
//	3
//	size_t Height = GetHeight(root);
//	std::cout << "Height = " << Height << std::endl;
//	Destroy(root);
//}

int main()
{
//	Test1();
	system("pause");
	return 0;
}