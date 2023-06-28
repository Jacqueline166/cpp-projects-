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
                }
            } 
            return -1;
        }

        int searchBook(string title) {
            for (int i=0; i<books.size(); i++) {
                if (books[i]->getTitle()==title) {
                    return i;
                }
            } 
            return -1;
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

enum Action {
    ADD_BOOK = 1,
    REMOVE_BOOK = 2,
    SEARCH_BOOK = 3,
    LIST_BOOKS = 4,
    EXIT = 5
};

int main() {
    Catalog * catalog = new Catalog();

    while(true){
        std::cout<<"1. add a book\n2. remove a book\n3. Search for a book\n4. list all books\n5. Exit\n";
        int input;
        std::string titleInput;
        int pageCountInput;
        int chapterCountInput;
        std::cin>>input;
        int index;
        switch (input) {
            case Action::ADD_BOOK:
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
            case Action::REMOVE_BOOK:
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
            case Action::SEARCH_BOOK:
                cout<<"Enter title of the book\n";
                cin.ignore();
                getline(cin, titleInput);
                index = catalog->searchBook(titleInput);
                if(index==-1) {
                    cout<<"Book not found\n";
                } else {
                    cout<<"Book has been found at index "<<index<<endl;
                }
                break;
            case Action::LIST_BOOKS:
                std::cout<<"Printing all books\n";
                cout<<catalog->listBooks();
                std::cout<<"Finished printing books\n";
                break;
            case Action::EXIT:
                std::cout<<"Exited";
                return 0;
                break;
            default:
                std::cout<<"Invalid Input\n";
        };
        std::cin.clear();
    }

    return 0;
}