#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int last_digit(const std::string &str1, const std::string &str2) {
	if ((str1[str1.length() - 1] == '0')&(str2 != "0"))return 0;
	int n = str1[str1.length() - 1] - 48, st;
	str2.length() > 1 ? st = (str2[str2.length() - 2] - 48) * 10 + (str2[str2.length() - 1] - 48) : st = str2[str2.length() - 1] - 48;
	if (st == 0 & str2.length() > 1)return (int)pow(n, 4) % 10;
	if (st % 4 != 0)return (int)pow(n, st % 4) % 10;
	if (st == 0)return 1;
	return (int)pow(n, 4) % 10;
}


int maxSequence(const std::vector<int>& arr) {
	int mx = 0, tek = 0;
	for (int i = 0; i < arr.size(); i++) {
		tek = max(tek + arr[i], arr[i]);
		mx = max(tek, mx);
	}
	return mx;
}

int cycle(int n) {
	if (n == 1 || n % 5 == 0 || n % 2 == 0)return -1;
	int x = 1, k = 0;
	do {
		x %= n;
		x *= 10;
		k++;
	} while (x%n != 1);
	return k;
}

class HiddenSeq
{
public:
	static unsigned long long fcn(int n) {
		return pow(2, n);
	}
};

bool narcissistic(int value) {
	int val = value;
	int sum = 0;
	int dig = std::to_string(value).length();
	while (value > 0) {
		sum += pow(value % 10, dig);
		value /= 10;
	}
	return sum == val;
}

vector<int> tribonacci(vector<int> signature, int n)
{
	if (n == 0)return {}; if (n == 0)return {};
	vector<int> result;
	if (n == 1)return { signature[0] };
	if (n == 2)return { signature[0],signature[1] };
	result.push_back(signature[0]);
	result.push_back(signature[1]);
	result.push_back(signature[2]);
	for (int i = 3; i < n; i++) {
		result.push_back(result[i - 3] + result[i - 2] + result[i - 1]);
	}
	return result;
}

int digital_root(int n)
{
	if (n / 10 == 0)return n;
	int sum = 0;
	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}
	return digital_root(sum);
}

string duplicate_encoder(const string& word) {
	string s = word;
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	string ns = "";
	for (int i = 0; i < s.length(); i++)
		if (count(s.begin(), s.end(), s[i]) == 1)ns += "(";
		else ns += ")";
	return ns;
}

std::string createPhoneNumber(const int arr[10]) {
	return "(" + to_string(arr[0]) + to_string(arr[1]) + to_string(arr[2]) + ") " + to_string(arr[3]) + to_string(arr[4]) + to_string(arr[5]) + "-" + to_string(arr[6]) + to_string(arr[7]) + to_string(arr[8]) + to_string(arr[9]);
}

static long findMissing(std::vector<long> list) {
	long d = (list[list.size() - 1] - list[0]) / long(list.size());
	for (int i = 1; i < list.size(); i++)
		if (list[i] - list[i - 1] != d)return list[0] + d * i;
	return list[0];
}

unsigned int countBits(unsigned long long n) {
	int c = 0;
	while (n > 0) {
		if (n % 2 == 1)c++;
		n /= 2;
	}
	return c;
}

int countSmileys(std::vector<std::string> arr)
{
	int c = 0;
	for (int i = 0; i < arr.size(); i++) {
		bool f = true;
		if (arr[i].length() == 3) {
			if (arr[i][0] != ':' & arr[i][0] != ';')f = false;
			if (arr[i][1] != '-' & arr[i][1] != '~')f = false;
			if (arr[i][2] != ')' & arr[i][2] != 'D')f = false;
		}
		else if (arr[i].length() == 2) {
			if (arr[i][0] != ':' & arr[i][0] != ';')f = false;
			if (arr[i][1] != ')' & arr[i][1] != 'D')f = false;
		}
		else f = false;
		if (f)c++;
	}
	return c;
}

bool is_square(int n)
{
	if (n < 0)return false;
	if (sqrt(n) == double(int(sqrt(n))))return true;
	return false;
}

long sumTwoSmallestNumbers(std::vector<int> numbers)
{
	sort(numbers.begin(), numbers.end());
	return numbers[0] + numbers[1];
}

int find_short(std::string s)
{
	s += " ";
	int min = s.length();
	while (s.find(' ') != -1) {
		int p = s.find(' ');
		if (p < min)min = p;
		s = s.substr(p + 1);
	}
	return min;
}

bool isAscOrder(std::vector<int> arr)
{
	if (arr.size() == 1)return true;
	for (int i = 1; i < arr.size(); i++)
		if (arr[i] < arr[i - 1])return false;
	return true;
}

bool isAnagram(std::string s1, std::string s2) {
	int k1, k2;
	if (s1.length() != s2.length())return false;
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] <= 'Z'&s1[i] >= 'A') {
			k1 = count(s1.begin(), s1.end(), s1[i]) + count(s1.begin(), s1.end(), s1[i] + 32);
			k2 = count(s2.begin(), s2.end(), s1[i]) + count(s2.begin(), s2.end(), s1[i] + 32);
			if (k1 != k2)return false;
		}
		else {
			k1 = count(s1.begin(), s1.end(), s1[i]) + count(s1.begin(), s1.end(), s1[i] - 32);
			k2 = count(s2.begin(), s2.end(), s1[i]) + count(s2.begin(), s2.end(), s1[i] - 32);
			if (k1 != k2)return false;
		}
	}
	return true;
}

bool is_isogram(std::string s) {
	int k;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] <= 'Z'&s[i] >= 'A')k = count(s.begin(), s.end(), s[i]) + count(s.begin(), s.end(), s[i] + 32);
		else k = count(s.begin(), s.end(), s[i]) + count(s.begin(), s.end(), s[i] - 32);
		if (k > 1)return false;
	}
	return true;
}

std::string DNAStrand(const std::string& dna)
{
	std::string s = "";
	for (int i = 0; i < dna.length(); i++) {
		switch (dna[i]) {
		case 'A': {s += 'T'; break; }
		case 'T': {s += 'A'; break; }
		case 'C': {s += 'G'; break; }
		case 'G': {s += 'C'; break; }
		}
	}
	return s;
}

bool XO(const std::string& s)
{
	return count(s.begin(), s.end(), 'o') + count(s.begin(), s.end(), 'O') == count(s.begin(), s.end(), 'x') + count(s.begin(), s.end(), 'X');
}

string get_middle(string s)
{
	if (s.length() % 2 == 1)return s.substr(s.length() / 2, 1);
	return s.substr(s.length() / 2 - 1, 2);
}

string reverse_words(string s)
{
	string s1 = "", sl = "";
	s = " " + s;
	for (int i = s.length() - 1; i >= 0; i--) {
		if (s[i] != ' ')sl += s[i];
		else { s1 = sl + " " + s1; sl = ""; }
	}
	return s1.substr(0, s1.length() - 1);
}

int twice_as_old(int dad, int son) {
	return abs(dad - 2 * son);
}

std::string bool_to_word(bool value)
{
	return value ? "Yes" : "No";
}

int opposite(int number)
{
	return -number;
}

std::string number_to_string(int num) {
	return std::to_string(num);
}

std::string no_space(std::string x)
{
	std::string s = "";
	for (int i = 0; i < x.length(); i++)
		if (x[i] != ' ')s += x[i];
	return s;
}

string reverseString(string str)
{
	string s = "";
	for (int i = str.length() - 1; i >= 0; i--)s += str[i];
	return s;
}

std::string even_or_odd(int number)
{
	return (number % 2 == 0) ? "Even" : "Odd";
}

int centuryFromYear(int year)
{
	return (year % 100 == 0) ? year / 100 : year / 100 + 1;
}

int basicOp(char op, int val1, int val2) {
	if (op == '+')return val1 + val2;
	else if (op == '-')return val1 - val2;
	else if (op == '*')return val1 * val2;
	else if (op == '/')return val2 != 0 ? val1 / val2 : 0;
}

int basicOp(char op, int val1, int val2) {
	if (op == '+')return val1 + val2;
	else if (op == '-')return val1 - val2;
	else if (op == '*')return val1 * val2;
	else if (op == '/')return val1 / val2;
}

int summation(int num) {
	int s = 0;
	for (int i = 1; i <= num; i++)s += i;
	return s;
}

int multiply(int a, int b)
{
	return a * b;
}

int main()
{
	return 0;
}
