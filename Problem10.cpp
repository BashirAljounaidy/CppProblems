#include <iostream>
#include <limits>
using namespace std;

unsigned long long int ReadPositiveNumber(string message) {
    unsigned long long int Number=0;
    do {
        cout << message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

unsigned long long int ReversedNumber(unsigned long long int Number){
    unsigned long long int Reversed=0;
    do
    {
        Reversed=Reversed*10+Number%10;
        Number/=10;
    } while (Number !=0);
    return Reversed;
    
}

int main()
{

    unsigned long long int Number = ReadPositiveNumber("Enter Number");
    cout<<ReversedNumber(Number)<<endl;
    Number==ReversedNumber(Number) &&cout<<"it is Palindorm Number\n"||cout<<"it is not Palindorm Number\n";
    return 0;
    //-9223372036854775808
}


