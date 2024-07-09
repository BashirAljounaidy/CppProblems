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

int IndexOfValueInArray(int value,int array[],int arrLength){
    for (int i = 0; i < arrLength; i++)
    {
        if(array[i]==value) return i;
    }
    return -1;
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
    int myArray1[100],arraylenght=0,value,index;
    arraylenght=ReadPositiveNumber("enter the lenght of array");
    randomFillArray(myArray1,arraylenght);
    PrintArray(myArray1,arraylenght);
    value=ReadPositiveNumber("enter the value to find");
    cout<<"Value you Entered: "<<value<<endl;
    index=IndexOfValueInArray(value,myArray1,arraylenght);
    if (index>=0)
    {
        cout<<"The Value founded at index :"<<index<<endl;
    }
    else
    {
        cout<<"The Value not found :("<<endl;

    }
    
    // cout<<"Elements ArraySum : ";
    // SumTwoArrays(myArray1,myArray2,arraylenght,myArray3);
    // PrintArray(myArray3,arraylenght);
    return 0;
}

