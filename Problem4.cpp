#include <iostream>
using namespace std;

void SwapNumbers(char &A, char &B) {
    char Temp;
    Temp = A;
    A = B;
    B = Temp;
}

int main() {
    char Numbers[] = {'1', '2', '3', '4', '5', '6', '7'};
    int length = sizeof(Numbers) / sizeof(Numbers[0]);

    cout << "Original array: ";
    for (int i = 0; i < length; i++) {
        cout << Numbers[i];
    }
    cout << endl;

    for (int i = 0; i < length / 2; i++) {
        SwapNumbers(Numbers[i], Numbers[length - 1 - i]);
    }

    cout << "Reversed array: ";
    for (int i = 0; i < length; i++) {
        cout << Numbers[i];
    }
    cout << endl;

    return 0;
}
