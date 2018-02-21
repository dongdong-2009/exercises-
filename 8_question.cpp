#include <iostream>

//��ָoffer������8������һ�������������е�һ���ڵ㣬
//�ҳ���Ӧ����������е���һ���ڵ㡣�����ĽṹΪ��������

//˼·������ı���˳��Ϊ����ң����������
//�����ǰ�ڵ���������������һ���ڵ�Ϊ������������ڵ�
//���� ��ǰ�ڵ��������������жϵ�ǰ�ڵ��Ǹ��ڵ��������
//     ����Ǹ��ڵ����ڵ㣬��ô��һ���ڵ���Ǹ��ڵ�
//     ����˵���ýڵ��Ǹ��ڵ���Һ��ӣ�һֱ�����ң�ֱ���ҵ���ǰ�ڵ��Ǹ��ڵ�����ӣ����ظø��ڵ�
typedef struct TreeNode{
	int _value;
	TreeNode* _left;
	TreeNode* _right;
	TreeNode* _parent;

	TreeNode(const int& x)
		:_value(x)
		,_left(NULL)
		,_right(NULL)
		,_parent(NULL)
	{}
}Node;

Node* FindNext(Node* node) {
	if (node == NULL)
		return NULL;

	Node *pnext = NULL;
	if (node->_right != NULL) {
    //�Ҳ�Ϊ�գ��򷵻�����������ڵ�
		Node* right = node->_right;
        while(right != NULL)
            right = right->_left;
        pnext = right;
	}
	else if (node->_parent != NULL) {

		Node *cur = node;
		Node *parent = node->_parent;
		if (cur == parent->_left) {
			pnext = parent;
		}
		else {
			//cur == parent->_right��һֱ�����ҵ���һ����ǰ�ڵ�Ϊ���ڵ����ڵ�
			//�ø��ڵ��Ϊ��һ���ڵ�
			while (parent != NULL && cur == parent->_right) {
				cur = parent;
				parent = cur->_parent;
			}
			pnext = parent;
		}
	}
	return pnext;
}


int main() {
	Node *a = new Node(1);
	Node *b = new Node(2);
	Node *c = new Node(4);
	Node *d = new Node(3);
	a->_left = b; a->_right = c;
	b->_parent = a; b->_left = d; 
	c->_parent = a; 
	d->_parent = b;
	/*   a(1)   
	  b(2)     c(4)
	d(3)            */
	Node* ret = FindNext(d);
	std::cout << "3 next node : " << ret->_value << std::endl;
	return 0;
}
