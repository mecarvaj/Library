#include "Library.h"
#include <iostream>


namespace Library {
    
    //Constructor Books
    Book::Book()
    {
    }
    Book::Book(string pTitle, string pAuthor, string pIsbn) 
    {
        this->title = pTitle;
        this->author = pAuthor;
        this->ISBN = pIsbn;
    }
    Book::~Book()
    {
    }

    // Getters and setters
    void Book::SetTitle(string pTitle) 
    {
        this->title = pTitle;
    }

    string Book::GetTitle() 
    {
        return this->title;
    }

    void Book::SetAuthor(string pAuthor) 
    {
        this->author = pAuthor;
    }

    string Book::GetAuthor() 
    {
        return this->author;
    }

    void Book::SetISBN(string pIsbn) 
    {
        this->ISBN = pIsbn;
    }

    string Book::GetISBN() 
    {
        return this->ISBN;
    }



    //Library methods
    Library::Library()
    {
    }
    
    Library::~Library()
    {
    }
    
    bool Library::deleteBook(string pIsbn)
    {
        bool foundBook{false};
        for (auto iteratorBook = this->library.begin(); iteratorBook != this->library.end(); ++iteratorBook) {
            if (iteratorBook->GetISBN() == pIsbn) {
                foundBook = true;
                this->library.erase(iteratorBook);
                return foundBook;
            }
        }
    }

    void Library::addBook(Book pBook)
    {
        this->library.push_back(pBook);
    }
    
    void Library::listBooks()
    {
        for (auto& book : this->library) {
            cout << "\n##################" << endl;
            cout << "Title: " << book.GetTitle() << endl;
            cout << "Author: " << book.GetAuthor() << endl;
            cout << "ISBN: " << book.GetISBN() << endl;
            cout << "##################\n";
            
        }
        cout << "\n\n---LAST LINE---\n\n";
    }
    vector<Book> Library::getVector()
    {
        return this->library;
    }


 }