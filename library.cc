#include <iostream>
#include "library.h"
using namespace std;

        void Library::place_book(int number){
           switch(number){
                case 1:
                    if(s[0].place_book()==1){
                        cout<<"I placed a book on shelf no1"<<endl;
                    }
                    else{
                        cout<<"There was not enough space on shelf no1 to place a book"<<endl;
                    }
                    break;
                case 2:
                    if(s[1].place_book()==1){
                        cout<<"I placed a book on shelf no2"<<endl;
                    }
                    else{
                        cout<<"There was not enough space on shelf no2 to place a book"<<endl;
                    }
                    break;
                case 3:
                    if(s[2].place_book()==1){
                        cout<<"I placed a book on shelf no3"<<endl;
                    }
                    else{
                        cout<<"There was not enough space on shelf no3 to place a book"<<endl;
                    }
                    break;
                case 4:
                    if(c.place_book(number)==1){
                        cout<<"I placed a book inside the cupboard, on the shelf no1"<<endl;
                    }
                    else{
                        cout<<"There was not enough space inside the cupboard, on the shelf no1"<<endl;
                    }
                    break;
                case 5:
                    if(c.place_book(number)==1){
                        cout<<"I placed a book inside the cupboard, on the shelf no2"<<endl;
                    }
                    else{
                        cout<<"There was not enough space inside the cupboard, on the shelf no2"<<endl;
                    }
                    break;
           }

        }
        
        void Library::take_book(int number){
           switch(number){
                case 1:
                    if(s[0].take_book()==1){
                        cout<<"I took a book from shelf no1"<<endl;
                    }
                    else{
                        cout<<"There was not a single book to take from shelf no1"<<endl;
                    }
                    break;
                case 2:
                    if(s[1].take_book()==1){
                        cout<<"I took a book from shelf no2"<<endl;
                    }
                    else{
                        cout<<"There was not a single book to take from shelf no2"<<endl;
                    }
                    break;
                case 3:
                    if(s[2].take_book()==1){
                        cout<<"I took a book from shelf no3"<<endl;
                    }
                    else{
                        cout<<"There was not a single book to take from shelf no3"<<endl;
                    }
                    break;
                case 4:
                    if(c.take_book(number)==1){
                        cout<<"I took a book from inside the cupboard, from the shelf no1"<<endl;
                    }
                    else{
                        cout<<"There was not a single book to take from inside the cupboard, from shelf no1"<<endl;
                    }
                    break;
                case 5:
                    if(c.take_book(number)==1){
                        cout<<"I placed a book  from inside the cupboard, from the shelf no2"<<endl;
                    }
                    else{
                        cout<<"There was not a single book to take from inside the cupboard, from shelf no2"<<endl;
                    }
                    break;
           }
        }
////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Base::Base(){
            cout<<"A base has been created!"<<endl;
        }//constructor
        
        Base::~Base(){
            cout<<"A base has been destroyed!"<<endl;
        }//destructor

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        Book::~Book(){
            cout<<"A book has been destroyed!"<<endl;
        }//destructor
