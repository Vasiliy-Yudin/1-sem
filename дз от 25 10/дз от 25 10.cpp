//задания с целочисленным массивом
/*#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	const int N = 15;
	int m[N];
	int min=10000000, sum = 0,mi;
	double sr_ar=0.0;
	srand(time(0));
	//инициализация и нахождение мин эл-та и суммы
	for (int i = 0; i < N; i++) {
		m[i] = 1 + rand() % 16;
		if (m[i] < min){
			min = m[i];
			mi = i;
		}
		sum += m[i];
	}
	for (int i = 0; i < N; i++)cout << m[i] << " ";
	cout << endl;
	//среднее арифм.
	sr_ar = (double)sum / 10;

	//перевернутый массив
	int h = 0;
	for (int i = 0; i < N/2;i++){
		h = m[i];
		m[i] = m[N - 1 - i];
		m[N - 1 - i] = h;
	}
	for (int i = 0; i < N; i++)cout << m[i] << " ";
	cout << endl;
	//сначала числа до сред знач, потом после среднему значению
	int m1[N];
	vector<int> v1, v2;
	for (int i = 0; i < N; i++) {
		if (m[i] < sr_ar)v1.push_back(m[i]);
		else v2.push_back(m[i]);
	}
	for (int i = 0; i < v1.size(); i++)m[i] = v1[i];
	for (int i = 0; i < v2.size(); i++)m[v1.size()+i] = v2[i];
	//самое повторяющееся число
	vector<int> vc;
	int maxcnt = 0, maxcounter = 0;
	int mc[N];
	for (int i = 0; i < N; i++)mc[i] = m[i];
	sort(mc, mc + N);
	for (int i = 0; i < N-1; i++) {
		bool f = true;
		int count = 1;
		for (int j = 0; j < vc.size(); j++)if (mc[i] == vc[j])f = false;
		if (f){
			vc.push_back(mc[i]);
			for (int j = i + 1; j < N; j++)if (mc[j] == mc[i])count++;
		}
		if (count >= maxcnt) { maxcnt = count; maxcounter = mc[i]; }
	}
	cout<< "minimal= " << min << ", his index= " << mi << "\n";
	cout << "average= " << sr_ar<< "\n";
	cout << "sorted with average and reversed " <<"\n";
	for (int i = 0; i < N; i++)cout << m[i] << " ";
	cout << "\nmaximum counted number= " << maxcounter << ", count= " << maxcnt << endl;
	cout <<endl;
	return 0;
}*/


//число 16сс
/*#include <iostream>
#include <ctime>
using namespace std;
int main() {
	char c[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	int n;
	cout << "Input n: ";
	cin >> n;
	srand(time(0));
	char* m = new char[n];
	m[0] = c[rand() % 16==0?1:rand()%16];
	for (int i = 1; i < n; i++)m[i] =c[rand() % 16];
	for (int i = 0; i < n; i++)cout << m[i];
	return 0;
}*/


//массив с упорядоченными парами из 2 массивов
/*#include <iostream>
#include <algorithm>
int main() {
	int m1[4] = { -1,3,54,-30 }, m2[4] = { -5, 7,23,-25 },m[8];
	for (int i = 0; i < 4; i++) {
		m[2 * i] = std::min(m1[i], m2[i]);
		m[2 * i+1] = std::max(m1[i], m2[i]);
	}
	for (int i = 0; i < 8; i++)std::cout << m[i] << " ";
	return 0;
}*/


//двумерный массив
/*#include <iostream>
#include <ctime>
using namespace std;
void printArr(const int row, const int col, int m[][3]) {
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)cout << m[i][j] << " ";
		cout << endl;
	}
}

//массив столбцами в обратном порядке
void chCol( const int row, const int col, int m[][3]) {
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col / 2; j++) {
			int prom = m[i][j];
			m[i][j] = m[i][col - 1 - j];
			m[i][col - 1 - j] = prom;
		}
}
//массив строками в обратном порядке
void chRow( const int row, const int col, int m[][3]) {
	for (int i = 0; i < row / 2; ++i)
		for (int j = 0; j < col; ++j) {
			int prom = m[i][j];
			m[i][j] = m[row - 1 - i][j];
			m[row - 1 - i][j] = prom;
		}
}

//транспонирование
void trans( const int row, const int col, int m[][3]) {
	for (int i = 0; i < row; i++)
		for (int j = 0; j < i; j++){
			int prom = m[i][j];
			m[i][j] = m[j][i];
			m[j][i] = prom;
		}
}

int main()
{
	srand(time(0));
	int i;
	const int row = 3, col = 3;
	int m[row][col];
	for (int i = 0; i < row; i++)for (int j = 0; j < col; j++)m[i][j] = 1 + rand() % 100;
	printArr(row, col,m);  
	chCol(row, col, m);
	cout << "\n" << "Changed columns: " << "\n";
	printArr(row, col, m);
	chRow(row, col,m);
	cout << "\n" << "Changed rows: " << "\n";
	printArr(row, col, m);
	trans(row, col, m);
	cout << "\n" << "Transposed matrix:" << "\n";
	printArr(row, col, m);
	return 0;
}*/