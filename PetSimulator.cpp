/*
class: player
 - attributes: stamina, pets, money, name
 - methods (actions): 
sub class: pet
 - attributes: happiness, health, hunger, hygine
 - methods: eat, sleep, 
sub sub classes: dog, cat, hamster, fish

todo: split program into multiple files and link with header files
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;



class Pet {
    protected:
        int happiness;
        int health;
        int hunger;
        int hygiene;
        string name;
    public:
        Pet(string name) {
            this->name=name;
            this->happiness=50;
            this->health=50;
            this->hunger=50;
            this->hygiene=50;
        }
        void eat() {
            cout<<"pet is eating"<<endl;
        }

        string getStatus() {
            stringstream ss;
            ss<<"name:"<<name<<endl
            <<"happiness:"<<happiness<<endl
            <<"hygiene:"<<hygiene<<endl;
            return ss.str();
        }

        string getName() {
            return name;
        }

        void sleep() {

        }
        void sayName() {
            cout<<name;
        }

        void setHygiene(int hygiene) {
            this->hygiene=hygiene;
        }

        void increaseHygiene(int increment) {
            setHygiene(hygiene+increment);
        }

        void decreaseHygiene(int decrement) {
            setHygiene(hygiene-decrement);
        }

        void setHappiness(int happiness) {
            this->happiness=happiness;
        }

        void increaseHappiness(int increment) {
            setHappiness(happiness+increment);
        }

        void decreaseHappiness(int decrement) {
            setHappiness(happiness-decrement);
        }
};

class Dog: public Pet {
    public:
        Dog(string name): Pet(name) {
        }
        void eat() {
            cout<<"dog is eating"<<endl;
        }
        void pet() {
            cout<<"petting the dog"<<endl;
            cout<<"the dog is happy"<<endl;
            increaseHappiness(5);
        }
};

class Fish: public Pet {
    public:
        Fish(string name): Pet(name) {
        }
        void eat() {
            cout<<"fish is eating"<<endl;
        }
        void cleanTank() {
            cout<<"cleaned tank"<<endl;
            increaseHygiene(5);
        }
};

class Player {
    private:
        int stamina;
        float money;
        string name;
        vector<Pet*> pets;
    public:
        void adoptPet(Pet * newPet) {
            pets.push_back(newPet);
        }
        Pet * getFirstPet() {
            return pets[0];
        }
        Pet * getSecondPet() {
            return pets[1];
        }

};

class PetStore {
    private:
        vector<Pet*> petStore;
    public:
        PetStore() {
            Pet * dog1 = new Dog("Duke");
            petStore.push_back(dog1);
        }
        
        Pet * findPetByName(string petName) {
            for(int i=0; i<petStore.size(); i++) {
                if(petStore[i]->getName()==petName) {
                    return petStore[i];
                } 
            } 
            return nullptr;
        }

        string listAllPets() {
            stringstream ss;
            for(int i=0; i<petStore.size(); i++) {
                ss<<"Pet "<<i+1<<endl
                <<petStore[i]->getStatus()<<endl<<endl;
            } 
            return ss.str();
        }
};



int main() {
    Player  player;
    PetStore * petStore = new PetStore();
    // Pet * dog = new Dog("Max");
    // dog->eat();
    // cout<<dog->getStatus();
    // ((Dog *) dog)->pet();
    // cout<<dog->getStatus();
    // player.adoptPet(dog);
    // ((Dog *) player.getFirstPet())->pet();

    // Pet * fish = new Fish("Otto");
    // player.adoptPet(fish);
    // ((Fish *) player.getSecondPet())->cleanTank();
    // cout<<player.getSecondPet()->getStatus();



    // TODO: create game loop that allows player to adopt pets and do things with them
    int action;
    cout<<"What would you like to do?"<<endl;
    cout<<"1. Adopt a new pet"<<endl
    <<">> ";
    cin>>action;
    string petName;
    Pet * newPet;

    switch (action) {
        case 1: //adopting a pet
            cout<<petStore->listAllPets()<<endl;
            cout<<"Which pet would you like to adopt? ";
            cin>>petName;
            newPet = petStore->findPetByName(petName);
            if(newPet) {
                cout<<"Adopting pet "<<petName<<endl;

            } else{
                cout<<"Could not find pet"<<endl;
            }
            break;
        default:;
    }  
}