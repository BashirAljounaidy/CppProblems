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
void SumTwoArrays(int array1[],int array2[],int arrayLength,int arraySum[]){
    for (int i = 0; i < arrayLength; i++)
    {
        arraySum[i]=array1[i]+array2[i];
    }
    
}

void SwapNumbers(int &A, int &B) {
    int Temp;
    Temp = A;
    A = B;
    B = Temp;
}

void FillOrderedArray(int array[],int arrLength){
    for (int i = 0; i < arrLength; i++)
    {
        array[i]=i+1;
    } 
}

void ShuffleArray(int array[], int arraylength){
    int shuffleIndex=0;
    for (int i = 0; i < arraylength; i++)
    {
        shuffleIndex =RandomNumberFromTo(0,arraylength);
        SwapNumbers(array[i],array[shuffleIndex]);
    }
}

int main() {
    srand(static_cast<unsigned int>(time(NULL)));
    int myArray1[100],arraylenght=0;
    arraylenght=ReadPositiveNumber("enter the lenght of array");

    cout<<"Elements of Array1: ";
    FillOrderedArray(myArray1,arraylenght);
    PrintArray(myArray1,arraylenght);
    ShuffleArray(myArray1,arraylenght);
    cout<<"Elements of Shuffeld: ";
    PrintArray(myArray1,arraylenght);
    // cout<<"Elements ArraySum : ";
    // SumTwoArrays(myArray1,myArray2,arraylenght,myArray3);
    // PrintArray(myArray3,arraylenght);
    return 0;
}

