#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

class Animal {
    int height;
    string name;
    bool isHealthy;

    

    public:
    Animal() {
        
    }
    int getAge() {
        return height / 3;
    }

    void printName() {
        cout << name << endl;
    }

};

int main() {
    std::vector<std::string> catalog;

    while(true){
        std::cout<<"1. add a book\n2. remove a book\n3. list all books\n4. exit\n";
        int input;
        std::string titleInput;
        std::cin>>input;
        switch (input) {
            case 1:
                std::cout<<"Enter title of the book:";
                std::cin>>titleInput;
                catalog.push_back(titleInput);
                std::cout<<"Book has been added\n";
                break;
            case 2:
                std::cout<<"Please give title of the book\n";
                std::cin>>titleInput;
                for (int i=0; i<catalog.size(); i++) {
                    if (catalog[i]==titleInput) {
                        catalog.erase(catalog.begin()+i);
                        std::cout<<"Book has been removed from index "<<i<<std::endl;
                        break;
                    } else if (i==catalog.size()-1) {
                        std::cout<<"Book not found "<<std::endl;
                    }
                }
                break;
            case 3:
                std::cout<<"Printing all books\n";
                for (int i=0; i<catalog.size(); i++){
                    std::cout<<"Book "<<i+1<<": ";
                    std::cout<<catalog[i]<<std::endl;
                }
                std::cout<<"Finished printing books\n";
                break;
            case 4:
                std::cout<<"Exited";
                return 0;
                break;
            default:
                std::cout<<"Invalid Input\n";
        };
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }


    // std::vector<int> vec;
    // vec.push_back(4);
    // vec.push_back(5);
    // vec.push_back(3);
    // for(int i=0; i<vec.size(); i++){
    //     std::cout<<vec[i]<<std::endl;
    // }



    // int numbers[4];
    // // std::cout << numbers[0];
    // numbers[0]=2;
    // numbers[1]=8;
    // numbers[2]=3;
    // numbers[3]=6;
    

    // for (int i=0; i < sizeof(numbers)/sizeof(numbers[0]); i++){
    //     std::cout<<numbers[i]<<std::endl;
    // }

    Animal * dog = new Animal();
}