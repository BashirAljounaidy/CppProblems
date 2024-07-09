#include <iostream>

using namespace std;

//Read input
int ReadNumber(string message) {
    int Number=0;
    do {
        cout << message << ": ";
        cin >> Number;
    } while (Number < 0);
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

void AddElementToArray(int element,int array[],int index){
    array[index]=element;
}

void CopyArray1by1(int arrayOriginal[],int arrayCopy[],int arrayOriginalLength){
    for (int i = 0; i < arrayOriginalLength; i++)
    {
        AddElementToArray(arrayOriginal[i],arrayCopy,i);
    }
}

int main() {
    srand(static_cast<unsigned int>(time(NULL)));
    int MyArray[100],MyCopiedArray[100],ArrayLength=0;
    ArrayLength=ReadNumber("Please Enter Array Length");
    randomFillArray(MyArray,ArrayLength);
    cout<<"Original Array:"<<endl;
    PrintArray(MyArray,ArrayLength);
    cout<<"Copied Array:"<<endl;
    CopyArray1by1(MyArray,MyCopiedArray,ArrayLength);
    PrintArray(MyCopiedArray,ArrayLength);

    return 0;
}

