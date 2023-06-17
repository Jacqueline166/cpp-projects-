#include <iostream>
#include <vector>

using namespace std;

int findMax(int num1, int num2) {
    if (num1>num2) {
        return num1;
    } else if (num2>num1) {
        return num2;
    }
}

int addAll(vector<int> nums) {
    int total=0;
    for (int i=0; i<nums.size(); i++) {
        total=nums[i]+total;
    }
    return total;
}

int main() {
    cout<<"findMax"<<endl;
    cout<<findMax(4, 5)<<endl;
    cout<<findMax(5, 4)<<endl;
    cout<<"addAll"<<endl;
    vector<int> vec1= {10, 23, 40};
    vector<int> vec2= {10, 23, 40, 50, 7};
    cout<<addAll(vec1)<<endl;
    cout<<addAll(vec2)<<endl;
    return 0;
}