#include <iostream>
#include <fstream>
using namespace std;
int main(int argc,char* argv[])
{
	cout << "argc = " << argc << endl;
	if (argc == 1)cout << "Program name -i source_file - o destinataion_file or " << endl << "Program name - o destinataion_file -i source_file" << endl;
	cout << argv[0] << endl;
	for (size_t k = 1; k < argc; ++k)cout << argv[k] << endl;
	if (argc >= 2) {//open source file
		fstream ifs;
		ifs.open(argv[1], std::ios_base::in | std::ios_base::binary);
		if (ifs.is_open()) {
			ifs.seekg(10);
			unsigned int bitOff = 0;
			ifs.read((char*)&bitOff, sizeof(int));
			cout << "Read bitOff " << bitOff << endl;
			ifs.seekg(18);
			int iWidth = 0, iHeight = 0;
			ifs.read((char*)&iWidth, sizeof(int));
			ifs.read((char*)&iHeight, sizeof(int));
			cout << "Read width " << iWidth << endl;
			cout << "Read height " << iHeight << endl;
			unsigned int bpp=0;
			ifs.seekg(28);
			ifs.read((char*)&bpp, sizeof(short int));
			cout << "Read bpp " << bpp << endl;

			ifs.seekg(bitOff);
			for (size_t rows = 0; rows < iHeight; ++rows) {
				for (size_t cols=0; cols < iWidth; cols+=8) {
					unsigned char bTmp = 0;
					if (ifs.eof())break;
					ifs.read((char*)&bTmp, bpp);
					for (unsigned char mask = 0x80; mask != 0; mask >>= 1) { cout << ((bTmp&mask) == 0) ? 1 : 0;	/*cout << "Mask " << int(mask);*/
					}
				}
				cout << endl;
			}
			ifs.close();
		}
		else cout << "Can't open file " << argv[1] << endl;
	}
}
