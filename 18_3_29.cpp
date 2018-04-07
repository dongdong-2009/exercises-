#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

/*
A��B��C��D��E��F��G��H��I��J ��10��ѧ���п��ܲμӱ��μ����������Ҳ���ܲ��μӡ���Ϊĳ��ԭ�������Ƿ�����ܵ�����������Լ����

   1. ���A�μӣ�BҲ�μӣ�
   2. ���C���μӣ�DҲ���μӣ�
   3. A��C��ֻ����һ���˲μӣ�
   4. B��D�����ҽ���һ���˲μӣ�
   5. D��E��F��G��H ��������2�˲μӣ�
   6. C��G���߶��μӣ����߶����μӣ�
   7. C��E��G��I������ֻ��2�˲μ�   
   8. ���E�μӣ���ôF��GҲ���μӡ�
   9. ���F�μӣ�G��H�Ͳ��ܲμ�
   10. ���I��J�����μӣ�H����μ�

���̸�����Щ�����ж���10��ͬѧ�в���������������ж��ֿ��ܣ���������еĿ��������ÿ�����ռһ�С�����ͬѧ����ĸ�������У��ÿո�ָ���

���磺
C D G J
����һ�ֿ��ܵ������

���������ǰ��˳����Ҫ*/
bool join[10];

void show() {
	for (int i = 0; i < 10; ++i) {
		if (join[i])
			cout << (char)(i + 'A') << " ";
	}
	cout << endl;
}

bool Judge() {
	//1�����A�μӣ�BҲ�μ�
	if (join[0] == 1 && join[1] == 0)
		return false;

	//2�����C���μӣ�DҲ���μ�
	if (join[2] == 1 && join[3] == 0)
		return false;

	//3��A��Cֻ����һ���˲μ�
	if (join[0] == 1 && join[2] == 1)
		return false;

	//4��B��D�����ҽ���һ���˲μ�
	if (join[1] == join[3])
		return false;

	//5��D��E��F��G��H��������2���μ�
	int count = 0;
	for (int i = 3; i < 8; ++i) {
		if (join[i] != 0)
			++count;
	}
	if (count < 2)
		return false;

	//6��C��G���߶��μӻ��߶����μ�
	if (join[2] != join[5])
		return false;

	//7��CEGI������ֻ�����˲μ�
	count = 0;
	for (int i = 2; i < 10; i += 2) {
		if (join[i] != 0)
			++count;
	}
	if (count > 2)
		return false;

	//8�����E�μӣ���ôFGҲ�μ�
	if (join[4] == 1) {
		if ((join[5] && join[6]) == 0)
			return false;
	}

	//9�����F�μӣ�GH�Ͳ��ܲμ�
	if (join[5] == 1) {
		if (join[6] || join[7])
			return false;
	}

	//10�����IJ�����μӣ�H����μ�
	if (!join[8] && !join[9]) {
		if (join[7] == 0) {
			return false;
		}
	}

	return true;
}

void search(int pos) {
	if (pos == 10) {
		if (Judge())
			show();
		return;
	}
	for (int i = 0; i <= 1; ++i) {
		join[pos] = i;
		search(pos + 1);
	}
}


int main() {
	memset(join, false, sizeof(join));
	search(0);
	system("pause");
	return 0;
}