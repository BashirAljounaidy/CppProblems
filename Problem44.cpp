#include <iostream>

using namespace std;

//is Positive 
bool IsPositive(int Number){
    if(Number >0) return true;else return false;
}

int CountPositiveNumbers(int OriginalArray[],int OriginalArrayLength){
    int PositiveCounter=0;
    for (int i = 0; i < OriginalArrayLength; i++)
    {
        if(IsPositive(OriginalArray[i])){
            PositiveCounter++;
        }
    }
    return PositiveCounter; 
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
        array[i]=RandomNumberFromTo(-100,100);
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
    int PositiveNumbersCount = CountPositiveNumbers(myArray,myArrayLength);

    //Outputs
    PrintArray(myArray,myArrayLength);
    cout<<"Positive Number Count is : "<<PositiveNumbersCount<<endl;

    return 0;
}