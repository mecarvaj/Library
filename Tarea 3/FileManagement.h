#pragma once
#include <string>
#include <vector>
#include "Library.h"

using namespace std;

namespace FileManagement {
	
	class DataFile{
		string filePath;
	
	public:
		DataFile();
		Library::Library getLibrary();
		void saveLibrary(Library::Library);
	};

}