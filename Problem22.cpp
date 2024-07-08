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

int CheckDigitExistance(int array[],int arrayLength,int digit){
    int count=0;
    for (int i = 0; i < arrayLength; i++)
    {
        array[i]==digit&&count++;
    }
    return count;
}

void InputElementsArray(int array[],int numberOfElements){
    cout<<"Enter elements of array : : "<<endl;
    for(int i=0;i<numberOfElements;i++){
        cout<<"Element ["<<i+1<<"] : ";
        cin>>array[i];
    }
}


int main() {
    int Number=0,myArray[100] ;
    Number=ReadPositiveNumber("Enter the number of Elements in Array : ");
    InputElementsArray(myArray,Number);
    int SearchableNumbe=ReadPositiveNumber("Enter number to search for : ");
    int count=CheckDigitExistance(myArray,Number,SearchableNumbe);
    cout<<"it apperas "<<count<<" times"<<endl;

    return 0;
}

