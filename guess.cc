#include<iostream>
using namespace std;

int main(){
    int secret=15;
    int guess; //No initialization needed here

    do{
        cout<<"Guess the number:";
        cin>>guess; //Initialization happens
    }while(guess!=secret);

    cout<<"You got it!"<<endl;

    return 0;
}