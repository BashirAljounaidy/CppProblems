#include <iostream>
#include<cstdlib>

using namespace std;

int GetOnes(int number){
    return number%10;
}

int ReadPositiveNumber(string message) {
    int Number=0;
    do {
        cout << message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}


int RandomNumberFromTo(int From,int To){
    int random=rand()%(To-From)+From;
    return random;
}

int main() {
    srand(static_cast<unsigned int>(time(NULL)));

    cout<<RandomNumberFromTo(0,9)<<endl;
    cout<<RandomNumberFromTo(0,9)<<endl;
    cout<<RandomNumberFromTo(0,9)<<endl;
    return 0;
}

