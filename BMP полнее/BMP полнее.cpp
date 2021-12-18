#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char* argv[]) {
	cout << " argc=" << argc << endl;
	cout << argv[0] << endl;
	for (size_t k = 1; k < argc; ++k) {
		cout << argv[k] << endl;
	}
	int ch;
	int count = 0;
	fstream fs;
	fs.open(argv[1], ios_base::in | ios_base::binary);

	if (!fs.is_open()) {
		cout << "file can't be opened " << endl;
	}
	
	//------------------------------------------------------------------------------------
	//поменять ширину и высоту местами
	/*
	cout << "file opened " << endl;
	fs.seekg(18);
	int width=0, height=0;
	fs.read((char*)&width, sizeof(int));
	fs.read((char*)&height, sizeof(int));
	cout << "width=" << (int)width << endl;
	cout << "height=" << (int)height << endl;
	fs.close();
	ofstream ofs;
	ofs.open(argv[2], ios_base::binary | ios_base::in);
	if (!ofs.is_open()) {
		cout << "Error";
	}
	else {
		ofs.seekp(18, ios::beg);
		ofs.write((char*)&height, sizeof(int));
		ofs.seekp(22, ios::beg);
		ofs.write((char*)&width, sizeof(int));
		ofs.close();
	}

	width = 0; height = 0;*/

	//33*32
	/*unsigned int bpp = 0;
	fs.seekg(28);
	fs.read((char*)&bpp, sizeof(int));
	cout << "bpp: " << bpp << endl;
	fs.seekg(18);
	unsigned int width = 0, height = 0;
	fs.read((char*)&width, sizeof(int));
	fs.read((char*)&height, sizeof(int));
	cout << "width=" << width << endl;
	cout << "height=" << height << endl;
	int bitoffBits = 0;
	fs.seekg(10);
	fs.read((char*)&bitoffBits, sizeof(int));
	cout << "BitoffBits= " << bitoffBits << endl;
	fs.seekg(bitoffBits);
	for (size_t rows = 0; rows < height; ++rows) {
		unsigned char ost = 0,lish = 0;
		for (size_t cols = 0; cols < width/32*32; cols += 8) {
			unsigned char bTmp = 0;
			fs.read((char*)&bTmp, 1);
			if (fs.eof())break;
			for (unsigned char mask = 0x80; mask != 0; mask >>= 1)cout << (((bTmp & mask) == 0) ? '1' : '0');
		}
		fs.read((char*)&ost, width % 32);
		for (unsigned char mask = 0x80; mask != 0; mask >>= 1) {
			cout << (((ost & mask) == 0) ? '1' : '0');
			break;
		}
		for (int i = 0; i < 3; ++i) {
			fs.read((char*)&lish, 1);
		}
		cout << endl;
	}*/



}
