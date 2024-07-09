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

void FillArrayFromUser(int array[], int &arrayLength){
    int Number=0;
    bool NeedMore=false;
    do
    {
        Number=ReadNumber("Please Enter a Number");
        array[arrayLength]=Number;
        NeedMore=ReadNumber("Do you need to add more ? (1) Yes (0) No");
        arrayLength++;
    } while (NeedMore==true);
    
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
    int myArray[100],arraylenght=0;
    FillArrayFromUser(myArray,arraylenght);
    cout<<"Your Array is : ";
    PrintArray(myArray,arraylenght);
    cout<<endl;
    return 0;
}

