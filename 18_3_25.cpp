#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;


//����Ƕ��
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

�۲����ͼ�Σ�������һϵ�������ε��Ǻŷ���Ƕ�׶��ɡ�
���ϱߵ������У����ⷽ��ı߳�Ϊ11��

�����������Ǵӱ�׼������һ������n(1<n<100)
����������Ƕ���ŵĻ������Ǻŷ���������㷽��ı߳�Ϊn

���磺
���룺
5
���������
*****
*   *
* * *
*   *
*****

���룺6
���������
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
