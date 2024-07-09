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
void SumTwoArrays(int array1[],int array2[],int arrayLength,int arraySum[]){
    for (int i = 0; i < arrayLength; i++)
    {
        arraySum[i]=array1[i]+array2[i];
    }
    
}
int main() {
    srand(static_cast<unsigned int>(time(NULL)));
    int myArray1[100],myArray2[100],myArray3[100],arraylenght=0;
    arraylenght=ReadPositiveNumber("enter the lenght of array");

    randomFillArray(myArray1,arraylenght);
    randomFillArray(myArray2,arraylenght);
    cout<<"Elements of Array1: ";
    PrintArray(myArray1,arraylenght);
    cout<<"Elements of Array2: ";
    PrintArray(myArray2,arraylenght);
    cout<<"Elements ArraySum : ";
    SumTwoArrays(myArray1,myArray2,arraylenght,myArray3);
    PrintArray(myArray3,arraylenght);
    return 0;
}

