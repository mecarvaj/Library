#pragma once
#include <string>
#include <vector>


using namespace std;

namespace Library {


	class Book
	{
	private:
		string title;
		string author;
		string ISBN;
	public:
		//Constructors
		Book();
		Book(string pTitle, string pAuthor, string pIsbn);
		~Book();

		//Getters and setters
		void SetTitle(string pTitle);
		string GetTitle();
		void SetAuthor(string pAuthor);
		string GetAuthor();
		void SetISBN(string pIsbn);
		string GetISBN();
	};

	class Library {
		vector<Book> library;
	public:
		Library();
		~Library();
		bool deleteBook(string pIsbn);
		void addBook(Book pBook);
		void listBooks();
		vector<Book> getVector();
	};
}