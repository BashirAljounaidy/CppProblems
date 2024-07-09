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

void PrintArray(int array[],int arrayLength){
    for (int i = 0; i < arrayLength; i++)
    {
        cout<<array[i]<<"  ";
    }
    cout<<endl;
}

void AddElementToArray(int element,int array[],int index){
    array[index]=element;
}


bool IsElementInArray(int Element, int Array[], int ArrayLength) {
    for (int i = 0; i < ArrayLength; i++) {
        if (Array[i] == Element) return true;
    }
    return false;
}

void AddToDistinctArray(int OriginalArray[],int OriginalArrayLength,int DistinctArray[],int &DistinctArrayLength){
    int DistinctArrayIndex=0;
    for (int i = 0; i < OriginalArrayLength; i++)
    {
        if(!IsElementInArray(OriginalArray[i],DistinctArray,DistinctArrayIndex)){
            AddElementToArray(OriginalArray[i],DistinctArray,DistinctArrayIndex);
            DistinctArrayIndex++;
        }
        
    }
    DistinctArrayLength=DistinctArrayIndex; 
}


int main() {
    int myArrayDistinct[100],myArray[10]={10,10,20,20,20,30,40,10,50,50};
    int myArrayLength=10,myArrayDistinctLength=0;
    cout<<"Elements of Array:"<<endl;
    PrintArray(myArray,10);
    AddToDistinctArray(myArray,myArrayLength,myArrayDistinct,myArrayDistinctLength);
    PrintArray(myArrayDistinct,myArrayDistinctLength);
    return 0;
}
