#include <iostream>

using namespace std;

int main()
{
    int counter = 0;
    for (char i = 'A'; i <= 'Z'; i++)
    {
        for (char j = 'A'; j <= 'Z'; j++)
        {
            for (char z = 'A'; z <= 'Z'; z++)
            {
                cout << i << j << z << endl;
            }
        }
    }
    cout << counter;
    return 0;
}
