#include <iostream>

using namespace std;

//Read input
int ReadPositiveNumber(string message) {
    int Number=0;
    do {
        cout << message << ": ";
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

//Randome Functions 
int RandomNumberFromTo(int From,int To){
    int random=rand()%(To-From)+From;
    return random;
}

//Arrays Functions
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


//Add Element To Array
void AddElementToArray(int element,int array[],int index){
    array[index]=element;
}

void CopyPrimeFromArrayToArray(int OriginalArray[],int OriginalArrayLength,int PrimeArray[],int &PrimeArrayLength){
    int PrimeArrayIndex=0;
    for (int i = 0; i < OriginalArrayLength; i++)
    {
        if(IsPrimeNumber(OriginalArray[i])){
            AddElementToArray(OriginalArray[i],PrimeArray,PrimeArrayIndex);
            PrimeArrayIndex++;
        }
    }
    PrimeArrayLength=PrimeArrayIndex; 
}


int main() {
    srand(static_cast<unsigned int>(time(NULL)));
    int myArray1[100],primeArray[100],arrayLength=0,primeArrayLength=0;
    arrayLength=ReadPositiveNumber("enter the lenght of array");
    cout<<"Elements of Array:"<<endl;
    randomFillArray(myArray1,arrayLength);
    PrintArray(myArray1,arrayLength);
    CopyPrimeFromArrayToArray(myArray1,arrayLength,primeArray,primeArrayLength);
    cout<<"PrimeArray: ";
    PrintArray(primeArray,primeArrayLength);
    return 0;
}

