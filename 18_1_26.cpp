#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

//求出一个数组中出现次数大于数组元素个数一半的元素
class Solution {
public:
	int GetOverHalfElement(std::vector<int> a, size_t size)
	{
		std::map<int, int> mp;
		bool flag = false;
		size_t i = 0;
		for (; i < a.size(); ++i) {
			if (++mp[a[i]] >= (a.size() >> 1)) {
				flag = true;
				break;
			}
		}
		return flag ? a[i] : -1;
	}
};


void Test2()
{
	//vector<int> a = { 2,3,2,2,2,2,2,5,4,1,2,3 };
	vector<int> a = {1,2,3,2,2};
	Solution s1;
	int ret = s1.GetOverHalfElement(a, sizeof(a) / sizeof(a[0]));

	cout << "超过一半的数字是：" << ret << endl;


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

typedef TreeNode Node;


void GetLeafSize(Node* root, size_t& size)
{
	if (root == NULL)
		return;

	if (root->_left == NULL && root->_right == NULL)
		++size;

	GetLeafSize(root->_left, size);
	GetLeafSize(root->_right, size);
}


size_t GetKSize(Node* root, size_t k)
{
	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	return GetKSize(root->_left, k-1) + GetKSize(root->_right, k-1);
}

//1、实现二叉树的叶子节点个数以及第k层的节点个数
void Test1()
{
	TreeNode* root = new TreeNode(1);
	root->_left = new TreeNode(2);
	root->_left->_left = new TreeNode(3);
	root->_right = new TreeNode(4);
	//     1
	//  2    4
	//3
	size_t size = 0;
	GetLeafSize(root,size);
	cout << "LeafSize: " << size << endl;
	size = GetKSize(root, 2);
	cout << "第二层节点个数为：" << size << endl;
}



int main()
{
	Test2();
	//Test1();
	system("pause");
	return 0;
}