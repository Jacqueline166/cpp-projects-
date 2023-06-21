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

float fToC(float temperature) {
    return (temperature-32)*5/9;
}

char calculateGrade(float grade) {
    if (grade>=90) {
        return 'A';
    } else if (grade>=80){
        return 'B';
    } else if (grade>=70) {
        return 'C';
    } else if (grade>=60) {
        return 'D';
    } else {
        return 'F';
    }
        
}

int factorial(int num) {
    if (num==1) {
        return 1;
    } 
    return num*factorial(num-1);
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

    cout<<"calculateGrade"<<endl;
    cout<<calculateGrade(97)<<endl;
    cout<<calculateGrade(82)<<endl;
    cout<<calculateGrade(60.3)<<endl;
    cout<<calculateGrade(79.9)<<endl;
    cout<<calculateGrade(32)<<endl;

    cout<<"fToC"<<endl;
    cout<<fToC(140)<<endl;
    cout<<fToC(76)<<endl;
    cout<<fToC(89)<<endl;
    cout<<fToC(111)<<endl;
    cout<<fToC(44.4)<<endl;

    cout<<"factorial"<<endl;
    cout<<factorial(5)<<endl;
    cout<<factorial(4)<<endl;
    cout<<factorial(3)<<endl;
    cout<<factorial(2)<<endl;
    cout<<factorial(1)<<endl;
    return 0;
}