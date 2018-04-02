#include <iostream>
#include <vector>
using namespace std;
//将一个递增序列和一个递减序列利用归并排序进行合并

void Merge(vector<int>& a1, vector<int>& a2, vector<int>& a3){
    int first_start = 0; int first_end = a1.size()-1;
    int second_start = a2.size()-1; int second_end = 0;
    while(first_start <= first_end && second_start >= second_end){
        if(a1[first_start] < a2[second_start]){
            a3.push_back(a1[first_start++]);
        }else{
            a3.push_back(a2[second_start--]);
        }
    }

    while(first_start <= first_end){
        a3.push_back(a1[first_start++]);
    }
    while(second_start >= second_end){
        a3.push_back(a2[second_start--]);
    }
}

int main(){
    vector<int> a1;
    vector<int> a2;
    
    a1.push_back(1);
    a1.push_back(4);
    a1.push_back(6);
    a1.push_back(8);

    a2.push_back(7);
    a2.push_back(5);
    a2.push_back(3);
    a2.push_back(2);
    a2.push_back(0);

    vector<int> ret;
    Merge(a1, a2, ret);

    for(int i=0; i<ret.size(); ++i){
        cout<<ret[i]<<" ";
    }
    cout<<endl;
    return 0;
}
