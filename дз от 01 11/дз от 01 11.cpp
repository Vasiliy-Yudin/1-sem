#include <iostream>
#include <ctime>
using namespace std;

/*bool searching(int row, int col,int m[][5]) {
    int n;
	cout << "Input n: ";
    cin >> n;
    for (int i = 0; i < row; i++){
        if (n < m[i][i])continue;
        if (n ==m[i][i])return true;
		else {
            for (int j = 0; j < i; j++) {
                if (m[j][i] < n)continue;
                if (m[j][i] > n)break; 
				else return true;
            }
            for (int k = 0; k < i; k++) {
                if (m[i][k] < n)continue;
                if (m[i][k] > n)break;
				else return true;
            }
            if (n == arr[columns *  || n == arr[i - 1][j + 1]) {
                return 1;
            }
            break;
        }
    }
    return 0;
}*/



//интегральное изображение
void integralImg(int row, int col, int m[][5]) {
	for (int i = 1; i < row; i++)m[i][0] += m[i - 1][0];
	for (int j = 1; j < row; j++)m[0][j] += m[0][j-1];
	for (int i = 1; i < row; i++)for (int j = 1; j < col; j++)m[i][j]+=m[i][j-1]+m[i-1][j];
}

int main()
{
	const int row = 4, col = 5;
	int m[row][col];
	srand(time(0));
	for (int i = 0; i < row; i++)for (int j = 0; j < col; j++)m[i][j] = rand() % 10;
	cout << "Matrix: " << "\n";
	for (int i = 0; i < row; i++) { for (int j = 0; j < col; j++)cout << m[i][j] << " "; cout << "\n"; }
	integralImg(row, col, m);
	cout << "Integral image: " << "\n";
	for (int i = 0; i < row; i++) { for (int j = 0; j < col; j++)cout << m[i][j] << " "; cout << "\n"; }
	return 0;
}

