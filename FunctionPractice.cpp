#include <iostream>

using namespace std;

int findMax(int num1, int num2) {
    if (num1>num2) {
        return num1;
    } else if (num2>num1) {
        return num2;
    }
   
}

int main() {
    cout<<findMax(4, 5)<<endl;
    cout<<findMax(5, 4)<<endl;
    return 0;
}