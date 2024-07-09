#include <iostream>
using namespace std;

bool IsArrayPalindorme(int array[],int arrayLength){
    for (int i = 0; i < arrayLength/2; i++)
    {
        if(array[arrayLength-1-i]!=array[i]) return false;
    }
    return true;
}

void PrintArray(int array[],int arrayLength){
    for (int i = 0; i < arrayLength; i++)
    {
        cout<<array[i]<<"  ";
    }
    cout<<endl;
}

void PrintResult(int array[],int length){
    cout<<"Array : ";
    PrintArray(array,length);
    cout<<"IsArrayPalindorme : ";
    if(IsArrayPalindorme(array,length)) cout<<"Yes" ;else cout<<"No";
    cout<<endl;
}

int main() {
    int ArraysLength=9;

    int NonPoArray[9]={10,40,20,30,20,30,20,20,10};
    int PoArray[9]={10,20,20,30,20,30,20,20,10};
    PrintResult(NonPoArray,ArraysLength);
    cout<<"**********************"<<endl;
    PrintResult(PoArray,ArraysLength);
    return 0;
}

