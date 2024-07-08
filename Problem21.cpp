#include <iostream>

using namespace std;

int randomNumberGenerator(int From,int To){
    int random=rand()%(To-From)+From;
    return random;
}

char randomCapitalLetterGenerator(char From ,char To){
    return char(randomNumberGenerator(int(From),int(To)));
}

string generateRandomString(int size){
    string serialString="";
    for (int i=0;i<size;i++){
        serialString=serialString+randomCapitalLetterGenerator('A','Z');
    }
    return serialString;
}

string generateSerial(int segmentLength, int sizeSegment) {
    string serialString = "";
    for (int i = 0; i < sizeSegment; i++) {
        serialString += generateRandomString(segmentLength);
        if (i < sizeSegment - 1) serialString += "-";
    } 
    return serialString;
}

void printSerialKeys(int numKeys){
    for (int i = 0; i < numKeys; i++)
    {
        cout<<"Key ["<<i+1<<"] : "<<generateSerial(4,4)<<endl;
    }
    
}

int main() {
    srand(static_cast<unsigned int>(time(NULL)));
    printSerialKeys(5);
    return 0;
}
