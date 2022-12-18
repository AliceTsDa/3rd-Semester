#include<iostream>
using namespace std;

void print (int i){
    cout<<"Printing an integer value:"<<i<<endl;
}

void print(double d){
     cout<<"Printing adouble value:"<<d<<endl;
}

void print(const char* str){
    cout<<"Printing a string:"<<str<<endl;
}

int main(){
    int i=10;
    double d=3.14;
    char* str="This is a string";

    print(i);
    print(d);
    print(str);

    return 0;
}
