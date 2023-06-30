#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

//1. Adult books 2. Children’s books 3. Teen books 4. Media Center (CDs, DVDs, Audiobooks)

enum Section {
    ADULT,
    CHILDREN,
    TEEN,
    MEDIA,  
    OTHER
};



enum Bookshelf {
    A_TO_H,
    I_TO_S,
    T_TO_Z,
    NUMBERS,
    NONE

};

string toString(Section section) {
    switch(section) {
        case ADULT:
            return "Adult";
        case CHILDREN:
            return "Children";
        case TEEN:
            return "Teen";
        case MEDIA:
            return "Media";
        case OTHER:
            return "Other";
        default:
            return NULL;
    }
}


string toString(Bookshelf bookshelf) {
    switch(bookshelf) {
        case A_TO_H:
            return "A to H";
        case I_TO_S:
            return "I to S";
        case T_TO_Z:
            return  "T to Z";
        case NUMBERS:
            return "Numbers";
        default:
            return NULL;

    }

}
class Book {
    public:
        Book(string title, string section, int pageCount, int chapterCount) {
            this->title = title;
            this->pageCount=pageCount;
            this->chapterCount=chapterCount;
            string sectionLower=section;
            // TODO: add support for uppercase and lowercase section names
            // transform(section.begin(), section.end(), sectionLower.begin(), tolower);
            // cout<<sectionLower<<endl;
            if(sectionLower=="adult") {
                this->section=ADULT;
            } else if (sectionLower=="children") {
                this->section=CHILDREN;
            } else if (sectionLower=="teen") {
                this->section=TEEN;
            } else if (sectionLower=="media") {
                this->section=MEDIA;
            } else {
                this->section=OTHER;
            }
            if((title[0]>='a'&&title[0]<='h')||(title[0]>='A'&&title[0]<='H')) {
                bookshelf=A_TO_H;
            } else if((title[0]>='i'&&title[0]<='s')||(title[0]>='I'&&title[0]<='S')) {
                bookshelf=I_TO_S;
            } else if((title[0]>='t'&&title[0]<='z')||(title[0]>='T'&&title[0]<='Z')) {
                bookshelf=T_TO_Z;
            } else {
                bookshelf=NUMBERS;
            }
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

        Bookshelf getBookshelf() {
            return bookshelf;
        }

        Section getSection() {
            return section;
        }

    private:
        string title;
        int pageCount;
        int chapterCount;
        Section section;
        Bookshelf bookshelf;

};

class Catalog {
    public:
        Catalog() {

        }

        void addBook(Book * newBook) {
            books.push_back(newBook);
        }

        bool removeBook(string title) {
            for (int i=0; i<books.size(); i++) {
                if (books[i]->getTitle()==title) {
                    books.erase(books.begin()+i);
                    return true;
                }
            } 
            return false;
        }

        Book * searchBook(string title) {
            for (int i=0; i<books.size(); i++) {
                if (books[i]->getTitle()==title) {
                    return books[i];
                }
            } 
            return nullptr;
        }

        string listBooks() {
            stringstream ss;
            for (int i=0; i<books.size(); i++) {
                ss<<"Book "<<i+1<<": "<<books[i]->getTitle()<<"\n"
                <<"\tPage count: "<<books[i]->getPageCount()<<"\n"
                <<"\tChapter count: "<<books[i]->getChapterCount()<<"\n"
                <<"\tBookshelf: "<<toString(books[i]->getBookshelf())<<"\n"
                <<"\tSection: "<<toString(books[i]->getSection())<<"\n";
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
        string sectionInput;
        bool foundBook;
        std::cin>>input;
        Book * book;
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
                std::cout<<"What kind of book is "<<titleInput<<"? ";
                cin.ignore();
                getline(cin, sectionInput);
                // Book * newBook = new Book(titleInput, pageCountInput, chapterCountInput);
                catalog->addBook(new Book(titleInput, sectionInput, pageCountInput, chapterCountInput));
                std::cout<<"Book has been added\n";
                break;
            case Action::REMOVE_BOOK:
                std::cout<<"Please give title of the book\n";
                cin.ignore();
                getline(cin, titleInput);
                foundBook = catalog->removeBook(titleInput);
                if(!foundBook) {
                    cout<<"Book not found\n";
                } else {
                    cout<<"Removed book"<<endl;
                }
                break;
            case Action::SEARCH_BOOK:
                cout<<"Enter title of the book\n";
                cin.ignore();
                getline(cin, titleInput);
                book = catalog->searchBook(titleInput);
                if(book) {
                    cout<<"Book has been found on bookshelf "<<toString(book->getBookshelf())<<" in section "<<toString(book->getSection())<<endl;
                } else {
                    cout<<"Book not found\n";
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