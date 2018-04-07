#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

/*
A、B、C、D、E、F、G、H、I、J 共10名学生有可能参加本次计算机竞赛，也可能不参加。因为某种原因，他们是否参赛受到下列条件的约束：

   1. 如果A参加，B也参加；
   2. 如果C不参加，D也不参加；
   3. A和C中只能有一个人参加；
   4. B和D中有且仅有一个人参加；
   5. D、E、F、G、H 中至少有2人参加；
   6. C和G或者都参加，或者都不参加；
   7. C、E、G、I中至多只能2人参加   
   8. 如果E参加，那么F和G也都参加。
   9. 如果F参加，G、H就不能参加
   10. 如果I、J都不参加，H必须参加

请编程根据这些条件判断这10名同学中参赛者名单。如果有多种可能，则输出所有的可能情况。每种情况占一行。参赛同学按字母升序排列，用空格分隔。

比如：
C D G J
就是一种可能的情况。

多种情况的前后顺序不重要*/
bool join[10];

void show() {
	for (int i = 0; i < 10; ++i) {
		if (join[i])
			cout << (char)(i + 'A') << " ";
	}
	cout << endl;
}

bool Judge() {
	//1、如果A参加，B也参加
	if (join[0] == 1 && join[1] == 0)
		return false;

	//2、如果C不参加，D也不参加
	if (join[2] == 1 && join[3] == 0)
		return false;

	//3、A和C只能有一个人参加
	if (join[0] == 1 && join[2] == 1)
		return false;

	//4、B和D中有且仅有一个人参加
	if (join[1] == join[3])
		return false;

	//5、D、E、F、G、H中至少有2个参加
	int count = 0;
	for (int i = 3; i < 8; ++i) {
		if (join[i] != 0)
			++count;
	}
	if (count < 2)
		return false;

	//6、C和G或者都参加或者都不参加
	if (join[2] != join[5])
		return false;

	//7、CEGI中至多只能两人参加
	count = 0;
	for (int i = 2; i < 10; i += 2) {
		if (join[i] != 0)
			++count;
	}
	if (count > 2)
		return false;

	//8、如果E参加，那么FG也参加
	if (join[4] == 1) {
		if ((join[5] && join[6]) == 0)
			return false;
	}

	//9、如果F参加，GH就不能参加
	if (join[5] == 1) {
		if (join[6] || join[7])
			return false;
	}

	//10、如果IJ都不参加，H必须参加
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