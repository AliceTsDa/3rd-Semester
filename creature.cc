#include "creature.h"

static string goodNames[]={"Fairy_", "Elf_", "Wizard_", "Hobbit_", "Dwarf_"};
static string badNames[]={"Goblin_", "Orc_", "Troll_", "Uruk-hai_", "Vampire_"};

Creature::Creature(string creatureName, int creatureLife, CreatureSociety* position, int position_i) : name(creatureName){
	pos_i=position_i;
	cout<<"Created creature: "<<name<<" ";
	life=creatureLife;
	pos=position;
}

Creature::~Creature(){
	cout<<"Destroyed creature: "<<name<<endl;
}

void Creature::beat(){
	if(is_a_zobie())
		return;
	life--;
}

bool Creature::is_a_zobie(){
	if(life>0)
		return false;
	else
		return true;
}

void GoodCreature::bless(){
	if(is_a_zobie())
		return;
	life++;
	if(life>goodThreshold)
		pos->clone_next(pos_i);
}

void BadCreature::bless(){
	if(is_a_zobie())
		return;
	life++;
	if(life>badThreshold)
		pos->clone_zobies(pos_i);
}

void Creature::clone(Creature* &c){
	if(!is_a_zobie()){
		int new_pos_i=c->pos_i;
		delete c;
		if(is_a_good())
			c=new GoodCreature(name, life, getThreshold(), pos, new_pos_i);
		else
			c=new BadCreature(name, life, getThreshold(), pos, new_pos_i);
		cout<<"Cloned..."<<endl;
	}
}

CreatureSociety::CreatureSociety(int sizeOfArray, int initialLife, int goodThreshold, int badThreshold){
	char nameStr[15];

	size=sizeOfArray;
	array=new Creature*[size];
	for(int i=0; i<size; ++i){
		sprintf(nameStr, "%d", i);
		if(rand()%2==0){
			string name=goodNames[rand()%5];
			array[i]=new GoodCreature(name + nameStr, initialLife, goodThreshold, this, i);
		}
		else{
			string name=badNames[rand()%5];
			array[i]=new BadCreature(name + nameStr, initialLife, badThreshold, this, i);
		}
	}
	cout<<"Created a Creature Society"<<endl;
}

CreatureSociety::~CreatureSociety(){
	for(int i=0; i<size; ++i)
		delete array[i];
	delete[] array;
	cout<<"Destroyed a Creature Society"<<endl;
}