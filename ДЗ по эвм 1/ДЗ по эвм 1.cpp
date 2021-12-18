//Звездочки 1
/*#include <iostream>
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
}*/

//звездочки 2
/*
#include <iostream>
using namespace std;
int main()
{
	unsigned int n;
	cin >> n;
	for (int i = n; i >0; i--) {
		for (int j = 0; j < i; j++)cout << '*';
		cout << endl;
	}
	system("pause");
	return 0;
}*/

//звездочки 3
/*
#include <iostream>
using namespace std;
int main()
{
	unsigned int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int p = 2 * i - 1;
		for (int pr = 0; pr < (2 * n - 1 - p) / 2; pr++)cout << ' ';
		for (int z = 0; z < p; z++)cout << '*';
		cout << endl;
	}
	for (int i = n-1; i>0; i--) {
		int p = 2 * i - 1;
		for (int pr = 0; pr < (2 * n - 1 - p) / 2; pr++)cout << ' ';
		for (int z = 0; z < p; z++)cout << '*';
		cout << endl;
	}
	system("pause");
	return 0;
}*/

//не помню, что это
/*#include <iostream>
using namespace std;
int main()
{
	int n, k = 0;
	cout << "Input n: ";
	cin >> n;
	cout << n;
	while (n>1) {
		if (n % 2 == 0) {
			n /= 2;
			k++;
			cout << " => " << n;
		}
		else {
			n = 3 * n + 1;
			k++;
			cout << " => " << n;
		}
	}
	cout <<"\n" << k;
	return 0;
}*/


//что-то про сумму длин сторон до точки, треугольником и тп
/*#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double ax, ay, bx, by;
	int e;
	cout << "Input coords a: ";
	cin >> ax >> ay;
	cout << "Input coords b: ";
	cin >> bx >> by;
	double cx, cy;
	cout << "Input coords c: ";
	cin >> cx >> cy;
	cout << "Input accuracy: ";
	cin >> e;
	if (abs(sqrt((cx - ax) * (cx - ax) + (cy - ay) * (cy - ay)) + sqrt((cx - bx) * (cx - bx) + (cy - by) * (cy - by)) - 10.0) < 1.0*pow(10,-e)) {
		cout << "c is belong";
	}
	else cout << "c isn't belong";
	return 0;
}*/


//кол-во целых точек внутри окр-ти
/*#include <iostream>
using namespace std;
int main()
{
	double r;
	int c = 0;
	cout << "Input R: ";
	cin >> r;
	cout << "\n";
	for(int a = -r;a <= r; a++)
		for(int b = -r;b <=r; b++) 
			if (a*a+b*b<=r*r)c++;
	cout<< c;
	return 0;
}*/

//гуси и кролики
/*#include <iostream>
using namespace std;
int main()
{
	int c,g;
	cout << "Count paws: ";
	cin >> c;
	g =(c % 4)/2;
	for (int i = c / 4; i >= 0; i--) {
		cout <<"rabbits: "<<i<<", geese: "<<g << "\n";
		g += 2;
	}
	return 0;
}*/

//число пи с точность до n после запятой
/*#include <iostream>
using namespace std;
int main()
{
	int n;
	cout << "Input accuracy: ";
	cin >> n;
	double pi = 0.0;
	for (int i = 0; i < n; i++) {
		pi += 1.0 / (2 * i + 1) - 1.0 / (2 * i + 3);
	}
	cout << "pi= " << 4*pi;
	return 0;
}*/


//сумма sin(x)+sin(sin(x))+...+sin(...sin(sin(x)))
/*#include <iostream>
#include <cmath>
#define pi 3.14159265
using namespace std;
int main()
{
	double x, s = 0.0;
	int ac;
	cout << "Input deg: ";
	cin >> x;
	cout << "Input accuracy: ";
	cin >> ac;
	for (int i = 0; i < ac; i++) {
		x = sin(x*pi / 180);
		s += x;
	}
	cout << "sum= " << s;
	return 0;
}*/

//сумма и произведение цифр числа
/*#include <iostream>
using namespace std;
int main()
{
	int n,sum=0,pr=1;
	cout << "Input number: ";
	cin >> n;
	while (n > 0) {
		sum += n % 10;
		pr *= n % 10;
		n/=10;
	}
	cout << "Sum= " << sum << "\nProduct= " << pr;
	return 0;
}*/

//день недели
/*#include <iostream>
#include <string>
using namespace std;
int main()
{
	int d, m, y, week, cyear, cmnth1, cmnth2;
	string day[7] = { "Sunday", "Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
	cout << "day:";
	cin >> d;
	cout << "month:";
	cin >> m;
	cout << "year:";
	cin >> y;
	cmnth1 = (14 - m)/12;
	cmnth2 = m-2 + 12 * cmnth1;
	cyear = y - cmnth1;
	week = d + cyear + cyear / 4 - cyear / 100 + cyear / 400 + (31 * cmnth2) / 12;
	cout << day[week % 7];
	return 0;
}*/

//разница между датами
/*#include <iostream>
using namespace std;
int main() {
	int y1, m1, d1, y2, m2, d2,days = 0;
	cin >> d1 >> m1 >> y1 >> d2 >> m2 >> y2;
	int years = y2 - y1;
	int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (years == 0) {
		if (((y1 % 4 == 0 && y1 % 100 != 0) || (y1 % 400 == 0)) && (m1 < 3) && ((m2 >= 3) || (m2 == 2) && (d2 == 29))) {
			days += 1;
		}
		for (int i = m1; i < m2; ++i) {
			days += month[i - 1];
		}
		days = days - d1 + d2;
		cout << days << " days";
	}
	else {
		for (int i = m1; i <= 12; ++i) {
			days += month[i - 1];
		}
		if (((y1 % 4 == 0 && y1 % 100 != 0) || (y1 % 400 == 0)) && (m1 < 3)) {
			days += 1;
		}
		days -= d1;

		if (years > 1) {
			for (int i = 1; i < years; ++i) {
				days += 365;
				if (((y1 + i) % 4 == 0 && (y1 + i) % 100 != 0) || ((y1 + i) % 400 == 0)) {
					days += 1;
				}
			}
		}

		if (((y2 % 4 == 0 && y2 % 100 != 0) || (y2 % 400 == 0)) && ((m2 >= 3) || (d2 == 29) && (m2 == 2))) {
			days += 1;
		}

		for (int i = 1; i < m2; ++i) {
			days += month[i - 1];
		}
		days += d2;
		cout << days;
	}
	return 0;
}*/

//разница по времени
/*#include <iostream>
using namespace std;
int main() {
	int h1, m1, s1, h2, m2, s2, h3, m3, s3;
	cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
	if (s2 >= s1) {
		s3 = s2 - s1;
	}
	else {
		s3 = 60 - s1 + s2;
		m2 -= 1;
	}
	if (m2 >= m1) {
		m3 = m2 - m1;
	}
	else {
		m3 = 60 - m1 + m2;
		h2 -= 1;
	}
	if (h2 >= h1) {
		h3 = h2 - h1;
	}
	else {
		h3 = -1;
		std::cout << "Bad input";
	}
	if (h3 != -1) {
		cout << h3 << " hours " << m3 << " minutes " << s3 << " seconds ";
	}
	return 0;
}*/


//из 10 сс в 16сс
/*#include <iostream>
#include <string>
using namespace std;
int main() {
	int n, rem, counter = 0;
	cin >> n;
	string answer="";
	char letter[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	while (n > 0) {
		rem = n % 16;
		answer = letter[rem]+answer;
		n /= 16;
	}
	cout << answer;
	return 0;
}*/

//римские числа
/*#include <iostream>
#include <string>
using namespace std;
int main() {


	int chislo;
	do {
		cin >> chislo;
	} while (chislo < 1, chislo>3999);
	string rim[13] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
	int arab[] = { 1000, 900,  500,  400, 100, 90,    50,   40, 10,    9,    5,   4,   1 };
	for (int i = 0; i < 13; i++) {
		while (chislo - arab[i] >= 0) {
			cout << rim[i];
			chislo -= arab[i];
		}
	}
	cout << endl;
	return 0;
}*/
