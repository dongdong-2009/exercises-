#include <iostream>
#include <set>
#include <assert.h>
using namespace std;


int func(multiset<int> arr) {
	assert(arr.size() <= 20);
	if (arr.size() == 0) {
		return 0;
	}

	int res = 0;
	size_t app_count = 0;
	for (multiset<int>::iterator it = arr.begin(); it != arr.end(); ++it) {
		if (arr.count(*it) > app_count) {
			app_count = arr.count(*it);
			res = *it;
		}
	}
	return res;
}

int main() {
	int count = 0;
	cin >> count;
	multiset<int> arr;

	for (int i = 0; i < count; ++i) {
		int tmp = 0;
		cin >> tmp;
		arr.insert(tmp);
	}

	int res = func(arr);

	cout << res << endl;
	system("pause");
	return 0;
}