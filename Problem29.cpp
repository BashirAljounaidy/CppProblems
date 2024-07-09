#include <iostream>

using namespace std;


int ReadPositiveNumber(string message) {
    int Number=0;
    do {
        cout << message << ": ";
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

//Prime Numbers Fucntions
bool IsDivisible(int Number, int Divider) {
    return Number != Divider && Number % Divider == 0;
}

bool IsPrimeNumber(int Number) {
    if (Number == 1) return false; // 1 is not a prime number

    for (int i = 2; i < Number; i++) { // Loop from 2 to Number-1
        if (IsDivisible(Number, i))  return false;
    }   
    return true;
}
//Arrays Functions
int RandomNumberFromTo(int From,int To){
    int random=rand()%(To-From)+From;
    return random;
}

void randomFillArray(int array[],int arrayLength){
    for (int i = 0; i < arrayLength; i++)
    {
        array[i]=RandomNumberFromTo(1,100);
    }
}

void PrintArray(int array[],int arrayLength){
    for (int i = 0; i < arrayLength; i++)
    {
        cout<<array[i]<<"  ";
    }
    cout<<endl;

}
int CopyPrimeFromArrToArr(int array[],int primeArray[],int arrayLength){
    int index=0;
    for (int i = 0; i < arrayLength; i++)
    {
        if(IsPrimeNumber(array[i])){
            primeArray[index]=array[i];
            index++;
        }
    }
    return index;
    
}
int main() {
    srand(static_cast<unsigned int>(time(NULL)));
    int arraylenght ,primeArrayLength,myArray[100],myPrimeArray[100];
    arraylenght=ReadPositiveNumber("enter the lenght of array");

    randomFillArray(myArray,arraylenght);
    cout<<"Elements of Array: ";
    PrintArray(myArray,arraylenght);
    primeArrayLength=CopyPrimeFromArrToArr(myArray,myPrimeArray,arraylenght);
    cout<<"Elements of Prime Array: ";
    PrintArray(myPrimeArray,primeArrayLength);
    return 0;
}

