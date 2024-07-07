#include <iostream>

using namespace std;
string ReadPassword(){
    string password="";
    while(password==""){
            cout<<"Please Enter Password to guess : \n";
    cin>>password;
    return password;
    }

}
void PrintCharacters(string password){
    string world="";
    int Trial=0;
    for (char i = 'A'; i <= 'Z'; i++)
    {
        for (char j = 'A'; j <= 'Z'; j++)
        {
            for (char z = 'A'; z <= 'Z'; z++)
            {
              world = world +char(i); 
              world = world +char(j); 
              world = world +char(z);
              world == password && cout<<"Password is: "<<world<<'\n'<<"Found After: "<<Trial<<" Trials"<<endl;
              Trial++;
              world="";
            }
        }
    }
}

int main()
{
    PrintCharacters(ReadPassword());
    return 0;
}
