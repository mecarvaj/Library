#include <iostream>
#include "Library.h"
#include "FileManagement.h"

using namespace std;

int main()
{
    //Declarations
    string option{};
    FileManagement::DataFile txtFile{};
    Library::Library library{};
    library = txtFile.getLibrary();
    
    while (true)
    {
        //Menu
        cout << "\nSelect the option you want: \n";
        cout << "1. Add a book\n";
        cout << "2. Remove a book\n";
        cout << "3. View all books\n";
        cout << "4. Quit\n\n->";
        cin >> option;
        if (option == "1")
        {
            //Add a book
            string title, author, isbn;
            system("cls");
            cin.ignore();
            cout << "Adding a book\n";
            cout << "\nPlease input the title of the book: \n";
            getline(cin, title);
            cout << "\nPlease input the author of the book: \n";
            getline(cin, author);
            cout << "\nPlease input the ISBN of the book: \n";
            getline(cin, isbn);
            library.addBook(Library::Book{ title,author,isbn });
        }
        else if (option == "2")
        {
            //Delete a book using ISBN
            string isbn{};
            cout << "\nPlease input the ISBN of the book you want to remove\n";
            cin >> isbn;
            library.deleteBook(isbn) ? cout << "\nISBN found, Book was deleted\n":
                cout << "\nISBN not found, Book was not deleted\n";
        }
        else if (option == "3")
        {
            //View all books
            system("cls");
            cout << "Viewing al library\n";
            library.listBooks();
        }
        else if (option == "4")
        {
            //Exit and save
            txtFile.saveLibrary(library);
            break;
        }
        else
        {
            //42 is not a valid answer
            system("cls");
            cout << "Please select a valid option\n";
        }
    }
    
}