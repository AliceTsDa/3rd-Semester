#include<iostream>
using namespace std;

int main(){
    bool quit=false; //Flag for quitting

    while(quit==false){
        cout<<"Select a, b or q to quit"<<endl;
        char response;
        cin>>response;

        switch(response){
            case'a': cout<<"You chose a"<<endl;
                     break;
            
            case'b': cout<<"You chose b"<<endl;
                     break;

            case'q': cout<<"Quitting menu"<<endl;
                     quit=true;
                     break;
            
            default: cout<<"Please use a, b or q!"<<endl;         
        }
    }

    return 0;
}