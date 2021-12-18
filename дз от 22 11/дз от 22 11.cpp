#include <iostream>
#include <fstream>
#include <string>
//копирование файла через .get() 
void copyFile(std::string s, std::string sc) {
	std::fstream fs;
	fs.open(s, std::ios_base::in);
	if (!fs.is_open()) {
		std::cout << "file can't be opened " << std::endl;
	}
	if (fs.is_open()) {
		std::cout << "file opened " << std::endl;

		std::fstream outFile;
		outFile.open(sc, std::ios_base::out | std::ios_base::trunc);
		if (outFile.is_open()) {
			std::cout << "file opened " << std::endl;

			while (true) {
				char c = fs.get();
				if (fs.eof()) break;
				outFile.put(c);
			}
			outFile.close();
		}
	}
	fs.close();
	std::cout << "copy finished! check your file!\n";
}

//вывод каждого 4го байта в консоль /get() & seekg()
void output4bytes(std::string s) {
	std::fstream fs;
	fs.open(s, std::ios_base::in | std::ios_base::binary);
	if (!fs.is_open()) {
		std::cout << "file can't be opened " << std::endl;
	}
	if (fs.is_open()) {
		std::cout << "file opened " << std::endl;
		char c;
		while (!fs.eof()) {
			fs.seekg(3, std::ios_base::cur);
			c = fs.get();
			std::cout << c;
			if (fs.tellg() == EOF) {
				break;
			}
		}

		fs.close();
	}
	std::cout << "\nfinished!\n";
}


//вывод каждого 4го байта в консоль read()
void outever4bytes(std::string s) {
	std::fstream fs;
	fs.open(s, std::ios_base::in | std::ios_base::binary);
	if (!fs.is_open()) {
		std::cout << "file can't be opened " << std::endl;
	}
	if (fs.is_open()) {
		std::cout << "file opened " << std::endl;
		fs.seekg(0, std::ios_base::end);
		unsigned int sizeoffile = fs.tellg();

		for (size_t i = 3; i < sizeoffile; i += 4)
		{
			int buffer = 0;
			fs.seekg(i);
			fs.read((char*)&buffer, sizeof(char));
			std::cout << (char)buffer;
		}

		fs.close();
	}
	std::cout << "\nfinished!\n";
}


int main(int argc, char* argv[]) {

	copyFile(argv[0],argv[1]);
	output4bytes(argv[0]);
	outever4bytes(argv[0]);


}