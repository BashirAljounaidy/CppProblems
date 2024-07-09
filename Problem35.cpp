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

//Random Functions 
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

int IndexOfValueInArray(int value,int array[],int arrLength){
    for (int i = 0; i < arrLength; i++)
    {
        if(array[i]==value) return i;
    }
    return -1;
}



bool IsTheValueExistInArray(int value,int array[],int arrLength){
    if(IndexOfValueInArray(value,array,arrLength)>=0) return true ;else return false;
}

int main() {
    srand(static_cast<unsigned int>(time(NULL)));
    int myArray1[100],arraylenght=0,value,index;
    arraylenght=ReadPositiveNumber("enter the lenght of array");
    randomFillArray(myArray1,arraylenght);
    PrintArray(myArray1,arraylenght);
    value=ReadPositiveNumber("enter the value to find");
    cout<<"Value you looking for: "<<value<<endl;
    IsTheValueExistInArray(value,myArray1,arraylenght)&& cout<<"Yes it is there"<<endl||cout<<"No it is not there"<<endl;
    return 0;
}

