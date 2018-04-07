#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
using namespace std;

/*n 只奶牛坐在一排，每个奶牛拥有 ai 个苹果，现在你要在它们之间转移苹果，使得最后所有奶牛拥有的苹果数都相同，每一次，你只能从一只奶牛身上拿走恰好两个苹果到另一个奶牛上，问最少需要移动多少次可以平分苹果，如果方案不存在输出 -1。*/

int apple(vector<int>& arr){
    //1、要求所有奶牛拥有苹果数目相等，必须苹果总数能够整数牛的个数
    int sum = 0;
    for(size_t i=0; i<arr.size(); ++i){
        sum += arr[i];
    }
    if(sum % arr.size() != 0)
        return -1;
    int avg = sum / arr.size();
    int movecount = 0;
    
    //只对少于平均值的进行统计
    for(size_t i=0; i<arr.size(); ++i){
        if(arr[i] > avg){
            //由于每次只能移动2个，所以所缺少的个数必须是偶数
            if(((arr[i]-avg) & 0x1) != 0)
                return -1;
            movecount += (arr[i]-avg)/2;
        }
    }
    return movecount;
}

int main(){
    int n = 0;
    scanf("%d", &n);
    vector<int> arr;
    while(n--){
        int tmp = 0;
        scanf("%d", &tmp);
        arr.push_back(tmp);
    }
    int ret = apple(arr);
    printf("%d\n", ret);
    
    return 0;
}
