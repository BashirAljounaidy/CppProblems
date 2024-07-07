#include <iostream>

using namespace std;

enum enCharType{CapitalLetter=1,SmallLetter=2,SpecialLetter=3,Digit=4};

int RandomNumberFromTo(int From,int To){
    int random=rand()%(To-From)+From;
    return random;
}

char GetRandomChar(enCharType SelectedType){
    switch (SelectedType)
    {
    case CapitalLetter:
         return RandomNumberFromTo(int('A'),int('Z'));
        break;
    case SmallLetter:
        return RandomNumberFromTo(int('a'),int('z'));
        break;
    case SpecialLetter:
        return RandomNumberFromTo(33,47);
        break;
    case Digit:
        return RandomNumberFromTo(1,9);
        break;   
    default:
        return 0;
        break;
    }
}

int main() {
    enCharType SelectedType;
    srand(static_cast<unsigned int>(time(NULL)));

    cout<<GetRandomChar(CapitalLetter);
    cout<<GetRandomChar(SmallLetter);
    cout<<GetRandomChar(SpecialLetter);
    cout<<int(GetRandomChar(Digit))<<endl;
    
    return 0;
}