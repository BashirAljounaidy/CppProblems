#include <iostream>
using namespace std;
int ReadPositiveInteger(string Number){
    
}
bool IsDivisible(int Number, int Divider) {
    return Number != Divider && Number % Divider == 0;
}

int SumOfDividors(int Number){
    int SumOfDividors=0;
    for (int i = 1; i < Number; i++) {
        if (IsDivisible(Number, i)) SumOfDividors+=i;
    }
    return SumOfDividors;
}

bool IsPerfektNumber(int Number) {
    if(SumOfDividors(Number)==Number)     return true;
    else return false;
}

void PrintNumbersPerfecktOrNot(int Number){
    if (IsPerfektNumber(Number)) cout<<Number<<" is Perfect Number \n" ;
    else cout<<Number<<" is Not Perfect Number\n" ;
}

int main() {
    int Number;
    cout << "Please Enter the Number: ";
    cin >> Number;
    PrintNumbersPerfecktOrNot(Number);
}
