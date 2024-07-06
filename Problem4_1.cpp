#include <iostream>
#include <string>
using namespace std;

int main() {
    string Numbers;
    cout<<"please enter series of numbers :"<<endl;

    cin>> Numbers;
    int length = Numbers.length();
    string count="";
    for (int i = length - 1; i >= 0; i--) {
        // int num = Numbers[i] - '0';  // Convert char to int
        count=count+Numbers[i];
    }
    cout<<count;
    return 0;
}
