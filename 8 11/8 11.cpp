#include <iostream>
using namespace std;

void snake(int row, int col, int** m) {
	int ch = 1;
	for (int i = 0; i < row; i += 2) {
		for (int j = 0; j < col; j++) {
			m[i][j] = ch;
			ch++;
		}
		ch = ch + col;
	}
	ch = col + 1;
	for (int i = 1; i < row; i += 2) {
		for (int j = col-1; j>=0; j--) {
			m[i][j] = ch;
			ch++;
		}
		ch = ch + col;
	}
}


void diag( int row, int col, int** m) {
	int ch = 1;
	for (int p = 1; p <= row + col - 1; p++) {
		for (int i = 0, j = p - 1; i < p; i++, j--) {
			if (p % 2 == 0) {
				if (i < row & j < col)m[i][j] = ch++;
				else continue;
			}
			else {
				if (j < row & i < col)m[j][i] = ch++;
				else continue;
			}
		}
	}
}

void spiral(int** m, int row, int col) {
	int ch = 1,max;
	row >= col ? max = row : max = col;
	for (int i = 0; i < max / 2; ++i) {
		if (ch > row * col) break;
		for (int j = i; j < col - i; ++j)m[i][j] = ch++;
		if (ch > row * col) break;
		for (int k = i + 1; k < row - i; ++k)m[k][col - 1 - i] = ch++;
		if (ch > row * col) break;
		for (int j = col - i - 2; j > i; --j)m[row - i - 1][j] = ch++;
		if (ch > row * col) break;
		for (int k = row - i - 1; k > i; --k)m[k][i] = ch++;
	}
	if ((row % 2) && (row == col))m[row / 2][col / 2] = ch;
}


int main()
{
	//1-мерный динам массив
	/*int n, firstn;
	cout << "Input n: ";
	cin >> n;
	cout << "Input first num: ";
	cin >> firstn;
	int* m = new int[n];
	for (int i = 0; i < n; i++)m[i] = i + firstn;
	for (int i = 0; i < n; i++)cout << m[i] << " ";
	delete[] m;*/
	int row, col;
	cout << "\nMatrix rows and cols: ";
	cin >> row >> col;
	int** M = new int*[row];
	for (int i = 0; i < row; ++i) {
		M[i] = new int[col];
	}
	snake(row, col, M);
	cout << "Snake: "<<"\n";
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)cout << M[i][j] << " ";
		cout << "\n";
	}
	cout << "\nDiag snake: " << "\n";
	diag(row, col, M);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)cout << M[i][j] << " ";
		cout << "\n";
	}
	cout << endl;
	spiral(M, row, col);
	cout << "\nSpiral: " << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)cout << M[i][j] << " ";
		cout << "\n";
	}
}
