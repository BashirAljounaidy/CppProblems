#include <iostream>
#include <cmath>

using namespace std;

float MyAbs(float number) {
    return (number < 0) ? -number : number;
}

bool IsNegative(float Number){
    return Number<0;
}

float MyRound(float Number){
    int result = int((Number*10))%10;
    if(Number<0){
        result=MyAbs(result);
        if(result>4) return int(Number)-1 ;else return int(Number);
    }
    else{
        if(result>4) return int(Number)+1 ;else return int(Number);
    }
}

int main() {
    float Number= -10.77,divider=1.00;
    cout<<"Round "<<Number<<" = "<<MyRound(Number)<<" C++ Round "<<round(Number);
    cout<<endl;
    Number= -10.33;
    cout<<"Round "<<Number<<" = "<<MyRound(Number)<<" C++ Round "<<round(Number);
    return 0;
}

