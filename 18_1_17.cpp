//#//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//
////求链表是否带环，若带环求环的长度，若带环求换的入口点，
//struct ListNode
//{
//	ListNode* _next;
//	int _data;
//
//	ListNode(const int& x)
//		:_data(x)
//		, _next(NULL)
//	{}
//};
//
//void PushFront(ListNode*& list, const int& x)
//{
//	ListNode* tmp = new ListNode(x);
//	tmp->_next = list;
//	list = tmp;
//}
//
//ListNode* IsCrile(ListNode* l)
//{
//	//利用快慢指针，返回相遇点
//	ListNode* quick = l;
//	ListNode* slow = l;
//	//5 4 3 2 1->3
//
//	while (quick->_next != NULL && quick != NULL)
//	{
//		quick = quick->_next->_next;
//		slow = slow->_next;
//		if (quick == slow)
//			return slow;
//	}
//	return NULL;
//}
//
//size_t GetCrileLen(ListNode* list)
//{
//	ListNode* meet = IsCrile(list);
//
//	if (meet != NULL)
//	{
//		size_t count = 1;
//		ListNode* cur = meet->_next;
//		while (cur != meet)
//		{
//			cur = cur->_next;
//			count++;
//		}
//		return count;
//	}
//	return 0;
//}
//
//ListNode* GetEntry(ListNode* list)
//{
//	ListNode* meet = IsCrile(list);
//	if (meet != NULL)
//	{
//		ListNode* head = list;
//		while (head != meet)
//		{
//			head = head->_next;
//			meet = meet->_next;
//		}
//		return head;
//	}
//	return NULL;
//}
//
//void Test1()
//{
//	ListNode* head = new ListNode(1);
//	PushFront(head, 2);
//	PushFront(head, 3);
//	PushFront(head, 4);
//	PushFront(head, 5);
//
//	ListNode* cur = head;
//	for (int i = 0; i < 5; i++)
//	{
//		cout << cur->_data << " ";
//		if (cur->_next != NULL)
//			cur = cur->_next;
//	}
//	cur->_next = head->_next->_next;
//	//5 4 3 2 1->3
//
//	cout << endl;
//
//	//ret为返回的相遇点
//	ListNode* ret = IsCrile(head);
//	if (ret != NULL)
//		cout << "相遇点：" << ret->_data << endl;
//	else
//		cout << endl;
//
//	size_t count = GetCrileLen(head);
//	cout << "环长 = " << count << endl;
//
//	//入口点
//	ListNode* entry = GetEntry(head);
//	cout << "entry node = " << entry->_data << endl;
//}
//
//void Test2()
//{
//	//1、设计一个类不能被继承：
//	//将该类构造函数和析构函数设为私有成员，子类无法访问父类构造函数进行实例化所以无法继承
//
//	//2、设计一个类只能在堆/栈上创建对象
//	/*只能在堆内存上实例化的类：将析构函数定义为private，
//	在栈上不能自动调用析构函数，只能手动调用。也可以将构造函数定义为private，
//	但这样需要手动写一个函数实现对象的构造。
//
//	只能在栈内存上实例化的类：将函数operator new和operator delete定义为private，
//	这样使用new操作符创建对象时候，无法调用operator new，
//	delete销毁对象也无法调用operator delete*/
//}
//
//int main()
//{
//	Test1();
//	Test2();
//	system("pause");
//	return 0;
//}
