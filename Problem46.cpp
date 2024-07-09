#include <iostream>

using namespace std;
float ReadNumber(string Message){
    float Number=0;
    cout<<Message;
    cin>>Number;
    return Number;
}

float MyAbs(float number) {
    return (number < 0) ? -number : number;
}

int main() {
    float Number = ReadNumber("Please enter number :  ");
    cout << "My abs Result : " << MyAbs(Number) << endl;
    cout << "C++ abs Result: " << abs(Number) << endl;
    return 0;
}

