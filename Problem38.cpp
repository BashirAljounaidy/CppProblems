#include <iostream>

using namespace std;

//is odd 
bool IsOdd(int Number){
    if(Number %2 !=0) return true;else return false;
}

//Add Element To Array
void AddElementToArray(int element,int array[],int index){
    array[index]=element;
}

void CopyOddFromArrayToArray(int OriginalArray[],int OriginalArrayLength,int OddArray[],int &OddArrayLength){
    int OddArrayIndex=0;
    for (int i = 0; i < OriginalArrayLength; i++)
    {
        if(IsOdd(OriginalArray[i])){
            AddElementToArray(OriginalArray[i],OddArray,OddArrayIndex);
            OddArrayIndex++;
        }
    }
    OddArrayLength=OddArrayIndex; 
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
    int myArray1[100],oddArray[100],arrayLength=0,oddArrayLength=0;
    arrayLength=ReadPositiveNumber("enter the lenght of array");
    cout<<"Elements of Array:"<<endl;
    randomFillArray(myArray1,arrayLength);
    PrintArray(myArray1,arrayLength);
    CopyOddFromArrayToArray(myArray1,arrayLength,oddArray,oddArrayLength);
    cout<<"OddArray: ";
    PrintArray(oddArray,oddArrayLength);
    return 0;
}