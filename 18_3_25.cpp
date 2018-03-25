#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;


//回型嵌套
/*	
***********
*         *
* ******* *
* *     * *
* * *** * *
* * * * * *
* * *** * *
* *     * *
* ******* *
*         *
***********

观察这个图形，它是由一系列正方形的星号方框嵌套而成。
在上边的例子中，最外方框的边长为11。

本题的任务就是从标准输入获得一个整数n(1<n<100)
程序则生成嵌套着的回字型星号方框。其最外层方框的边长为n

例如：
输入：
5
程序输出：
*****
*   *
* * *
*   *
*****

输入：6
程序输出：
******
*    *
* ** *
* ** *
*    *
******


*/

void Print(vector<vector<char>>& arr, int left, int right) {
	if (right < 3)
		return;
	int row = left;
	int col = left;
	while (col < right)
	{
		arr[row][col] = '*';
		arr[right - 1][col] = '*';
		++col;
	}
	col = left;
	while (row < right) {
		arr[row][col] = '*';
		arr[row][right - 1] = '*';
		++row;
	}

	Print(arr, left + 2, right - 2);
}


int main() {
	int n = 0;
	cin >> n;
	vector<vector<char>>arr(n);
	for (int i = 0; i < n; ++i) {
		arr[i].resize(n);
	}

	Print(arr, 0, n);

	for (int row = 0; row < n; ++row) {
		for (int col = 0; col < n; ++col) {
			cout << arr[row][col];
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
