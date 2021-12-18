#include <iostream>
using namespace std;

//Создание 2-мерного массива
int** createArr(int row, int col) {
	int** A=new int*[row];
	for (int i = 0; i < row; i++) {
		A[i] = new int[col];
	}
	return A;
}

//Освобождение ресурсов, занимаемых данным массивом
void deleteArr(int** A, int row) {
	for (int i = 0; i < row; i++)
	{
		delete[] A[i];
	}
	delete[] A;
}

//Инициализация по заданному значению.
void initArray(int** A, int row, int col, int x) {
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			A[i][j] = x;
		}
}

//Единичная матрица
int** eMatrix(int** A, int row, int col) {
	for (int i = 0; i < row;i++)
		for (int j = 0; j < col; j++) {
			if (i == j)A[i][i] = 1;
			else A[i][j] = 0;
		}
	return A;
}

//Транспонирование
int** transpMatrix(int** A, int row, int col) {
	int **N = createArr(row, col);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col;j++) {
			N[i][j] = A[j][i];
		}
	return N;
}

//Поворот на 180гр
int** return180Array(int** A, int row, int col) {
	int** B = createArr(row, col);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			B[i][j] = A[row - i - 1][col - j - 1];
		}
	return B;
}

//Умножение матрицы на число
int** productMatrix(int** A, int row, int col, int num) {
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			A[i][j] *= num;
		}
	return A;
}

//Создание матрицы, как результата умножения матрицы на число
int** CreateProductMatrix(int** A, int row, int col, int num) {
	int** B = createArr(row, col);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			B[i][j] = A[i][j] * num;
		}
	return B;
}

//Сложение двух матриц
int** sumMatrix(int** A, int** B, int row, int col) {
	int** C;
	C = createArr(row, col);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			C[i][j] = A[i][j] + B[i][j];
		}
	return C;
}

//Умножение матриц
int** multMatrix(int** A, int row1, int column1, int** B, int row2, int column2) {
	if (column1 != row2)cout << "N0";
	else {
		int** C=new int*[row1];
		for (int i = 0; i < row1; i++)
		{
			C[i] = new int[column2];
			for (int j = 0; j < column2; j++)
			{
				C[i][j] = 0;
				for (int k = 0; k < column1; k++)
					C[i][j] += A[i][k] * B[k][j];
			}
		}
		return C;
	}
}

//Обмен местами строк
int** swapRows(int** A, int row, int column, int rowFirst, int rowSec) {
	int tmp = 0;
	for (int i = 0; i < column; ++i) {
		tmp = A[rowSec - 1][i];
		A[rowSec - 1][i] = A[rowFirst - 1][i];
		A[rowFirst - 1][i] = tmp;
	}
	return A;
}

//обмен местами столбцов
void swapColumns(int** A, int row, int column, int colFirst, int colSec) {
	int tmp = 0;
	for (int i = 0; i < row; ++i) {
		tmp = A[i][colFirst - 1];
		A[i][colFirst - 1] = A[i][colSec - 1];
		A[i][colSec - 1] = tmp;
	}
}

//Получение доступа к элементу по индексу
int& getElement(int** A, int row, int col) {
	return A[row - 1][col - 1];
}

void printArr(int** A, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)cout << A[i][j] << "\t";
		cout << std::endl;
	}
}

void fill(int** A, int row, int col) {
	for (int i = 0; i < row; i++)for (int j = 0; j < col; j++)A[i][j] = rand() % 10;
}


int main()
{
	int** A;
	int** B;
	int** D;
	int** C;
	int** V;
	int row, column, yr_const = 0, number = 1;
	int row1, column1, row2, column2;
	int rowFirst, colFirst, rowSec, colSec;
	int yourRow, yourColumn;
	cout << "razmer row and column:\n";
	cin >> row >> column;
	V = createArr(row, column);
	cout << "E matrix: " << endl;
	D = eMatrix(V, row, column);
	printArr(D, row, column);
	cout << endl;
	cout << "3.const array: " << endl;
	cout << "Input num :\n";
	cin >> yr_const;
	initArray(V, row, column, yr_const);
	printArr(V, row, column);
	cout << "Tronsponite: " << endl;
	fill(V, row, column);
	cout << "Before: " <<endl;
	printArr(V, row, column);
	cout << endl;
	V = transpMatrix(V, row, column);
	cout << "Become: " << endl;
	printArr(V, row, column);
	cout <<endl;
	cout << "180 degrees: " << endl;
	D = return180Array(V, row, column);
	printArr(D, row, column);
	cout << "Product matrix and number: " << endl;
	V = productMatrix(V, row, column, number = 2);
	printArr(V, row, column);
	cout << "Creating product matrix and number: " << endl;
	B = CreateProductMatrix(V, row, column, 2);
	printArr(B, row, column);
	cout << "--------------------9.sum Matrix-------------------------------" << endl;
	A = createArr(row, column);
	fill(A, row, column);
	printArr(A, row, column);
	cout << endl;
	fill(B, row, column);
	printArr(B, row, column);
	cout << endl;
	cout << "Matrix A + B= " << endl;
	C = sumMatrix(A, B, row, column);
	printArr(C, row, column);
	cout << endl;
	cout << "Product matri: " << endl;
	cout << "Input row and column: \n";
	cin >> row1 >> column1;
	D = createArr(row1, column1);
	fill(D, row1, column1);
	printArr(D, row1, column1);
	cout << "razmer row2 and column2:\n";
	cin >> row2 >> column2;
	fill(B, row2, column2);
	printArr(B, row2, column2);
	cout << std::endl;
	cout << "Matrix A * B" << endl;
	C = multMatrix(D, row1, column1, B, row2, column2);
	printArr(C, row1, column2);
	cout << "Swap rows or columns: " <<endl;
	cout << endl;
	fill(A, row, column);
	printArr(A, row, column);
	cout << endl;
	cout << "Input 2 rows for swap: \n";
	cin >> rowFirst >> rowSec;
	swapRows(A, row, column, rowFirst, rowSec);
	printArr(A, row, column);
	cout << endl;
	cout << "Input 2 columns for swap: \n";
	cin >> colFirst >> colSec;
	swapColumns(A, row, column, colFirst, colSec);
	printArr(A, row, column);
	cout << endl;
	cout << "Get element: " << std::endl;
	cout << "Input index: \n";
	cin >> yourRow >> yourColumn;
	cout << getElement(A, yourRow, yourColumn);
	cout << endl;
	deleteArr(C, row1);
	deleteArr(V, row);
	deleteArr(B, row);
	deleteArr(A, row);
}
