#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

//[begin, end)
//考虑总单词数！！！
int worker(char *text, int begin_offset, int end_offset, bool& flag) {
	assert(begin_offset < end_offset);

	int count = 0;
	//统计当前区间内单词个数
	for (int i = begin_offset; i < end_offset; ++i) {
		if (text[i] != ' ') {
			++count;
			while (text[i] != ' ' && text[i] != '\0') {
				++i;
			}
		}
	}
	
	//满足条件说明当前区间和上一个区间有连续的字母
	if (flag == true && count > 0)
		--count;

	//如果当前区间最后一个字符不为空格 置flag
	if (text[end_offset - 1] != ' ')
		flag = true;

	return count;
}

int master(char *text, int size, int n) {
	if (NULL == text || size <= 0 || n <= 0)
		return 0;

	//分配任务
	vector<int> len(n);
	int avg = size / n;
	for (int index = 0; index < n; ++index) {
		len[index] = avg;
	}

	int left = size - n * avg;
	int index = 0;
	while (left--) {
		len[index] += 1;
		++index;
	}

	//开始干活
	int begin_offset = 0;
	int end_offset = 0;
	int count = 0;
	bool flag = false; //flag为1表示末尾最后一个不是空格
	for (int i = 0; i < n; ++i) {
		end_offset += len[i];
		count += worker(text, begin_offset, end_offset, flag);
		begin_offset = len[i];
	}
	return count;
}


int main() {
	char text[] = "bb aaa    jjj";
	int ret = master(text, strlen(text), 1);
	cout << ret << endl;
	system("pause");
	return 0;
}
