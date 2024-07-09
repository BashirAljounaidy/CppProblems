#include <iostream>

using namespace std;

int ReadPositiveNumber(string message) {
    int Number=0;
    do {
        cout << message << ": ";
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

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
    cout<<"Array Elements: ";
    for (int i = 0; i < arrayLength; i++)
    {
        cout<<array[i]<<"  ";
    }
    cout<<endl;

}


int findMaxOfArray(int array[],int arrayLength){
    int max=0;
    for (int i = 0; i < arrayLength; i++)
    {
        if(array[i]>max) max=array[i];
    }
    return max;
}
int main() {
    srand(static_cast<unsigned int>(time(NULL)));

    int arraylenght,myArray[100];
    arraylenght=ReadPositiveNumber("enter the lenght of array");
    randomFillArray(myArray,arraylenght);
    PrintArray(myArray,arraylenght);
    cout<<"The Max : "<<findMaxOfArray(myArray,arraylenght)<<endl;
    return 0;
}

