//#//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//
////�������Ƿ�������������󻷵ĳ��ȣ��������󻻵���ڵ㣬
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
//	//���ÿ���ָ�룬����������
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
//	//retΪ���ص�������
//	ListNode* ret = IsCrile(head);
//	if (ret != NULL)
//		cout << "�����㣺" << ret->_data << endl;
//	else
//		cout << endl;
//
//	size_t count = GetCrileLen(head);
//	cout << "���� = " << count << endl;
//
//	//��ڵ�
//	ListNode* entry = GetEntry(head);
//	cout << "entry node = " << entry->_data << endl;
//}
//
//void Test2()
//{
//	//1�����һ���಻�ܱ��̳У�
//	//�����๹�캯��������������Ϊ˽�г�Ա�������޷����ʸ��๹�캯������ʵ���������޷��̳�
//
//	//2�����һ����ֻ���ڶ�/ջ�ϴ�������
//	/*ֻ���ڶ��ڴ���ʵ�������ࣺ��������������Ϊprivate��
//	��ջ�ϲ����Զ���������������ֻ���ֶ����á�Ҳ���Խ����캯������Ϊprivate��
//	��������Ҫ�ֶ�дһ������ʵ�ֶ���Ĺ��졣
//
//	ֻ����ջ�ڴ���ʵ�������ࣺ������operator new��operator delete����Ϊprivate��
//	����ʹ��new��������������ʱ���޷�����operator new��
//	delete���ٶ���Ҳ�޷�����operator delete*/
//}
//
//int main()
//{
//	Test1();
//	Test2();
//	system("pause");
//	return 0;
//}
