#include <iostream>

using namespace std;


//is odd 
bool IsOdd(int Number){
    if(Number %2 !=0) return true;else return false;
}

int CountOddNumbers(int OriginalArray[],int OriginalArrayLength){
    int OddCounter=0;
    for (int i = 0; i < OriginalArrayLength; i++)
    {
        if(IsOdd(OriginalArray[i])){
            OddCounter++;
        }
    }
    return OddCounter; 
}

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

int main() {
    srand(static_cast<unsigned int>(time(NULL)));
    int myArray[100], myArrayLength=0;

    //Read Input
    myArrayLength=ReadPositiveNumber("Please Enter The Number of Elements you want");

    //Process
    //Generate Random Array
    randomFillArray(myArray,myArrayLength);

    //Checks
    int OddNumbersCount = CountOddNumbers(myArray,myArrayLength);

    //Outputs
    PrintArray(myArray,myArrayLength);
    cout<<"Odd Number Count is : "<<OddNumbersCount<<endl;

    return 0;
}