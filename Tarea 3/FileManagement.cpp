#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#include "FileManagement.h"

using namespace std;

namespace FileManagement {

	DataFile::DataFile() {
		this->filePath = "LibraryBackup.csv";
	}

	Library::Library DataFile::getLibrary()
	{
		ifstream backUpFile{};
		backUpFile.open(this->filePath, ios::in);

		Library::Library newLibrary{};

		if (!backUpFile.is_open()) {
			cout << "Error opening the file\n";
			cout << "The library was reestablished\n\n\n";
			return newLibrary;
		}
		for (string line; getline(backUpFile, line);)
		{
			
			string title{}, author{}, isbn{};

			stringstream ss{ line };

			getline(ss, title, ',');
			getline(ss, author, ',');
			getline(ss, isbn, ',');

			Library::Book newBook{ title, author,isbn };
			newLibrary.addBook(newBook);
		}
		backUpFile.close();

		return newLibrary;
	}
	void DataFile::saveLibrary(Library::Library library)
	{
		ofstream outputFile(this->filePath);
		for (Library::Book& book : library.getVector()) {
			outputFile << book.GetTitle() << "," << book.GetAuthor() << "," << book.GetISBN() << endl;
		}
		outputFile.close();
	}
}