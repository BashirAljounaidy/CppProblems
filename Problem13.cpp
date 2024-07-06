#include <iostream>
using namespace std;

unsigned long long int ReadPositiveNumber(string message) {
    unsigned long long int Number=0;
    do {
        cout << message << ": ";
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

void PrintTringleNumber(unsigned long long int Number ){
        for (int i = 0; i <= Number; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout<<i;
        }
        cout<<endl;
    }
}

int main()
{
    unsigned long long int Number = ReadPositiveNumber("Enter a positive Number");
    PrintTringleNumber(Number);
    return 0;
}
