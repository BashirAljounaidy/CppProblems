#include <iostream>
using namespace std;
enum enPrimeNotPrime{NotPrime=1,Prime=1};

bool IsOne(int Number) {
    return Number >= 1;
}

bool IsDivisible(int Number, int Divider) {
    return Number != Divider && Number % Divider == 0;
}

bool IsPrimeNumber(int Number) {
    if (IsOne(Number)) return false; // 1 is not a prime number

    for (int i = 2; i < Number; i++) { // Loop from 2 to Number-1
        if (IsDivisible(Number, i))  return false;
    }   
    return true;
}

void PrintAllPreviousPrimeNumbers(int LastNumber){
    for(int i=2 ;i <= LastNumber;i++){
       IsPrimeNumber(i) && cout<<" "<<i<<" is Prime"<<endl;
    }
}

int main() {
    int Number;
    cout << "Please Enter the Number: ";
    cin >> Number;
    PrintAllPreviousPrimeNumbers(Number);
}
