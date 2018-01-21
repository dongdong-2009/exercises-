//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <string>
//#include <math.h>
//using namespace std;
//
////1/判断两个链表是否相交，若相交，求交点
////分别求出两个链表的长度，让长的先走长度差数步，然后再统一走，
////直到有相同或者为空
////
//
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
//size_t LenOfList(ListNode* list)
//{
//	if (list != NULL)
//	{
//		int count = 1;
//		ListNode* cur = list;
//		while (cur->_next != NULL)
//		{
//			++count;
//			cur = cur->_next;
//		}
//		return count;
//	}
//	return 0;
//}
//
//ListNode* IsCross(ListNode* l1, ListNode* l2)
//{
//	int len1 = LenOfList(l1);
//	int len2 = LenOfList(l2);
//	ListNode* longList = l1;
//	ListNode* shortList = l2;
//	if (len2 > len1)
//		swap(longList, shortList);
//
//	int gap = abs(len1 - len2);
//	while (gap--)
//		longList = longList->_next;
//
//	while (longList)
//	{
//		if (longList = shortList)
//			return shortList;
//		longList = longList->_next;
//		shortList = shortList->_next;
//	}
//}
//
//void Test()
//{
//	ListNode* list1 = NULL;
//	PushFront(list1, 5);
//	PushFront(list1, 4);
//	PushFront(list1, 3);
//	PushFront(list1, 2);
//	PushFront(list1, 1);
//
//	//      l1     
//	//		1 2 3 4 5
//	// 9 3 6
//	//l2
//	ListNode* list2 = list1;
//	PushFront(list1, 6);
//	PushFront(list1, 3);
//	PushFront(list1, 9);
//
//	ListNode* ret = IsCross(list1, list2);
//	cout << ret->_data << endl;
//}
//
//
//int main()
//{
//	Test();
//	system("pause");
//	return 0;
//}
