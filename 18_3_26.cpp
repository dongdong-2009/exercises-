#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

//求最小公倍数
int GetGcd(int num1, int num2){
    if(num2 == 0)
        return num1;

    return GetGcd(num2, num1%num2);
}

int main(){
    int num1, num2;
    cin>>num1;
    cin>>num2;
    //最小公倍数 = num1 * num2 / 最大公约数
    //最大公约数使用辗转相除法
    int res = 0;
    int a = num1;
    int b = num2;
    while(b != 0){
        res = a % b;
        if(res == 0){
            res = b;
            break;
        }
        a = b;
        b = res;
    }
   //2.利用递归
   // int res = GetGcd(num1, num2);
    cout<<"最大公约数:"<<res<<endl;
    cout<<"最小公倍数:"<<num1*num2/res<<endl;
    return 0;
}







