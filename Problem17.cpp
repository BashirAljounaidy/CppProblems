#include <iostream>

using namespace std;

string ReadWord()
{
    string world = "";
    while (world == "")
    {
        cout << "Please Enter world : ";
        cin >> world;
        return world;
    }
    return "";
}

string EncryptWorld(string world,int shift){
    for(int i=0;i<world.length();i++){
        world[i]=char (world[i]+shift);
    }
    return world;
}

int main() {
    string name=ReadWord();
    string EncryptedWorld=EncryptWorld(name,2);
    string DecryptedWorld=EncryptWorld(EncryptedWorld,-2);

    cout<<"EncryptedWorld "<<EncryptedWorld<<endl;
    cout<<"DecryptedWorld "<<DecryptedWorld<<endl;
    return 0;
}

