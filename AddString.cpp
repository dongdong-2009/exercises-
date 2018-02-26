#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

string AddSring(string s1, string s2){
    string ret = "";
    int s1_index = s1.size() - 1;
    int s2_index = s2.size() - 1;
    int carry = 0;
    while(s1_index >=0 || s2_index >= 0){
        int a = s1_index >= 0 ? s1[s1_index--]-'0' : 0;
        int b = s2_index >= 0 ? s2[s2_index--]-'0' : 0;
        int sum = a + b + carry;
        ret.insert(ret.begin(), sum % 10 + '0');
        carry = sum / 10;
    }
    return carry != 0 ? "1"+ret : ret;
}


int main(){
    string s1 = "1234";
    string s2 = "2345";

    string ret = AddSring(s1, s2);
    printf("%s\n", ret.c_str());
    return 0;
}
