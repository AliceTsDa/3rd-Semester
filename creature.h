#ifndef CREATURE_H_
#define CREATURE_H_

#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

class CreatureSociety;

class Creature{
    private:
        string name;
    protected:
        CreatureSociety *pos;
        int life, pos_i;
    public:
        Creature(string creatureName, int creatureLife, CreatureSociety* position, int position_i);
        virtual ~Creature();
        void clone(Creature* &c);
        virtual void bless()=0;
        void beat();
        bool is_a_zobie();
        virtual bool is_a_good()=0;
        virtual int getThreshold()=0;
};



class GoodCreature : public Creature{
	private:
        int goodThreshold;
    public:
        GoodCreature(string creatureName, int creatureLife, int goodThrsh, CreatureSociety* position, int position_i) :
            Creature(creatureName, creatureLife, position, position_i){
            goodThreshold=goodThrsh;
            cout<<"Created good creature."<<endl;
        }
        virtual ~GoodCreature(){
            cout<<"Destroyed good creature. ";
        }
        virtual void bless();
        virtual bool is_a_good(){
            return true;
        }
        virtual int getThreshold(){
            return goodThreshold;
        }
};



class BadCreature : public Creature{
	private:
        int badThreshold;
    public:
        BadCreature(string creatureName, int creatureLife, int badThrsh, CreatureSociety* position, int position_i) :
            Creature(creatureName, creatureLife, position, position_i){
            badThreshold = badThrsh;
            cout<<"Created bad creature."<<endl;
        }
        virtual ~BadCreature(){
            cout<<"Destroyed bad creature. ";
        }
        virtual void bless();
        virtual bool is_a_good(){
            return false;
        }
        virtual int getThreshold(){
            return badThreshold;
        }
};



class CreatureSociety{
    private:
        int size;
        Creature** array;
    public:
        CreatureSociety(int sizeOfArray, int initialLife, int goodThreshold, int badThreshold);
        ~CreatureSociety();
        void beat(int i){
            array[i]->beat();
        }
        void bless(int i){
            array[i]->bless();
        }
        int no_of_good(){
            int counter=0;
            int i=0;
            while(i<size){
                if(array[i]->is_a_good())
                    counter+=1;
                i+=1;
            }
            return counter;
        }
        int no_of_zobies(){
            int counter=0, i=0;
            while(i<size){
                if(array[i]->is_a_zobie())
                    counter+=1;
                i+=1;
            }
            return counter;
        }
        void clone_next(int i){
            int next = (i==size-1) ? 0 : i+1;
            array[i]->clone(array[next]);
        }
        void clone_zobies(int i){
            for(int j=i; j<size; ++j)
                if(array[j]->is_a_zobie())
                    array[i]->clone(array[j]);
        }
};

#endif