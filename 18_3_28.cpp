#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

/*有一个文本文件，每行记录了若干个单词（请注意：每个单词之间由若干个空格分隔），现
在需要统计这个文本文件的总单词数，假设 master 把这个文件按字节大小等分成 n 份，然
后分给 n 个 worker 并行运算*/

//[begin, end)
int worker(char *text, int begin_offset, int end_offset) {
	assert(begin_offset < end_offset);

	int count = 0;
	for (int i = begin_offset; i < end_offset; ++i) {
		if (text[i] != ' ')
			++count;
	}
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
	for (int i = 0; i < n; ++i) {
		end_offset += len[i];
		count += worker(text, begin_offset, end_offset);
		begin_offset = len[i];
	}
	return count;
}


int main() {
	char text[] = "hello world";
	int ret = master(text, strlen(text), 2);
	cout << ret << endl;
	system("pause");
	return 0;
}