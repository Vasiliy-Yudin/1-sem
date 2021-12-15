#include <iostream>
//#include "stdafx.h"
using namespace std;
int main()
{
	unsigned int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++)cout << '*';
		cout << endl;
	}
	system("pause");
	return 0;
}
