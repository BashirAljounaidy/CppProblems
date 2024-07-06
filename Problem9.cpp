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


int CountDigitInNumber(unsigned long long int Number,unsigned short int digit) {
    unsigned short int count = 0;
    for (; Number != 0; Number /= 10) {
        if (Number % 10 == digit) count++;
    }
    return count;
}

int main()
{

    unsigned long long int Number = ReadPositiveNumber("Enter Number");
    for (int i = 0; i < 10; i++)
    {
        unsigned short int count = CountDigitInNumber(Number, i);
        if(count) cout<<"This Digit "<<i<<" Repeated "<< count <<" Times\n";
    }
    return 0;
    //-9223372036854775808
}


