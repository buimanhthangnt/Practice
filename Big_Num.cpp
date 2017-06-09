#include <iostream>
#include <vector>

using namespace std;

long sizeOfString(string s) {
	long i = 0;
	while (s[i]!='\0') i++;
	return i;
}
void pushStringToVector(string s, vector<int> &v) {
	long i = sizeOfString(s) - 1;
	while (i>=0) {
		v.push_back(s[i]-48);
		i--;
	}
}
void printReversedVector(vector<int> v) {
	for (int i=v.size()-1; i>=0; i--) {
		if (i==v.size()-1) {
			if (v[i]==0) continue;
		}
		cout << v[i];
	}
	cout << endl;
}

vector<int> add(vector<int> a, vector<int> b) {
	vector<int> result;
	long max = (a.size()>b.size())? a.size():b.size();
	int remember = 0, digit1, digit2;
	for (int i=0; i<max; i++) {
		if (i>=a.size()) digit1 = 0;
		else digit1 = a[i];
		if (i>=b.size()) digit2 = 0;
		else digit2 = b[i];
		result.push_back((digit1 + digit2 + remember) % 10);
		if (digit1+digit2+remember>9) remember = 1;
		else remember = 0;
	}
	if (remember==1) result.push_back(1);
	return result;
}

vector<int> subtract(vector<int> a, vector<int> b) {
	vector<int> result;
	int remember = 0, digit1, digit2;
	bool swapped = false;
	if (a.size()<b.size() || (a.size()==b.size() && b.back()>a.back())) {
		vector<int> tmp = a; a = b; b = tmp; swapped = true;
	}
	long max = (a.size()>b.size())? a.size():b.size();
	for (int i=0; i<max; i++) {
		if (i>=a.size()) digit1 = 0;
		else digit1 = a[i];
		if (i>=b.size()) digit2 = 0;
		else digit2 = b[i];
		int temp = digit1 - digit2 - remember;
		if (digit1 - digit2 - remember < 0) {
			remember = 1; temp += 10;
		}
		else remember = 0;
		result.push_back(temp);
	}
	if (swapped==true) {
		int temp = result.back() * -1;
		result.pop_back();
		result.push_back(temp);
	}
	return result;
}

vector<int> singleMultiply(vector<int> v, int a, long numberOfZeroFollow) {
	vector<int> result;
	for (int i=1; i<=numberOfZeroFollow; i++) {
		result.push_back(0);
	}
	int remember = 0;
	for (int i=0; i<v.size(); i++) {
		result.push_back((v[i]*a + remember) % 10);
		remember = (v[i]*a + remember) / 10;
	}
	if (remember!=0) result.push_back(remember);
	return result;
}

vector<int> multiply(vector<int> a, vector<int> b) {
	vector<int> temp, result = singleMultiply(a,b[0],0);
	for (int i=1; i<b.size(); i++) {
		temp = singleMultiply(a,b[i],i);
		result = add(result,temp);
	}
	return result;
}

int main()
{
	vector<int> a, b;
    string number1, number2;
    cin >> number1 >> number2;
    pushStringToVector(number1,a);
	pushStringToVector(number2,b);
	cout << "Tong la: ";
   	printReversedVector(add(a,b));
   	cout << "Hieu la: ";
   	printReversedVector(subtract(a,b));
   	cout << "Tich la: ";
   	printReversedVector(multiply(a,b));
}
