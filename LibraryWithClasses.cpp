#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

class Book {
    public:
        Book(string title, int pageCount, int chapterCount) {
            this->title = title;
            this->pageCount=pageCount;
            this->chapterCount=chapterCount;
        }

        string getTitle() {
            return title;
        }

        int getPageCount() {
            return pageCount;
        }

        int getChapterCount() {
            return chapterCount;
        }

    private:
        string title;
        int pageCount;
        int chapterCount;

};

class Catalog {
    public:
        Catalog() {

        }

        void addBook(Book * newBook) {
            books.push_back(newBook);
        }

        int removeBook(string title) {
            for (int i=0; i<books.size(); i++) {
                if (books[i]->getTitle()==title) {
                    books.erase(books.begin()+i);
                    return i;
                } else if (i==books.size()-1) {
                    return -1;
                }
            }
        }

        string listBooks() {
            stringstream ss;
            for (int i=0; i<books.size(); i++) {
                ss<<"Book "<< i+1<<": "<<books[i]->getTitle()<<"\n"
                <<"\tPage count: "<<books[i]->getPageCount()<<"\n"
                <<"\tChapter count: "<<books[i]->getChapterCount()<<"\n";
            }
            return ss.str();
        }

    private:
        vector<Book * > books;
};



int main() {
    Catalog * catalog = new Catalog();

    while(true){
        std::cout<<"1. add a book\n2. remove a book\n3. list all books\n4. exit\n";
        int input;
        std::string titleInput;
        int pageCountInput;
        int chapterCountInput;
        std::cin>>input;
        int index;
        switch (input) {
            case 1:
                std::cout<<"Enter title of the book: ";
                // std::cin>>titleInput;
                cin.ignore();
                getline(cin, titleInput);
                std::cout<<"Enter the page count: ";
                std::cin>>pageCountInput;
                std::cout<<"Enter the chapter count: ";
                std::cin>>chapterCountInput;
                // Book * newBook = new Book(titleInput, pageCountInput, chapterCountInput);
                catalog->addBook(new Book(titleInput, pageCountInput, chapterCountInput));
                std::cout<<"Book has been added\n";
                break;
            case 2:
                std::cout<<"Please give title of the book\n";
                cin.ignore();
                getline(cin, titleInput);
                index = catalog->removeBook(titleInput);
                if(index==-1) {
                    cout<<"Book not found\n";
                } else {
                    cout<<"Book removed from index "<<index<<endl;
                }
                break;
            case 3:
                std::cout<<"Printing all books\n";
                cout<<catalog->listBooks();
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

    return 0;
}