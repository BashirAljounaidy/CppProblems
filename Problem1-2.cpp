#include <iostream>
using namespace std;



int main()
{
    cout<<"\t\t\tMultiplication Table From 1 to 10\n";
    for(short int i=1;i<=10;i++){
        cout<<"\t"<<i;
        if(i==10){
            cout<<endl;
        }
    }
    for(short int i=1;i<=83;i++){
        cout<<"-";
        if(i==83){
            cout<<endl;
        }
    }
    for(short int i=1;i<=10;i++){
        if(i==10){
           cout<<i<<"   |";
        }else{
            cout<<i<<"    |";
        }

        for(short int j=1;j<=10;j++){
            cout<<"\t"<<i*j;
            } 
        cout<<"\n";
    } 
    return 0;
}