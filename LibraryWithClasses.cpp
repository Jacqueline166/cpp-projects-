#include <iostream>
#include <vector>
#include <sstream>
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
        string listBooks() {
            stringstream ss;
            for (int i=0; i<books.size(); i++) {
                ss<<"Book "<<i+1<<*books[i]<<"\n";
            }
            return ss.str();
        }

    private:
        vector<Book * > books;
};



int main() {
    Book * harryPotter = new Book("Harry Potter", 500, 50);

    // cout<<harryPotter->getTitle()<<endl;

    Catalog * catalog = new Catalog();

    catalog->addBook(harryPotter);

    cout<<catalog->listBooks()<<endl;

    return 0;
}