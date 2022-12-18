#include<iostream>
#include<cstring>
using namespace std;

class Book{
    private:
        char title[10];
        char author[10];
        int ISBN;
    public:
        Book(char t[], char a[], int i){
            ISBN=i;
            strcpy(title,t);
            strcpy(author, a);
            cout<<"A book has been created!"<<endl;
        }
        ~Book();//destructor
};

class Shelf{
    private:
        int Nmax;
        int Ncurrent=0;
    public:
        Shelf(int NMax):
            Nmax(NMax){
            cout<<"A shelf has been created!"<<endl;
            Nmax=NMax;
        }//constructor
        
        ~Shelf(){
            cout<<"A shelf has been destroyed!"<<endl;
        }//destructor

        int place_book(){
            if(Ncurrent<Nmax){
                Ncurrent++;
                return 1;
            }
            return 0;
        }

        int take_book(){
            if(Ncurrent>0){
                Ncurrent--;
                return 1;
            }
            return 0;
        }
};

class Base{
    public:
        Base();//constructor
        ~Base();//destructor
};

class Cupboard{
    private:
        Shelf s[2];
    public:
        Cupboard(int NMax):
            s({NMax,NMax}){
                cout<<"A cupboard has been created!"<<endl;
        }//constructor
        
        ~Cupboard(){
            cout<<"A cupboard has been destroyed!"<<endl;
        }//destructor
        
        int place_book(int number){
            switch(number){
                case 4:
                    return(s[0].place_book());
                case 5:
                    return(s[1].place_book());
            }
        }

        int take_book(int number){
            switch(number){
                case 4:
                    return(s[0].take_book());
                case 5:
                    return(s[1].take_book());
            }
        }
};

class Library{
    private:
        Base b;
        Cupboard c;
        Shelf s[3];
        int N; //total counter of books

    public: 
        Library(int NMax):
            c(NMax), s({NMax,NMax,NMax}){
                cout<<"A library has been created!"<<endl;
            }//constructor
        ~Library(){
            cout<<"A library has been destroyed!"<<endl;
        }//destructor
        void place_book(int number);//mutator
        void take_book(int nummber);//mutator

};
